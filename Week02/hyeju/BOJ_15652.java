/*
 * N과 M (4)
 * 1. (a, b) (b, a) 구조가 아니라서 조합 알고리즘 사용
 * 2. (a, a) 구조라서 중복 가능한 경우
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class BOJ_15652 {	
	
	static int[] arr;
	static int[] t;
	
	static ArrayList<int[]> result = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String[] s = br.readLine().split(" ");
		int n = Integer.parseInt(s[0]);
		int m = Integer.parseInt(s[1]);
		
		arr = new int[n];
		t = new int[m];
		
		for (int i = 0; i < n; i++) {
			arr[i] = i + 1;
		}
		
		combine(n, m);
		
		Collections.sort(result, new Comparator<int[]>() {

			@Override
			public int compare(int[] o1, int[] o2) {
				for (int i = 0; i < Math.min(o1.length, o2.length); i++) {
					if (o1[i] != o2[i]) {
						return o1[i] - o2[i];
					}
				}
				return o1.length - o2.length;
			}
			
		});
		
		StringBuilder sb = new StringBuilder();
		
		for (int i = 0; i < result.size(); i++) {
			int[] current = result.get(i);
			
			for (int j = 0; j < current.length; j++) {
				sb.append(current[j] + " ");
			}
			sb.append("\n");
		}
		
		System.out.println(sb.toString());
	}
	
	static void combine(int n, int r) {
		if (r == 0) {
			result.add(Arrays.copyOf(t, t.length));
			return;
		} else if (n == 0) return;
		
		t[r-1] = arr[n-1];
		combine(n, r-1);
		combine(n-1, r);
	}
}