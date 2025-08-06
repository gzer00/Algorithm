// 14888 - 연산자 끼워넣기 (실버1)

import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int[] numbers;
    static int[] operators = new int[4]; // + - * /
    static int max = Integer.MIN_VALUE;
    static int min = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        numbers = new int[N];
        
        // 숫자 입력
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            numbers[i] = Integer.parseInt(st.nextToken());
        }

        // 연산자 개수 입력
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 4; i++) {
            operators[i] = Integer.parseInt(st.nextToken());
        }

        dfs(1, numbers[0]);

        System.out.println(max);
        System.out.println(min);
    }

    // depth: 현재 몇 번째 숫자를 사용하고 있는지
    // total: 이전까지의 계산 결과
    public static void dfs(int depth, int total) {
        if (depth == N) {
            max = Math.max(max, total);
            min = Math.min(min, total);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (operators[i] > 0) {
                operators[i]--; // 연산자 사용

                switch (i) {
                    case 0: // +
                        dfs(depth + 1, total + numbers[depth]);
                        break;
                    case 1: // -
                        dfs(depth + 1, total - numbers[depth]);
                        break;
                    case 2: // *
                        dfs(depth + 1, total * numbers[depth]);
                        break;
                    case 3: // /
                        dfs(depth + 1, total / numbers[depth]);
                        break;
                }

                operators[i]++; // 백트래킹 (원상복구)
            }
        }
    }
}
