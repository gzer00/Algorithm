import java.util.*;
import java.io.*;

public class BOJ_15652 {
	
	static int[] perm;
	static boolean[]visited;
	static int N;
	static int M;
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		perm = new int[M];
		visited = new boolean[N+1];
		
		permutation(0, 1);
		
		bw.flush();
		bw.close();
		br.close();
		
	}
	
	static void permutation(int depth, int start) throws IOException {

		if (depth == M) {
			
			for (int i = 0; i < M; i++) {
				
				bw.write(perm[i] + " ");
				
			}
			
			bw.newLine();
			
			return;
		}
		
		for (int i = start; i <= N; i++) {
				
				perm[depth] = i;
				
				permutation(depth+1, i);
				
		}
	}
		
}
