import java.util.Scanner;

class BOJ_1182 {
    static int N, S, answer;
    static int[] nums, combinedNums;
    
    public static void main(String args[]) {
    	Scanner sc = new Scanner(System.in);
    	
        answer = 0;
        
        N = sc.nextInt();
        S = sc.nextInt();
        
        nums = new int[N];
        
        for (int i = 0; i < N; i++) nums[i] = sc.nextInt();
        
        for (int r = 1; r <= N; r++) {
            combinedNums = new int[r];
            combine(N, r);
        }
        
        System.out.println(answer);
    }
    
    static void combine(int n, int r) {
        if (r == 0) {
            calculate();
            return;
        }
        else if (n < r) return;
        
        combinedNums[r-1] = nums[n-1];
        combine(n-1, r-1);
        combine(n-1, r);
    }
    
    static void calculate() {
        int result = 0;
        
        for (int n: combinedNums) result += n;
        
        if (result == S) answer++;
    }
}