import java.io.*;
import java.util.*;

public class Main {

    static int[][] arr;
    static int zero = 0;
    static int one = 0;
    static int minus = 0;

    static void divsion(int row, int col, int N) {
        boolean issame = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[row][col] != arr[row + i][col + j]) {
                    issame = false;
                    break;
                }
            }
        }
        if (issame) {
            if (arr[row][col] == 0) zero++;
            else if (arr[row][col] == 1) one++;
            else minus++;
            return;
        }
        int d = N / 3;
        for (int h = 0; h < N; h += d) {
            for (int t = 0; t < N; t += d) {
                divsion(row + h, col + t, d);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        arr = new int[N][N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        divsion(0, 0, N);
        System.out.println(minus);
        System.out.println(zero);
        System.out.println(one);
    }
}