#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector <vi>
#define sz(a) ((ll)a.size())
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define rofe(i,a,b) for(ll i=a-1; i>=b; i--)
#define fst first
#define snd second
#define pii pair <ll,ll>
#define nl '\n'
#define ALL(a) a.begin(), a.end()

using namespace std;

const int maxn = 1e5+10;

int dp[maxn],n,a[maxn];
vector <pii> b;
set <int> st;

int main(){
    fast;
    cin >> n;
    b.reserve(n);
    fore(i,1,n+1){
        cin >> a[i];
        b.pb({a[i],i});
    }


    dp[0] = dp[n+1] = -1;
    st.insert(0);
    st.insert(n+1);

    sort(ALL(b));
    reverse(ALL(b));

    //for(auto &[x,y] : b) cout << x << " " << y << nl;

    for(int i = 0; i<n; i++){
        int pos = i;
        while(pos < n && b[pos].fst == b[i].fst) pos++;

        // obtener sus respuestas primero.
        fore(j,i,pos){
            auto it = st.lower_bound(b[j].snd);

            int r = *it; 
            it--;
            int l = *it;

            //cout << b[j].snd << " " << l << " " << r << nl;

            if (abs(b[j].snd - r) < abs(b[j].snd - l)){ // hacia la derecha esta mas corto.
                if (a[r] < a[l]){ // puedo ir a ambos.
                    dp[b[j].snd] = max(dp[l],dp[r]) + 1;
                }
                else{ // solo puedo ir al derecho.
                    dp[b[j].snd] = dp[r] + 1;
                }
            }
            else if (abs(b[j].snd - r) > abs(b[j].snd - l)){ // hacia la izquierda esta mas corto.
                if (a[r] > a[l]){ // puedo ir a ambos
                    dp[b[j].snd] = max(dp[l],dp[r]) + 1;
                }
                else{
                    dp[b[j].snd] = dp[l] + 1;
                }
            }
            else{ // estan a la misma distancia.
                if (a[l] == a[r]){ // puedo ir a ambos.
                    dp[b[j].snd] = max(dp[l],dp[r]) + 1;
                }
                else if (a[l] > a[r]){ // solo puedo ir al izquierdo.
                    dp[b[j].snd] = dp[l] + 1;
                }
                else{
                    dp[b[j].snd] = dp[r] + 1;
                }
            }
        }   

        // meterlos al set
        fore(j,i,pos){
            st.insert(b[j].snd);
        }
        i = pos-1;
    }

    fore(i,1,n+1) cout << dp[i] << " ";
    cout << nl;
    return 0;
}