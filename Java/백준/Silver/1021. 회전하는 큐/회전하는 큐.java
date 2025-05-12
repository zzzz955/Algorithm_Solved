import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        Deque<Integer> deque = new ArrayDeque<>();

        for (int i = 1; i <= N; ++i) {
            deque.addLast(i);
        }

        st = new StringTokenizer(br.readLine());
        int ans = 0;
        while (M-- > 0) {
            int a = Integer.parseInt(st.nextToken());
            int size = deque.size();
            int cnt = 0;
            while (deque.getFirst() != a) {
                cnt++;
                int front = deque.pollFirst();
                deque.addLast(front);
            }
            deque.pollFirst();
            ans += Math.min(cnt, size - cnt);
        }
        bw.write(ans + "\n");
        br.close();
        bw.close();
    }
}