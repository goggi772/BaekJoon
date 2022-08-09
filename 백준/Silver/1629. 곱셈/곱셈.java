import java.io.*;
import java.util.*;

public class Main {

    static long mod;
    static long count;

    static void Multiplication(long a, long b, long c, long num) {
        if (b > num * 2) {
            Multiplication(a * a % c, b, c, num * 2);
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

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        Multiplication(A % C, B, C, 1);
        System.out.println(mod);

    }
}