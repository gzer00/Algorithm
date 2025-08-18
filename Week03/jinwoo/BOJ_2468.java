import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] space;
    static int maxCnt;
    static int N;
    static boolean[][] visited;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));


    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());

        space = new int[N][N];

        int max = Integer.MIN_VALUE;

        for (int i = 0; i < N; i++) {

            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < N; j++) {

                space[i][j] = Integer.parseInt(st.nextToken());

                if (max < space[i][j]) {
                    max = space[i][j];
                }

            }

        }

        maxCnt = 0;

        for (int i = 0; i <= max; i++) {

            int cnt = 0;
            visited = new boolean[N][N];

            for (int j = 0; j < N; j++) {

                for (int k = 0; k < N; k++) {

                    if (!visited[j][k] && space[j][k] > i) {

                        dfs(j, k, i);

                        cnt++;

                    }

                }
            }

            if (maxCnt < cnt) {
                maxCnt = cnt;
            }

        }

        bw.write(String.valueOf(maxCnt));

        bw.flush();
        bw.close();
        br.close();

    }

    static void dfs(int x, int y, int height) throws IOException {

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {

            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX < 0 || newX >= N || newY < 0 || newY >= N) continue;

            if (!visited[newX][newY] && space[newX][newY] > height) {

                dfs(newX, newY, height);
            }

        }
    }
}
