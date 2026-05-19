#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(), a.end()
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define nl '\n'
#define eb emplace_back

using namespace std;

const int N = 22 * 22 * 22;
int cnt1[N][N], cnt2[N][N];
vector<array<int, 3>> v[N][2][2][2];

void init() {
    fore(i, 0, N) {
        fore(j, 0, 2) {
            fore(ii, 0, 2) {
                fore(jj, 0, 2) v[i][j][ii][jj].reserve(150);
            }
        }
    }
}

int main() {
    fast;
    int n;
    cin >> n;
    init();

    int n2 = n * n;

    static string s[22][22]; // assuming n <= 22 from N
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        for (int j = 0; j < n; j++) cin >> s[i][j];
    }

    for (int i = -40; i <= 40; i++)
        for (int j = -40; j <= 40; j++)
            for (int k = -40; k <= 40; k++)
                v[i * i + j * j + k * k][(i % 2 + 2) % 2][(j % 2 + 2) % 2][(k % 2 + 2) % 2].pb({i, j, k});

    // B -> A via P
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            for (int k1 = 0; k1 < n; k1++) {
                if (s[i1][j1][k1] != 'B') continue;
                for (int i2 = 0; i2 < n; i2++)
                    for (int j2 = 0; j2 < n; j2++)
                        for (int k2 = 0; k2 < n; k2++) {
                            if (s[i2][j2][k2] != 'P') continue;

                            int di = i1 - i2;
                            int dj = j1 - j2;
                            int dk = k1 - k2;
                            int r = di * di + dj * dj + dk * dk;

                            int si = i1 + i2; // sum i
                            int sj = j1 + j2;
                            int sk = k1 + k2;

                            // si,sj,sk >= 0 so &1 is safe instead of %2
                            auto &vec = v[r][si & 1][sj & 1][sk & 1];

                            int idxP = i2 * n2 + j2 * n + k2;

                            for (const auto &p : vec) {
                                int x = (p[0] + si) >> 1;
                                int y = (p[1] + sj) >> 1;
                                int z = (p[2] + sk) >> 1;

                                // bounds check using unsigned trick (avoids 3 comparisons per coord)
                                if ((unsigned)x >= (unsigned)n ||
                                    (unsigned)y >= (unsigned)n ||
                                    (unsigned)z >= (unsigned)n)
                                    continue;

                                if (s[x][y][z] == 'A') {
                                    int idxA = x * n2 + y * n + z;
                                    cnt1[idxA][idxP]++;
                                }
                            }
                        }
            }

    // C -> P via A
    for (int i1 = 0; i1 < n; i1++)
        for (int j1 = 0; j1 < n; j1++)
            for (int k1 = 0; k1 < n; k1++) {
                if (s[i1][j1][k1] != 'C') continue;
                for (int i2 = 0; i2 < n; i2++)
                    for (int j2 = 0; j2 < n; j2++)
                        for (int k2 = 0; k2 < n; k2++) {
                            if (s[i2][j2][k2] != 'A') continue;

                            int di = i1 - i2;
                            int dj = j1 - j2;
                            int dk = k1 - k2;
                            int r = di * di + dj * dj + dk * dk;

                            int si = i1 + i2;
                            int sj = j1 + j2;
                            int sk = k1 + k2;

                            auto &vec = v[r][si & 1][sj & 1][sk & 1];

                            int idxA = i2 * n2 + j2 * n + k2;

                            for (const auto &p : vec) {
                                int x = (p[0] + si) >> 1;
                                int y = (p[1] + sj) >> 1;
                                int z = (p[2] + sk) >> 1;

                                if ((unsigned)x >= (unsigned)n ||
                                    (unsigned)y >= (unsigned)n ||
                                    (unsigned)z >= (unsigned)n)
                                    continue;

                                if (s[x][y][z] == 'P') {
                                    int idxP = x * n2 + y * n + z;
                                    cnt2[idxA][idxP]++;
                                }
                            }
                        }
            }

    long long res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            res += 1LL * cnt1[i][j] * cnt2[i][j];

    cout << res << nl;
    return 0;
}
