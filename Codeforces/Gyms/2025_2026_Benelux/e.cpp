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

using namespace std;

const ll maxn = 40;
const ll toth = 1e6;
const ll inf = 1e18;

ll starts[3];
ll n;
ll stt[5],stf[5];
ll ans = inf;
ll f[maxn],ti[maxn];

void doit(){
    ll elev_cnt = 1;
    ll pos = 0;
    ll t = 0;
    stt[1] = 0; // start time para este elevador
    stf[1] = 0; // start floor para este elevador
    fore(i,1,n+1){
        ll best = inf;

        fore(j,1,elev_cnt+1){
            ll diftime = ((t-stt[j]))%(toth*2);

            // get curelevpos and curori
            ll curelevpos;
            ll curori;
            if (diftime <= toth-stf[j]){
                curori = 0;
                curelevpos = stf[j] + diftime;
            }
            else{
                diftime -= toth - stf[j];
                if (diftime <= toth){
                    curori = 1;
                    curelevpos = toth - diftime;
                }
                else{
                    diftime -= toth;
                    curori = 0;
                    curelevpos = diftime;
                }
            }

            // if (i == 2 && j == 2){
            //     cout << "curelevpos: " << curelevpos << " curori: " << curori << nl;
            // }

            // Get time to pick me up
            ll cand_time = 0;
            if (curelevpos < pos){
                if (curori == 0){
                    cand_time += pos - curelevpos;
                }
                else{ // curori == 1
                    cand_time += (curelevpos + pos);
                }
            }
            else if (curelevpos > pos){
                if (curori == 0){
                    cand_time += (toth - curelevpos) + (toth - pos);
                }
                else{ // curori == 1
                    cand_time += (curelevpos - pos);
                }
            }

            // if (i == 2 && j == 2){
            //     cout << "cand_time: " << cand_time << nl;
            // }

            // get time to get to the next floor
            if (pos <= f[i]){
                if (curori == 0) cand_time += (f[i] - pos);
                else cand_time += pos + f[i];
            }
            else{ // pos >= f[i]:
                if (curori == 0) cand_time += (toth - pos) + (toth - f[i]);
                else cand_time += (pos - f[i]);
            }

            best = min(best,cand_time);
        }

        pos = f[i];
        t += best;
        t += ti[i];

        cout << i << ": " << t << " pos: " << pos << nl;
        
        if (i < n){
            fore(j,0,3){
                if (starts[j] == i){
                    elev_cnt++;
                    if (pos <= f[i+1]){ // el siguiente piso que tengo que visitar esta arriba
                        stt[elev_cnt] = t;
                        stf[elev_cnt] = f[i];
                    }
                    else{ // el siguiente piso que tengo que visitar esta abajo
                        ll difh = toth - f[i];
                        stt[elev_cnt] = max(0ll,t - difh);
                        stf[elev_cnt] = toth;
                        //cout << elev_cnt << ": " << stt[elev_cnt] << " " << stf[elev_cnt] << nl;
                    }
                }
            }
        }
    }
    ans = min(ans,t);
}

int main(){
    fast;
    cin >> n;
    fore(i,1,n+1) cin >> f[i];
    fore(i,1,n+1) cin >> ti[i];

    fore(i,1,n){
        starts[0] = i;
        fore(j,i,n){
            starts[1] = j;
            fore(k,i,n){
                starts[2] = k;
                doit();
            }
        }
    }

    cout << ans << nl;
    return 0;
}