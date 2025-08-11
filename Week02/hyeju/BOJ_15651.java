
/*
 * N과 M (3)
 * 중복을 허용한 순열 알고리즘 사용
 * 시간초과 발생 -> 생성한 순열을 정수형 배열에 저장
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class BOJ_15651 {	
	
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
			arr[i] = n - i;
		}
		
		perm(n, m);
		
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
	
	static void perm(int n, int r) {
		if (r == 0) {
			result.add(Arrays.copyOf(t, t.length));
		} else {
			for (int i = n-1; i >= 0; i--) {
				swap(i, n-1);
				t[r-1] = arr[n-1];
				perm(n, r-1);
				swap(i, n-1);
			}
		}
	}
	
	static void swap(int idx1, int idx2) {
		int temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}
}