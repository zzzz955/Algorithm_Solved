import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] dic = new int[100];
    static int[] cnt = new int[100];
    static int S, P;

    static boolean isDNA() {
        int DNAs = cnt['A'] + cnt['C'] + cnt['G'] + cnt['T'];
        return P - DNAs == 0;
    }

    static boolean isMatch() {
        if (cnt['A'] < dic['A']) return false;
        if (cnt['C'] < dic['C']) return false;
        if (cnt['G'] < dic['G']) return false;
        if (cnt['T'] < dic['T']) return false;
        return true;
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        String str = br.readLine();
        st = new StringTokenizer(br.readLine());
        dic['A'] = Integer.parseInt(st.nextToken());
        dic['C'] = Integer.parseInt(st.nextToken());
        dic['G'] = Integer.parseInt(st.nextToken());
        dic['T'] = Integer.parseInt(st.nextToken());

        for (int i = 0; i < P; ++i) {
            char ch = str.charAt(i);
            cnt[ch]++;
        }

        int ans = 0;
        if (isDNA() && isMatch()) ans++;

        for (int i = P; i < S; ++i) {
            char left = str.charAt(i - P);
            char right = str.charAt(i);
            cnt[left]--;
            cnt[right]++;
            if (isDNA() && isMatch()) ans++;
        }

        bw.write(ans + "\n");
        br.close();
        bw.close();
    }
}