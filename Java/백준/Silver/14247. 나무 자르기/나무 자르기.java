import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static class IV {
        int idx, val;
        IV (int idx, int val) {
            this.idx = idx;
            this.val = val;
        }
    }
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        long[] H = new long[N];
        IV[] P = new IV[N];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            long val = Long.parseLong(st.nextToken());
            H[i] = val;
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            int val = Integer.parseInt(st.nextToken());
            P[i] = new IV(i, val);
        }

        Arrays.sort(P, (a, b) -> a.val - b.val);
//        for (IV iv : P) {
//            bw.write(iv.val + " ");
//        }
//        bw.flush();
        long ans = 0;
        for (int i = 0; i < N; ++i) {
            int idx = P[i].idx;
            ans += H[idx] + P[i].val * i;
        }
        bw.write(ans + "\n");

        br.close();
        bw.close();
    }
}