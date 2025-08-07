// 스타트와 링크

import java.util.Scanner;

class BOJ_14889 {
    
	static int[][] arr;
	static boolean selected[];
	
	static int n;
	static int min = Integer.MAX_VALUE;
	
    public static void main(String[] arg) {
    	Scanner sc = new Scanner(System.in);
    	
    	n = sc.nextInt();
    	
    	arr = new int[n][n];
    	selected = new boolean[n];
    	
    	// 배열 초기화
    	for (int i = 0; i < n; i++) {
    		for (int j = 0; j < n; j++) {
    			arr[i][j] = sc.nextInt();
    		}
    	}
    	
    	// 로직   	
    	combination(0, 0);
    	
    	System.out.println(min);
    }
    
    static void combination(int idx, int depth) {
    	if (depth == n/2) {
    		calculate();
    		return;
    	}

    	for (int i = idx; i < n; i++) {
    		selected[i] = true;
    		combination(i+1, depth+1);
    		selected[i] = false;
    	}
    }
    
    static void calculate() {
    	int startSum = 0;
    	int linkSum = 0;
    	
    	for (int i = 0; i < n; i++) {
    		for (int j = i+1; j < n; j++) {
    			if (selected[i] && selected[j]) {
    				startSum += arr[i][j] + arr[j][i];
    			} else if (!selected[i] && !selected[j]){
    				linkSum += arr[i][j] + arr[j][i];
    			}
    		}
    	}
    	
    	int diff = startSum - linkSum < 0 ? (startSum - linkSum) * -1 : startSum - linkSum;

    	min = min > diff ? diff : min;
    }
}