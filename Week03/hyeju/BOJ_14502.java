/*
 * 조합과 DFS 사
 */

import java.util.Scanner;
import java.util.Stack;

class BOJ_14502 {

    static int N, M;
    static int maxSafeArea = 0;
    static int[][] map, tempMap;
    static int[][] emptySpaces = new int[62][2]; // 최대 빈 칸 수
    static int[][] walls = new int[3][2]; 		// 벽 3개를 세울 위치
    static int emptyCount = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][M];

        int idx = 0;
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                map[r][c] = sc.nextInt();
                if (map[r][c] == 0) {
                    emptySpaces[idx++] = new int[] { r, c };
                    emptyCount++;
                }
            }
        }

        placeWalls(0, 0);
        System.out.println(maxSafeArea);
    }

	// depth : 지금까지 선택한 개수 / startIdx : 다음에 고를 수 있는 인덱스의 최소값
	// i : depth 번째 자리에 넣을 인덱스 값
    
    static void placeWalls(int depth, int startIdx) {
        if (depth == 3) {
            tempMap = copyMap(map);
            for (int[] wall : walls) {
                tempMap[wall[0]][wall[1]] = 1;
            }

            boolean[][] visited = new boolean[N][M];

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (tempMap[i][j] == 2 && !visited[i][j]) {
                        spreadVirus(i, j, visited);
                    }
                }
            }

            maxSafeArea = Math.max(maxSafeArea, countSafeArea());
            return;
        }

        for (int i = startIdx; i <= emptyCount - 3 + depth; i++) {
            walls[depth] = emptySpaces[i];
            placeWalls(depth + 1, i + 1);
        }
    }

    static void spreadVirus(int x, int y, boolean[][] visited) {
        int[] dx = { -1, 1, 0, 0 };
        int[] dy = { 0, 0, -1, 1 };
        Stack<int[]> stack = new Stack<>();
        stack.push(new int[] { x, y });

        while (!stack.isEmpty()) {
            int[] pos = stack.pop();
            int cx = pos[0], cy = pos[1];
            visited[cx][cy] = true;

            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if (isInBounds(nx, ny) && tempMap[nx][ny] == 0 && !visited[nx][ny]) {
                    tempMap[nx][ny] = 2;
                    stack.push(new int[] { nx, ny });
                }
            }
        }
    }

    static int countSafeArea() {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (tempMap[i][j] == 0) count++;
            }
        }
        return count;
    }

    static int[][] copyMap(int[][] original) {
        int[][] newMap = new int[N][M];
        for (int i = 0; i < N; i++) {
            System.arraycopy(original[i], 0, newMap[i], 0, M);
        }
        return newMap;
    }

    static boolean isInBounds(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < M;
    }
}
