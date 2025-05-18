import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, M, A, B, C;
    static class Edge {
        int nn, nv;
        Edge(int nn, int nv) {
            this.nn = nn;
            this.nv = nv;
        }
    }
    static List<List<Edge>> edges = new ArrayList<>();
    static class Pos {
        int cn, cv, mv;
        Pos(int cn, int cv, int mv) {
            this.cn = cn;
            this.cv = cv;
            this.mv = mv;
        }
    }
    
    static int dijkstra() {
        PriorityQueue<Pos> pq = new PriorityQueue<>((a, b) -> a.cv - b.cv);
        pq.offer(new Pos(A, 0, 0));
        int[] dist = new int[N + 1];
        Arrays.fill(dist, 2000000000);
        dist[A] = 0;
        int min_val = 2000000000;
        
        while (!pq.isEmpty()) {
            Pos pos = pq.poll();
            int cn = pos.cn, cv = pos.cv, mv = pos.mv;
            if (dist[cn] < cv) continue;
            
            for (Edge edge : edges.get(cn)) {
                int nn = edge.nn, nv = edge.nv;
                if (cv + nv > C) continue;
                if (dist[nn] > cv + nv) {
                    int new_mv = Math.max(mv, nv);
                    if (nn == B && min_val > new_mv) min_val = new_mv;
                    dist[nn] = cv + nv;
                    pq.offer(new Pos(nn, cv + nv, new_mv));
                }
            }
        }
        return dist[B] == 2000000000 ? -1 : min_val;
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
        
        bw.write(dijkstra() + "\n");
        br.close();
        bw.close();
    }
}