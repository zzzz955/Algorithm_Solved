#include<iostream>
#include<queue>
#include<vector>
using namespace std;

const int N = 1001;
int n, m, k;
struct Edge {
    int nn, nv;
};
vector<Edge> edges[N];
struct Pos {
    int cn, cv;
    bool operator<(const Pos& other) const {
        return cv > other.cv;
    }
};

void dijkstra() {
    priority_queue<Pos> pq;
    pq.push({ 1, 0 });
    vector<priority_queue<int>> dist(n + 1);

    while (!pq.empty()) {
        Pos pos = pq.top(); pq.pop();
        int cn = pos.cn, cv = pos.cv;

        if (dist[cn].size() >= k && dist[cn].top() <= cv) continue;
        dist[cn].push(cv);

        if (dist[cn].size() > k) dist[cn].pop();

        for (const Edge& edge : edges[cn]) {
            int nn = edge.nn, nc = cv + edge.nv;

            if (dist[nn].size() < k || (dist[nn].size() == k && dist[nn].top() > nc)) {
                pq.push({ nn, nc });
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i].size() < k) {
            cout << -1 << "\n";
        }
        else {
            while (dist[i].size() > k) dist[i].pop();
            cout << dist[i].top() << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
    }

    dijkstra();
}