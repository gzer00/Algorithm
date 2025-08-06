// 퇴

import java.util.Scanner;
import java.lang.Math;

public class BOJ_14501 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc. nextInt();
        
        int[] t = new int[n+1];
        int[] p = new int[n+1];
        int[] cost = new int[n+2];
            
        for (int i = 1; i < n+1; i++) {
            t[i] = sc.nextInt();
            p[i] = sc.nextInt();
        } 
        
        for (int i = n; i > 0; i--) {
            int days = i + t[i];
            
            if (days <= n+1) {
                cost[i] = Math.max(p[i] + cost[i+t[i]], cost[i+1]);
            } else {
                cost[i] = cost[i+1];
            }
        }
        System.out.println(cost[1]);
    }
}