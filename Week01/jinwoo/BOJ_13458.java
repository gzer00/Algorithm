// 13458 - 시험 감독 (브론즈2)

import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;

    public static void main(String[] args) throws Exception {

        int N = Integer.parseInt(br.readLine());

        st = new StringTokenizer(br.readLine());

        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {

            arr[i] = Integer.parseInt(st.nextToken());

        }

        st = new StringTokenizer(br.readLine());

        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        long answer = 0;

        for (int i = 0; i < N; i++){

            int other = arr[i] - B;
            answer++;

            if (other <= 0) {
                continue;
            }

            int cnt = other / C;

            if (other % C > 0) {
                cnt++;
            }

            answer = answer + cnt;
        }

        bw.write(String.valueOf(answer));

        bw.flush();
        bw.close();
        br.close();
    }
}
