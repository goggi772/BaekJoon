import java.io.*;

public class Main {
    static long[][] A = {{1, 1}, {1, 0}};
    static long[][] fibonacci(long N) {
        if (N == 1) return A;
        long[][] m = fibonacci(N / 2);
        long[][] res = cal(m, m);
        if (N % 2 == 0) {
            return res;
        } else {
            return cal(res, A);
        }
    }

    static long[][] cal(long[][] a, long[][] b) {
        long[][] result = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                int sum = 0;
                for (int k = 0; k < 2; k++) {
                    sum += (a[i][k] * b[k][j]) % 1000000007;
                }
                result[i][j] = sum % 1000000007;
            }
        }
        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        long N = Long.parseLong(br.readLine());

        long[][] result = fibonacci(N);

        System.out.println(result[0][1]);

    }
}
