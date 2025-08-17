/*
 * 배열 인덱스 연산
 * 
 * A = 열 = x축 = [    ][here]
 * B = 행 = y축 = [here][    ]
 */

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

class BOJ_2174 {
	static int A, B, N, M;
	static Map<Integer,Integer>[][] area;	
	static int[] dx = {-1, 0, 1, 0};	// N, E, S, W (상우좌하)
	static int[] dy = {0, 1, 0, -1};
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		A = sc.nextInt();
		B = sc.nextInt();
		N = sc.nextInt();
		M = sc.nextInt();
		
		area = new Map[B][A];		
		for (int r = 0; r < B; r++) {
		    for (int c = 0; c < A; c++) {
		        area[r][c] = new HashMap<>();
		    }
		}
		
		for (int robotId = 1; robotId <= N; robotId++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			char dir = sc.next().charAt(0);
			
			int row = B - y;
			int col = x - 1;
			
			area[row][col].put(robotId, dirToInt(dir));
		}
		
		for (int i = 0; i < M; i++) {
			int robotId = sc.nextInt();
			char command = sc.next().charAt(0);
			int repeat = sc.nextInt();
			
			if (!executeCommand(robotId, command, repeat)) {
				return;
			}
		}
		
		System.out.println("OK");
	}
	
	static boolean executeCommand(int robotId, char command, int repeat) {
        int[] pos = findRobot(robotId);
        int row = pos[0];
        int col = pos[1];
        int dir = area[row][col].get(robotId);

        for (int i = 0; i < repeat; i++) {
            if (command == 'L') {
                dir = (dir + 3) % 4;
                area[row][col].put(robotId, dir);
            } else if (command == 'R') {
                dir = (dir + 1) % 4;
                area[row][col].put(robotId, dir);
            } else { // Move forward
                int newRow = row + dx[dir];
                int newCol = col + dy[dir];

                if (!isValid(newRow, newCol)) {
                    System.out.println("Robot " + robotId + " crashes into the wall");
                    return false;
                }

                if (!area[newRow][newCol].isEmpty()) {
                    int other = area[newRow][newCol].keySet().iterator().next();
                    System.out.println("Robot " + robotId + " crashes into robot " + other);
                    return false;
                }

                area[row][col].clear();
                area[newRow][newCol].put(robotId, dir);
                row = newRow;
                col = newCol;
            }
        }

        return true;
    }
	
	static int dirToInt(char d) {
		switch (d) {
	        case 'N': return 0;
	        case 'E': return 1;
	        case 'S': return 2;
	        case 'W': return 3;
	    }
		return -1;	// default
	}
	
	static int[] findRobot(int key) {
		for (int i = 0; i < B; i++)
			for (int j = 0; j < A; j++)
				if (area[i][j].containsKey(key)) return new int[] {i,j};
		
		return null;
	}
	
	static boolean isValid(int i, int j) {
		return 0 <= i && i < B && 0 <= j && j < A;
	}
}