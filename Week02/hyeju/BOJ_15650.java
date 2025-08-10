/*
 * N과 M (2)
 * 중복을 허용하지 않은 조합 알고리즘 사용
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class BOJ_15650  {	
	
	static int[] arr;
	static int[] t;
	
	static ArrayList<String> result = new ArrayList<>();
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		arr = new int[n];
		t = new int[m];
		
		for (int i = 0; i < n; i++) {
			arr[i] = i+1;
		}
		
		combine(n, m);
		
		Collections.sort(result);
		
		for (int i = 0; i < result.size(); i++) {
			String modified = result.get(i).replace("[", "")
											.replace("]", "")
											.replace(",", "");
			System.out.println(modified);
		}
	}
	
	static void combine(int n, int r) {
		if (r == 0) {
			result.add(Arrays.toString(t));
		}
		else if (n < r) return;
		
		else {
			t[r-1] = arr[n-1];
			combine(n-1, r-1);
			combine(n-1, r);
		}
	}
	
	static void swap(int idx1, int idx2) {
		int temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}
}