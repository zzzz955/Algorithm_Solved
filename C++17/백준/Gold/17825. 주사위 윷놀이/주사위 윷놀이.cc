#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

const int FIN = 32;
int dice[10];
int nxt[34], blue[34], val[34];
int pos[4];
int ans;

int moveTo(int p, int d) {
    if (p == FIN) return FIN;
    if (blue[p] != -1) {
        p = blue[p];
        d--;
    }
    else {
        p = nxt[p];
        d--;
    }
    while (d-- > 0 && p != FIN) p = nxt[p];
    return p;
}

void dfs(int turn, int sum) {
    if (turn == 10) { ans = max(ans, sum); return; }

    for (int i = 0; i < 4; ++i) {
        if (pos[i] == FIN) continue;
        int np = moveTo(pos[i], dice[turn]);

        if (np != FIN) {
            bool flag = false;
            for (int j = 0; j < 4; ++j) {
                if (j != i && pos[j] == np) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
        }

        int bak = pos[i];
        pos[i] = np;
        dfs(turn + 1, sum + (np == FIN ? 0 : val[np]));
        pos[i] = bak;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 10; ++i) cin >> dice[i];

    memset(blue, -1, sizeof(blue));
    val[0] = 0;
    for (int i = 1; i <= 20; ++i) val[i] = 2 * i;
    val[21] = 13; val[22] = 16; val[23] = 19;
    val[24] = 22; val[25] = 24;
    val[26] = 28; val[27] = 27; val[28] = 26;
    val[29] = 25; val[30] = 30; val[31] = 35;
    val[FIN] = 0;

    nxt[0] = 1;
    for (int i = 1; i < 20; ++i) nxt[i] = i + 1;
    nxt[20] = FIN;
    blue[5] = 21; nxt[21] = 22; nxt[22] = 23; nxt[23] = 29;
    blue[10] = 24; nxt[24] = 25; nxt[25] = 29;
    blue[15] = 26; nxt[26] = 27; nxt[27] = 28; nxt[28] = 29;
    nxt[29] = 30; nxt[30] = 31; nxt[31] = 20; nxt[20] = FIN;
    
    dfs(0, 0);
    cout << ans;
}
