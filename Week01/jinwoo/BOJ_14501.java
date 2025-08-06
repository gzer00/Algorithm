// 14501 - 퇴사 (실버3)

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        int[] T = new int[N];
        int[] P = new int[N];
        int[] dp = new int[N + 1]; // dp[i] = i일째부터 얻을 수 있는 최대 수익

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            T[i] = Integer.parseInt(st.nextToken()); // 상담 기간
            P[i] = Integer.parseInt(st.nextToken()); // 상담 수익
        }

        // 역순으로 계산
        for (int i = N - 1; i >= 0; i--) {
            int time = T[i] + i;
          
            if (time <= N) {
                // i번째 상담을 하는 경우와 안 하는 경우 중 최대
                dp[i] = Math.max(P[i] + dp[time], dp[i + 1]);
            } else {
                // 상담할 수 없는 경우는 다음날 dp 그대로
                dp[i] = dp[i + 1];
            }
          
        }

        System.out.println(dp[0]);
    }
}
