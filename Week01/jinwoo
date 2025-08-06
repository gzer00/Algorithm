// 14889 - 스타트와 링크 (실버1)

import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[][] S;
    static boolean[] visited;
    static int minDiff = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        S = new int[N][N];
        visited = new boolean[N];

        // 능력치 입력
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                S[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0, 0);
        System.out.println(minDiff);
    }

    // depth: 현재 선택된 인원 수
    // idx: 다음으로 탐색할 시작 인덱스 (중복 방지)
    public static void dfs(int depth, int idx) {
        if (depth == N / 2) {
            calculateDifference();
            return;
        }

        for (int i = idx; i < N; i++) {
            if (!visited[i]) {
                visited[i] = true;
                dfs(depth + 1, i + 1);
                visited[i] = false; // 백트래킹
            }
        }
    }

    // 두 팀의 능력치 합을 계산
    public static void calculateDifference() {
        int startSum = 0;
        int linkSum = 0;

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (visited[i] && visited[j]) {
                    startSum += S[i][j] + S[j][i];
                } else if (!visited[i] && !visited[j]) {
                    linkSum += S[i][j] + S[j][i];
                }
            }
        }

        int diff = Math.abs(startSum - linkSum);
        minDiff = Math.min(minDiff, diff);

        // 최솟값이 0이면 더 이상 탐색할 필요 없음
        if (minDiff == 0) {
            System.out.println(0);
            System.exit(0);
        }
    }
}
