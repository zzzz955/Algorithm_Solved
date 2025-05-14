import java.util.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int N, M, K;
    static class Edge {
        int nn, nv;
        Edge (int nn, int nv) {
            this.nn = nn;
            this.nv = nv;
        }
    }
    static class Pos {
        int cn, cv;
        Pos (int cn, int cv) {
            this.cn = cn;
            this.cv = cv;
        }
    }

    static int[] dijkstra (int sn, List<List<Edge>> edges) {
        PriorityQueue<Pos> pq = new PriorityQueue<>((o1, o2) -> o1.cv - o2.cv);
        pq.add(new Pos(sn, 0));
        int[] dist = new int[N + 1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[sn] = 0;

        while (!pq.isEmpty()) {
            Pos u = pq.poll();
            int cn = u.cn, cv = u.cv;
            if (dist[cn] < cv) continue;

            for (Edge edge : edges.get(cn)) {
                int nn = edge.nn, nv = edge.nv;
                if (dist[nn] > cv + nv) {
                    dist[nn] = cv + nv;
                    pq.add(new Pos(nn, cv + nv));
                }
            }
        }
        return dist;
    }

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int T = Integer.parseInt(st.nextToken());

        while (T-- > 0) {
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());

            List<List<Edge>> edges =  new ArrayList<>();
            for (int i = 0; i <= N; ++i) {
                edges.add(new ArrayList<>());
            }

            while (M-- > 0) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());
                int c = Integer.parseInt(st.nextToken());

                edges.get(a).add(new Edge(b, c));
                edges.get(b).add(new Edge(a, c));
            }

            st = new StringTokenizer(br.readLine());
            K = Integer.parseInt(st.nextToken());
            int[] preDist = new int[N + 1];
            Arrays.fill(preDist, 0);

            st = new StringTokenizer(br.readLine());
            while (K-- > 0) {
                int cn = Integer.parseInt(st.nextToken());
                int[] dist = dijkstra(cn, edges);
                for (int i = 1; i <= N; ++i) {
                    preDist[i] += dist[i];
                }
            }

            int node = 1;
            int min_val = Integer.MAX_VALUE;
            for (int i = 1; i <= N; ++i) {
                if (preDist[i] < min_val) {
                    min_val = preDist[i];
                    node = i;
                }
            }
            bw.write(node + "\n");
        }

        br.close();
        bw.close();
    }
}