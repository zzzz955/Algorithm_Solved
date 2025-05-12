import java.util.*;
import java.io.*;

public class Main {
    static class Pos {
        public int x;
        public int y;
        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[][] lst = new int[50][50];
    static boolean[][] v = new boolean[50][50];
    static int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    static int W, H;

    static void bfs(int sx, int sy) {
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(sx, sy));

        while (!q.isEmpty()) {
            Pos p = q.poll();
            int cx = p.x, cy = p.y;

            for (int i = 0; i < 8; ++i) {
                int nx = cx + dx[i], ny = cy + dy[i];
                if (0 <= nx && nx < H && 0 <= ny && ny < W && !v[nx][ny] && lst[nx][ny] > 0) {
                    v[nx][ny] = true;
                    q.add(new Pos(nx, ny));
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            W = Integer.parseInt(st.nextToken());
            H = Integer.parseInt(st.nextToken());
            if (W == 0 && H == 0) break;

            for (int i = 0; i < H; ++i) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < W; ++j) {
                    lst[i][j] = Integer.parseInt(st.nextToken());
                    v[i][j] = false;
                }
            }

            int ans = 0;
            for (int i = 0; i < H; ++i) {
                for (int j = 0; j < W; ++j) {
                    if (v[i][j]) continue;
                    if (lst[i][j] == 0) continue;
//                    bw.write("x:" + i + ", y:" + j + "\n");
                    v[i][j] = true;
                    ans++;
                    bfs(i, j);
                }
            }
            bw.write(ans + "\n");
        }
        br.close();
        bw.close();
    }
}