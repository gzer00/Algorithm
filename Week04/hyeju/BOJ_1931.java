import java.util.Arrays;
import java.util.Scanner;

class BOJ_1931 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		int[][] arr = new int[N][N];
		
		for (int i = 0; i < N; i++) {
			arr[i][0] = sc.nextInt();
			arr[i][1] = sc.nextInt();
		}
		
		Arrays.sort(arr, (e1, e2) -> {
			if (e1[1] == e2[1]) {
				return e1[0] - e2[0];
			} else {
				return e1[1] - e2[1];
			}
		});
		
		// 메인로직
		int e = arr[0][1];
		
		int answer = 1;
		
		for (int i = 1; i < N; i++) {
			if (e <= arr[i][0]) {
				answer++;
				e = arr[i][1];
			}
		}
		
		System.out.println(answer);
	}
}
