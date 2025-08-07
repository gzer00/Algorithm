// 시험 감

import java.util.Scanner;

public class BOJ_13458 {

	public static void main(String args[]) 
	{
		Scanner sc = new Scanner(System.in);
		
		long result = 0;		// 정답
		int n = sc.nextInt();
		
		int[] rooms = new int[n];
		for (int i = 0; i < n; i++)
			rooms[i] = sc.nextInt();
		
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		for (int i = 0; i < rooms.length; i++) {
			int students = rooms[i];
			
			// 총감독관 할당된 인원
			result += 1;
			students -= b;
			
			if (students > 0) {	// 학생수 0이 아니라면
			
				// 부감독관 할당된 인원
				result += (students / c);
				
				// 감독관 추가
				if (students % c > 0) result += 1;
			}
		}
		
		System.out.println(result);
	}
}