import java.util.*;

public class H_grid1 {
    static long[][] dp;

    static int mod = (int)(1e9+7); 

    static boolean isValid(int i, int j, char[][] arr){
        return i >= 0 && j >= 0 && i < arr.length && j < arr[0].length && arr[i][j] != '#';
    }

    static long solve(char[][] arr, int i,int j) {
        if(!isValid(i, j, arr)) return 0;  

        if(i == arr.length - 1 && j == arr[0].length - 1) {
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        long d=0, ri=0;

        d = solve(arr, i+1, j);
        ri = solve(arr, i, j+1);
        
        dp[i][j] = (d+ri)%mod;
        return dp[i][j];
    }

    //985525448
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int r = sc.nextInt();
        int c = sc.nextInt();

        char[][] arr = new char[r][c];

        for(int i=0; i<r; i++) {
            arr[i] = sc.next().toCharArray();
        }

        dp = new long[r+1][c+1];
        for(long[] x : dp) {
            Arrays.fill(x, -1);
        }

        // input khatam

        long ans = solve(arr, 0, 0);
        System.out.print(ans);

        sc.close();
        return;
    }
}