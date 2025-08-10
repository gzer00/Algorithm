import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

class Main {	
	
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
		
		perm(n, m);
		
		Collections.sort(result);
		
		for (int i = 0; i < result.size(); i++) {
			String modified = result.get(i).replace("[", "")
											.replace("]", "")
											.replace(",", "");
			System.out.println(modified);
		}
	}
	
	static void perm(int n, int r) {
		if (r == 0) {
			result.add(Arrays.toString(t));
		} else {
			for (int i = n - 1; i >= 0; i--) {
				swap(i, n-1);
				t[r-1] = arr[n-1];
				perm(n-1, r-1);
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