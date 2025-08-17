import java.util.Scanner;
import java.util.Stack;

class BOJ_2468 {
    static int n;
    static int[][] area;
    static boolean[][] visited;
    
    public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
    	
    	int answer = 0;
        int maxHeight = Integer.MIN_VALUE;
        
        n = sc.nextInt();
        area = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                area[i][j] = sc.nextInt();
                
                // 최대높이 구함
                if (maxHeight < area[i][j]) maxHeight = area[i][j];
            }
        }
        
        for (int h = 0; h <= maxHeight; h++) {
        	visited = new boolean[n][n];
        	int result = 0;
        	
        	for (int i = 0; i < n; i++) {
        		for (int j = 0; j < n; j++) {
        			result += search(i, j, h);
        		}
        	}
        	
        	if (answer < result) answer = result;
        }
        
        System.out.println(answer);
    }
    
    static int search(int i, int j, int h) {        
    	if (visited[i][j] || area[i][j] <= h) return 0;
        
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        
        Stack<int[]> s = new Stack<>();
        s.push(new int[]{i, j});
        
        while (!s.empty()) {
            int[] current = s.pop();
            int x = current[0];
            int y = current[1];
            
             visited[x][y] = true;
            
            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if (isValid(nx,ny) && !visited[nx][ny] && area[nx][ny] > h) {
                    s.push(new int[]{nx, ny});
                }
            }
        }
        
        return 1;
    }
    
    static boolean isValid(int i, int j) {
        return 0 <= i && i < n && 0 <= j && j < n;
    }
}