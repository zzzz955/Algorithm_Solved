#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int to, cnt;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> edges(n + 1);
    vector<vector<Edge>> pars(n + 1);
    vector<int> cnts(n + 1, 0);
    vector<int> sum(n + 1, 0);

    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        edges[x].push_back({ y, k });
        pars[y].push_back({ x, k });
        cnts[y]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (cnts[i] == 0) {
            q.push(i);
            if (i == n) {
                sum[n] = 1;
            }
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();

        for (const Edge& edge : edges[cur]) {
            int to = edge.to;
            int cnt = edge.cnt;

            sum[to] += sum[cur] * cnt;

            if (!--cnts[to]) q.push(to);
        }
    }

    for (int i = 1; i < n; i++) {
        if (edges[i].empty() && sum[i] > 0) {
            cout << i << " " << sum[i] << "\n";
        }
    }
}