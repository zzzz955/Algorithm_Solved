import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, M, A, B, C, ans;
    static class Edge {
        int nn, nv;
        Edge(int nn, int nv) {
            this.nn = nn;
            this.nv = nv;
        }
    }
    static List<List<Edge>> edges = new ArrayList<>();
    static boolean[] v = new boolean[11];
    
    static void dfs(int cn, int spent, int mv) {
        if (cn == B) {
            if (ans == -1 || ans > mv) ans = mv;
            return;
        }
        
        for (Edge edge : edges.get(cn)) {
            int nn = edge.nn, nv = edge.nv;
            if (v[nn]) continue;
            if (spent + nv > C) continue;
            v[nn] = true;
            dfs(nn, spent + nv, Math.max(mv, nv));
            v[nn] = false;
        }
    }
    
    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        A = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        for (int i = 0; i <= N; ++i) edges.add(new ArrayList<>());
        
        while (M-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            edges.get(a).add(new Edge(b, c));
            edges.get(b).add(new Edge(a, c));
        }
        
        ans = -1;
        v[A] = true;
        dfs(A, 0, 0);
        
        bw.write(ans + "\n");
        br.close();
        bw.close();
    }
}