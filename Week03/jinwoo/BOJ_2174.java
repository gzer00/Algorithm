import java.io.*;
import java.util.StringTokenizer;

public class BOJ_2174 {

    static int A;
    static int B;
    static int N;
    static int M;
    static int[] dx = {0, 1, 0, -1}; // N E S W
    static int[] dy = {1, 0, -1, 0};

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[][] robots = new int[N+1][3];

        boolean breakOn = false;

        for (int i = 1; i <= N; i++) {

            st = new StringTokenizer(br.readLine());

            robots[i][0] = Integer.parseInt(st.nextToken());
            robots[i][1] = Integer.parseInt(st.nextToken());

            String dir = st.nextToken();

            int dirInt = 0;

            if (dir.equals("N")) dirInt = 0;
            else if (dir.equals("E")) dirInt = 1;
            else if (dir.equals("S")) dirInt = 2;
            else if (dir.equals("W")) dirInt = 3;

            robots[i][2] = dirInt;
            
        }

            for (int i = 0; i < M; i++) {

                if (breakOn) break;

                st = new StringTokenizer(br.readLine());

                int robotNum = Integer.parseInt(st.nextToken());

                String cmd = st.nextToken();

                int num = Integer.parseInt(st.nextToken());

                int robotDir = robots[robotNum][2];

                if (cmd.equals("F")) {

                // 좌표 이동
                	
                	for (int j = 1; j <= num; j++) {
                		
                		robots[robotNum][0] = robots[robotNum][0] + dx[robotDir];
                		robots[robotNum][1] = robots[robotNum][1] + dy[robotDir];
                		
                        // 벽에 부딪히는 경우

                        if (robots[robotNum][0] < 1 || robots[robotNum][0] > A ||
                                robots[robotNum][1] < 1 || robots[robotNum][1] > B) {
                            bw.write("Robot " + robotNum + " crashes into the wall\n");
                            breakOn = true;
                            break;
                        }

                        // 다른 로봇과 부딪히는 경우

                        for (int k = 1; k <= N; k++) {

                            if (k != robotNum && robots[robotNum][0] == robots[k][0] &&
                                    robots[robotNum][1] == robots[k][1]) {
                                bw.write("Robot " + robotNum + " crashes into robot " + k + "\n");
                                breakOn = true;
                                break;
                            }
                            
                        }
                        
                        if (breakOn) break;
                		
                	}
                	
                	if (breakOn) break;

                } 
                
                // 방향 전환 공식 사용
                
                else if (cmd.equals("L")) {

                   robotDir = (robotDir + 3 * num) % 4;
                   robots[robotNum][2] = robotDir;

                } else if (cmd.equals("R")) {

                    robotDir = (robotDir + 1 * num) % 4;
                    robots[robotNum][2] = robotDir;

                }

            }

        if (!breakOn) {
            bw.write("OK");
        }

        bw.flush();
        bw.close();
        br.close();

    }
}
