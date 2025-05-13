import java.util.*;
import java.io.*;

public class Main {
    static List<List<Integer>> edges = new ArrayList<>();
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int bfs(int sn, boolean[][] relation) /*throws IOException*/ {
        Queue<Integer> q = new ArrayDeque<>();
        int cnt = 0;
        for (Integer i : edges.get(sn)) {
            q.add(i);
            relation[sn][i] = true;
            cnt++;

//            bw.write("현재 노드 : " + sn + "와 노드 " + i + "연결\n");
        }
        relation[sn][sn] = true;

        while (!q.isEmpty()) {
            int cn = q.poll();
            for (int nn : edges.get(cn)) {
                if (relation[sn][nn]) continue;
                relation[sn][nn] = true;
                cnt++;
//                bw.write("현재 노드 : " + sn + "와 노드 " + nn + "연결\n");
            }
        }
        return cnt;
    }

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; ++i) {
            edges.add(new ArrayList<>());
            st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            for (int j = 0; j < N; ++j) {
                if (a.charAt(j) == 'Y') {
                    edges.get(i).add(j);
                }
            }
        }

        boolean[][] relation = new boolean[N][N];
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans = Math.max(ans, bfs(i, relation));
        }

        bw.write(ans + "\n");
        br.close();
        bw.close();
    }
}