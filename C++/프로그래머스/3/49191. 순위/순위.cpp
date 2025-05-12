#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<pair<int, bool>> edges[101];
bool v[101];

bool bfs(int n, int sn) {
    queue<pair<int, bool>> q;
    v[sn] = true;
    int cnt = 1;
    for (auto edge : edges[sn]) {
        q.push(edge);
        v[edge.first] = true;
        cnt++;
    }
    
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cn = cur.first;
        bool status = cur.second;
        
        for (auto edge : edges[cn]) {
            if (v[edge.first]) continue;
            if (edge.second != status) continue;
            v[edge.first] = true;
            q.push({edge.first, edge.second});
            cnt++;
        }
    }
    return cnt == n ? true : false;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for (int i = 0; i < results.size(); ++i) {
        int win = results[i][0];
        int loose = results[i][1];
        
        edges[win].push_back({loose, true});
        edges[loose].push_back({win, false});
    }
    
    for (int i = 1; i <= n; ++i) {
        memset(v, 0, sizeof(v));
        if (bfs(n, i)) {
            cout << i << " ";
            answer++;
        }
    }
    
    return answer;
}