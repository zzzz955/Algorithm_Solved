#include<iostream>
#include<queue>
#include<unordered_map>
#include<cstring>
using namespace std;

const int N = 1e5 + 1;
int n, k, m;
unordered_map<int, int> dic;
int lst[N];
vector<int> edges[N];

vector<int> bfs(int dn) {
    queue<int> q;
    q.push(1);

    vector<bool> v(n + 1, false);
    vector<int> path(n + 1, -1);
    v[1] = true;

    while (!q.empty()) {
        int cn = q.front(); q.pop();
        int cb = lst[cn];

        for (int nn : edges[cn]) {
            if (v[nn]) continue;
            path[nn] = cn;
            v[nn] = true;

            if (nn == dn) {
                vector<int> res;
                int curr = dn;
                while (curr != -1) {
                    res.push_back(curr);
                    curr = path[curr];
                }
                return res;
            }
            q.push(nn);
        }
    }

    return {};
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;

		int b = 0;
		for (int i = 0; i < k; ++i) {
			if (s[i] == '1') b += 1 << k - i - 1;
		}

		//cout << s << " " << b << "\n";
		dic[b] = i;
		lst[i] = b;
	}

    for (int i = 1; i <= n; ++i) {
        int cb = lst[i];
        for (int j = 0; j < k; ++j) {
            int nb = cb ^ (1 << j);

            auto it = dic.find(nb);
            if (it != dic.end()) {
                edges[i].push_back(it->second);
            }
        }
    }

	cin >> m;
	while (m--) {
		int a; cin >> a;
		vector<int> res = bfs(a);

		if (res.empty()) cout << -1;
		else for (int i = res.size() - 1; i >= 0; --i) {
			cout << res[i];
			if (i > 0) cout << " ";
		}
		cout << "\n";
	}
}