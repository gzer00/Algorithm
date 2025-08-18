import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int[] arr;
    static int[] comb;
    static int N;
    static int S;
    static int cnt;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());

        arr = new int[N];

        comb = new int[N];

        S = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        cnt = 0;

        combination(0, 0);

        bw.write(String.valueOf(cnt));

        bw.flush();
        bw.close();
        br.close();

    }

    static void combination(int depth, int start) throws IOException {

        if (depth > 0) {

            int sum = 0;

            for (int i = 0; i < depth; i++) {
                
                sum = sum + comb[i];
            }
            
            if (sum == S) cnt++;
        }

        for (int i = start; i < N; i++) {

            comb[depth] = arr[i];

            combination(depth+1, i+1);

        }

     }

}
