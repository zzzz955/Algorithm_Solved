#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

const int N = 4002;
const int K = 100001;
int n, k;
int lst[N][N];
bool v[N][N];
struct Pos {
	int x, y, g;
};
queue<Pos> flood;
int groups[K];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int Find(int a) {
	if (groups[a] == a) return a;
	return groups[a] = Find(groups[a]);
}

void Union(int a, int b) {
	int A = Find(a);
	int B = Find(b);
	if (A == B) return;
	if (A > B) swap(A, B);
	groups[B] = A;
	k--;
	//cout << a << " " << b << " " << k << "\n";
}

void floodfill() {
	queue<Pos> q;
	swap(flood, q);

	while (!q.empty()) {
		Pos pos = q.front(); q.pop();
		int cx = pos.x, cy = pos.y, cg = pos.g;

		for (int i = 0; i < 4; ++i) {
			int nx = cx + dx[i], ny = cy + dy[i];
			if (2 <= nx && nx <= n * 2 && 2 <= ny && ny <= n * 2) {
				if (!v[nx][ny]) {
					v[nx][ny] = true;
					lst[nx][ny] = cg;
					flood.push({ nx, ny, cg });
				}
				else Union(cg, lst[nx][ny]);
			}
		}
	}
}

void print() {
	cout << "\n";
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << lst[i][j] << " ";
		}
		cout << "\n";
	}
}

int solution() {
	int turn = 0;
	//print();
	while (k != 1) {
		turn++;
		floodfill();
		//print();
	}
	return turn / 2;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int x, y; cin >> x >> y;
		x *= 2;
		y *= 2;
		v[x][y] = true;
		lst[x][y] = i;
		groups[i] = i;
		flood.push({ x, y, i });
	}

	cout << solution();
}