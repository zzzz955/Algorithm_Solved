#include<iostream>
using namespace std;
using ll = long long;

const int N = 123456;
int n, d_atk;
struct OP {
	bool t;
	ll a, h;
};
OP lst[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> d_atk;
	for (int i = 0; i < n; ++i) {
		int t;
		ll a, h; 
		cin >> t >> a >> h;
		lst[i] = { t == 1 ? false : true, a, h };
	}

	ll ans = 0;
	ll l = 0, r = 1e18;
	while (l <= r) {
		ll mid = (l + r) / 2;
		bool flag = true;
		ll atk = d_atk;
		ll hp = mid;

		for (int i = 0; i < n; ++i) {
			const OP& op = lst[i];
			if (op.t) {
				atk += op.a;
				hp = min(mid, hp + op.h);
			}
			else {
				ll m_hp = op.h, m_atk = op.a;
				ll hits = m_hp % atk ? m_hp / atk + 1 : m_hp / atk;
				if (hp > m_atk * (hits - 1)) hp -= m_atk * (hits - 1);
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	cout << ans;
}