import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, S, ans;
    static int[] nums = new int[20];

    static void bt(int level, int sum, int cnt) /*throws IOException*/ {
        if (level == N) {
            if (sum == S && cnt > 0) ans++;
            return;
        }

//        if (cnt > 0) {
//            bw.write(level + " " + sum + "\n");
//            bw.flush();
//        }

        bt(level + 1, sum + nums[level], cnt + 1);
        bt(level + 1, sum, cnt);
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; ++i) {
            nums[i] = Integer.parseInt(st.nextToken());
        }

        bt(0, 0, 0);
        bw.write(ans + "\n");

        br.close();
        bw.close();
    }
}