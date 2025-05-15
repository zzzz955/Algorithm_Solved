import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, M;
    static List<List<Relation>> edges = new ArrayList<>();
    static class Relation {
        int v, r;
        Relation(int v, int r) {
            this.v = v;
            this.r = r;
        }
    }
    static class Status {
        int cn, cs;
        Status(int cn, int cs) {
            this.cn = cn;
            this.cs = cs;
        }
    }
    static boolean bfs(int sn) {
        Deque<Status> deq = new ArrayDeque<>();
        int cnt = 1;
        boolean[] v = new boolean[N + 1];
        Arrays.fill(v, false);
        v[sn] = true;
        for (Relation relation : edges.get(sn)) {
            deq.add(new Status(relation.v, relation.r));
            cnt++;
            v[relation.v] = true;
        }
        
        while (!deq.isEmpty()) {
            Status status = deq.poll();
            int cn = status.cn, cs = status.cs;
            
            for (Relation relation : edges.get(cn)) {
                int nn = relation.v, nr = relation.r;
                if (v[nn]) continue;
                if (cs != nr) continue;
                v[nn] = true;
                cnt++;
                deq.add(new Status(nn, nr));
            }
        }
        return cnt == N ? true : false;
    }
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        
        for (int i = 0; i <= N; ++i) {
            edges.add(new ArrayList<>());
        }
        
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            edges.get(A).add(new Relation(B, 1));
            edges.get(B).add(new Relation(A, -1));
        }
        
        int ans = 0;
        for (int i = 1; i <= N; ++i) {
            if (bfs(i)) ans++;
        }
        bw.write(ans + "\n");
        br.close();
        bw.close();
    }
}