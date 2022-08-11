import java.io.*;
import java.util.*;

public class Main {
    static int[][] matrix(int[][] arr, long B) {
        int len = arr.length;
        if (B == 1) {
            for (int t = 0; t < len; t++) {
                for (int r = 0; r < len; r++) {
                    arr[t][r] %= 1000;
                }
            }
            return arr;
        }
        int[][] m = matrix(arr, B / 2);
        int[][] result1 = new int[len][len];

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                int sum = 0;
                for (int k = 0; k < len; k++) {
                    sum += (m[i][k] * m[k][j]) % 1000;
                }
                result1[i][j] = sum % 1000;
            }
        }
        if (B % 2 == 0) {
            return result1;
        } else {
            int[][] result2 = new int[len][len];
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    int sum = 0;
                    for (int k = 0; k < len; k++) {
                        sum += (result1[i][k] * arr[k][j]) % 1000;
                    }
                    result2[i][j] = sum % 1000;
                }
            }
            return result2;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        long B = Long.parseLong(st.nextToken());
        int[][] A = new int[N][N];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) A[i][j] = Integer.parseInt(st.nextToken());
        }
        int[][] result = matrix(A, B);

        for (int t = 0; t < N; t++) {
            for (int p = 0; p < N; p++) bw.write(result[t][p] + " ");
            bw.write("\n");
        }
        bw.flush();
        bw.close();

    }
}
