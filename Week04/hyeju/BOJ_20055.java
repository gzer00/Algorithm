import java.util.*;

public class BOJ_20055 {
    static int N, K;
    static int[] belt; // 내구도
    static boolean[] robots; // 로봇 위치 여부
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();
        belt = new int[2 * N];
        robots = new boolean[N]; // 로봇은 올리는 위치부터 내리는 위치까지만 (0~N-1)
        for (int i = 0; i < 2 * N; i++) {
            belt[i] = sc.nextInt();
        }

        int step = 0;
        while (true) {
            step++;
            // 1. 벨트 회전
            rotateBelt();

            // 2. 로봇 이동
            moveRobots();

            // 3. 로봇 올리기
            if (belt[0] > 0 && !robots[0]) {
                robots[0] = true;
                belt[0]--;
            }

            // 4. 내구도 0 개수 확인
            int zeroCount = 0;
            for (int i = 0; i < 2 * N; i++) {
                if (belt[i] == 0) zeroCount++;
            }
            if (zeroCount >= K) break;
        }
        System.out.println(step);
    }

    static void rotateBelt() {
        // 벨트 회전
        int lastDurability = belt[2 * N - 1];
        for (int i = 2 * N - 1; i > 0; i--) {
            belt[i] = belt[i - 1];
        }
        belt[0] = lastDurability;

        // 로봇도 함께 이동
        for (int i = N - 1; i > 0; i--) {
            robots[i] = robots[i - 1];
        }
        robots[0] = false;

        // 내리는 위치에 도달한 로봇은 내림
        if (robots[N - 1]) robots[N - 1] = false;
    }

    static void moveRobots() {
        // 뒤에서부터 이동시도
        for (int i = N - 2; i >= 0; i--) {
            if (robots[i] && !robots[i + 1] && belt[i + 1] > 0) {
                robots[i] = false;
                robots[i + 1] = true;
                belt[i + 1]--;
            }
        }
        // 내리는 위치에 도달한 로봇 내림
        if (robots[N - 1]) robots[N - 1] = false;
    }
}
