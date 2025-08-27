import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int answer = 0;
		int N = sc.nextInt();
		PriorityQueue<Integer> que = new PriorityQueue<>();
		
		for (int i = 0; i < N; i++) {
			que.add(sc.nextInt());
		}
		
		while(que.size() > 1) {
			int num1 = que.poll();
			int num2 = que.poll();
			
			que.add(num1 + num2);
			answer += (num1 + num2);
		}
		
		System.out.println(answer);
	}
}