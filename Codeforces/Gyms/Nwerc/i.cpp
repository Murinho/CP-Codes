#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define vi vector<ll>
#define vvi vector<vi>
#define sz(a) ((ll)a.size())
#define ALL(a) a.begin(),a.end()
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a; i<b; i++)
#define nl '\n'
#define ld long double

using namespace std;

const ll maxn = 5e6+10;
const ll inf = 1e9+7;

struct Point{
    ll x,y;
    Point operator +(const Point& b) const { return Point{x+b.x, y+b.y}; } //suma de puntos
    Point operator -(const Point& b) const { return Point{x-b.x, y-b.y}; } //resta de puntos
    bool operator <(const Point& b) const { return x == b.x ? y < b.y : x < b.x; }
    bool operator ==(const Point &b){
        if (b.x == (*this).x && b.y == (*this).y) return true;
        return false;
    }
    void print(){
        cout << "( " << x << ", " << y << ")";
    }
};


bool sort_ccw(const Point& p, const Point& a, const Point& b) {
    return atan2(a.y - p.y, a.x - p.x) < atan2(b.y - p.y, b.x - p.x);
}

// Find a face of the graph
vector<Point> find_face(map<Point, vector<Point>>& neighbors, const Point& u, const Point& v) {
    vector<Point> face;
    Point current = v, previous = u;

    face.pb(previous);
    while (true) {
        face.pb(current);
        vector<Point>& current_neighbors = neighbors[current];
        auto index = find(ALL(current_neighbors), previous) - current_neighbors.begin();
        ll next_index = (index + 1) % sz(current_neighbors);
        Point next_vertex = current_neighbors[next_index];
        if (next_vertex.x == u.x && next_vertex.y == u.y) break;
        previous = current;
        current = next_vertex;
    }
    face.pb(u);
    return face;
}

// Find the outer edge of the graph
pair<Point, Point> find_outer_edge(map<Point, vector<Point>>& mp) {
    auto leftmost = min_element(ALL(mp), [](const pair<Point, vector<Point>>& a, const pair<Point, vector<Point>>& b) {
        return tie(a.first.x, a.first.y) < tie(b.first.x, b.first.y);
    })->first;

    vector<Point>& N_leftmost = mp[leftmost];
    sort(ALL(N_leftmost), [&leftmost](const Point& a, const Point& b) {
        return sort_ccw(leftmost, a, b);
    });

    Point u = N_leftmost[0];
    return {leftmost, u};
}

ll n,face_cnt=0;
ll d[maxn];
set <ll> g[maxn];
bool ok = false;

void bfs(){
    queue <ll> q;
    q.push(0);

    fore(i,0,face_cnt+1) d[i] = inf;
    d[0] = 0;

    while(sz(q)){
        ll node = q.front();
        q.pop();

        for(auto &signode : g[node]){
            if (d[node]+1 < d[signode]){
                d[signode] = d[node] + 1;
                q.push(signode);
            }
        }
    }
}

int main(){
    fast;
    cin >> n;
    map <Point, vector<Point>> mp; // adjacency list
    set <pair<Point,Point>> seen; // seen edges

    map <pair<Point,Point>, vi > ff; // fence to face.

    fore(i,0,n){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        Point p1 = {x1,y1};
        Point p2 = {x2,y2};

        mp[p1].pb(p2);
        mp[p2].pb(p1);
    }


    for(auto &p : mp){
        sort(ALL(p.snd), [&p](const Point &a, const Point &b){
            return sort_ccw(p.fst, a, b);
        });
    }

    auto [p, q] = find_outer_edge(mp);

    vector <Point> outer = find_face(mp, p, q);

    

    //cout << "Outer face: " << nl;
    fore(i,0,sz(outer)-1){
        seen.insert({outer[i], outer[(i+1)%sz(outer)]});
        //outer[i].print();
        //cout << " ";
        //outer[(i+1)%sz(outer)].print();
        // cout << nl;

        Point p1 = outer[i];
        Point p2 = outer[(i+1)%sz(outer)];

        if (p2 < p1) swap(p1,p2);

        ff[{p1,p2}].pb(face_cnt);
    }

    for(const auto& p : mp){
        for(const auto &q : p.snd){
            if (seen.count({p.fst, q})) continue;

            face_cnt++;
            //cout << "Inside face: " << nl;
            seen.insert({p.fst, q});
            vector<Point> face = find_face(mp, p.first, q);

            fore(i,0,sz(face)-1){
                seen.insert({face[i], face[(i+1)%sz(face)]});
                //face[i].print();
                //cout << " ";
                //face[(i+1)%sz(face)].print();
                //cout << nl;

                Point p1 = face[i];
                Point p2 = face[(i+1)%sz(face)];

                if (p2 < p1) swap(p1,p2);

                ff[{p1,p2}].pb(face_cnt);
            }
        }
    }

    // Build the adjacency list
    for(auto &au : ff){
        if (sz(au.snd) < 1) continue;
        else if (sz(au.snd) > 2){
            cout << "HERE" << nl;
            return 0;
        }
        else{
            ll f1 = au.snd[0];
            ll f2 = au.snd[1];
            g[f1].insert(f2);
            g[f2].insert(f1);
        }
    }

    bfs();

    fore(i,0,n){
        for(auto &signode : g[i]){
            if (d[i] == d[signode]) ok = true;
        }
    }

    if (!ok) cout << "no" << nl;
    else cout << "yes" << nl;
    return 0;
}