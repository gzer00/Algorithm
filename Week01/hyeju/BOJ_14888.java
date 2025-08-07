// 연산자 끼워넣

import java.util.Arrays;
import java.util.Scanner;

public class BOJ_14888 {

	static int max = Integer.MIN_VALUE;
	static int min = Integer.MAX_VALUE;
	
	static int[] arr;
	static char[] operator;
	static char[] output;
	static boolean[] visited;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		// 배열 입력
		int n = sc.nextInt();
		
		arr = new int[n];	// 원본배열
		visited = new boolean[n];	// 방문배열
		
		operator = new char[n-1];
		output = new char[n-1];	// 순열
		
		int idx = 0;
		
		for (int i = 0; i < n; i++)
			arr[i] = sc.nextInt();
		
		// + 연산
		int temp = sc.nextInt();
		
		for (int i = 0; i < temp; i++)
			operator[idx++] = '+';
		
		// - 연산
		temp = sc.nextInt();
		for (int i = 0; i < temp; i++)
			operator[idx++] = '-';
		
		// * 연산
		temp = sc.nextInt();
		for (int i = 0; i < temp; i++)
			operator[idx++] = '×';

		// - 연산
		temp = sc.nextInt();
		for (int i = 0; i < temp; i++)
			operator[idx++] = '÷';
		
		permutation(0, n-1);
		
		System.out.println(max);
		System.out.println(min);
	}
	
	// 3개를 고르는 순열
	// depth : 지금까지 찾은 숫자
	// r : 순열 개수
	public static void permutation(int depth, int r) {
		
		// 순열 완성했을때
		if (depth == r) {
			for (int i = 0; i < r; i++) {
				cal();
			}
		}
		
		for (int i = 0; i < operator.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				output[depth] = operator[i];
				permutation(depth+1, r);
				visited[i] = false;
			}
		}
	}
	
	public static void cal() {
		int idx = 0;
		int temp = arr[0];
		
		for (int i = 1; i < arr.length; i++) {
			int a = arr[i];
			
			if (output[idx] == '+') temp += a;
			else if (output[idx] == '-') temp -= a;
			else if (output[idx] == '×') temp *= a;
			else temp /= a;
			
			idx++;
		}
		
		max = Math.max(max, temp);
		min = Math.min(min, temp);
	}

}