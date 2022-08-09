import java.io.*;
import java.util.*;

public class Main {
    static long rem = 1000000007;
    static long mod;
    static long count;

    static void combination(long a, long b, long c, long num) {
        if (b > num * 2) {
            combination(a * a % c, b, c, num * 2);
        } else {
            count = num;
            mod = a;
        }
        if (b - count >= num) {
            mod = a * mod % c;
            count += num;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        long[] fac = new long[4000001];
        fac[0] = 1;
        for (int i = 1; i < 4000001; i++) {
            fac[i] = (fac[i - 1] % rem * i) % rem;
        }

        combination(fac[K] * fac[N - K] % rem, rem - 2, rem, 1);
        System.out.println(fac[N] * mod % rem);

    }
}