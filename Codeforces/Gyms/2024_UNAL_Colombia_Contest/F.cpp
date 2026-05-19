// Problem: F. Pacman or Shot
// Contest: Codeforces - 2024 ICPC Universidad Nacional de Colombia Programming Contest
// URL: https://codeforces.com/gym/105278/problem/F
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ld long double
#define nl '\n'
#define fast cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
#define fore(i,a,b) for(ll i=a;i<b;++i)
#define ALL(u) u.begin(),u.end()
#define vi vector <ll>
#define vvi vector<vi>
#define sz(a) ((int)a.size())
#define pii pair<ll,ll>
#define fst first
#define snd second
 
using namespace std;

const int maxn = 5005;
const int INF = 1e9+7;
int n,m,mov[4][2] = {{0,1},{1,0},{-1,0},{0,-1}},d[maxn][maxn][2];
vector < vector <char> > a;
string s;
bool flag;

void init(){
	a.resize(n+2);
	fore(i,0,n+2){
		a[i].resize(m+2);
	}
	flag = true;
}

bool outside(int &x, int &y){
	if (x <= 0 || x > n || y <= 0 || y > m) return true;
	return false;
}

void makeMove(int &x, int &y, char &c){
	int dx=0,dy=0;
	if (c == 'U') dx=-1;
	else if (c == 'D') dx=1;
	else if (c == 'L') dy=-1;
	else dy=1;
	int nx = x + dx,ny = y + dy;
	if (outside(nx,ny)){
		if (c == 'U') nx = n;
		else if (c == 'D') nx = 1;
		else if (c == 'L') ny = m;
		else ny = 1;
	}
	if (a[nx][ny] == '#') return;
	x = nx, y = ny;
}

void mp(int &x, int &y){
	d[x][y][0] = 0;
	fore(i,0,sz(s)){
		makeMove(x,y,s[i]);
		d[x][y][0] = i+1;
	}
}

void bfs(int &x, int &y){
	d[x][y][1] = 0;
	queue < pair <int,int> > q;
	q.push({x,y});
	while(!q.empty() && flag){
		x = q.front().fst;
		y = q.front().snd;
		q.pop();
		if (d[x][y][0] >= d[x][y][1]) flag = false;
		fore(i,0,4){
			int sx = x + mov[i][0];
			int sy = y + mov[i][1];
			if (!outside(sx,sy) && a[sx][sy] != '#' && d[sx][sy][1] == INF){
				q.push({sx,sy});
				d[sx][sy][1] = d[x][y][1] + 1;
			}
		}
	}
}

int main(){
    fast;
	cin>>n>>m;
	init();
	int px,py,gx,gy;
	fore(i,1,n+1){
		fore(j,1,m+1){
			cin>>a[i][j];
			if (a[i][j] == 'P') px = i, py = j;
			if (a[i][j] == 'G') gx = i, gy = j;
			d[i][j][0] = -1, d[i][j][1] = INF;
		}
	}
	cin>>s;
	mp(px,py);
	bfs(gx,gy);
	cout<<(!flag ? "Yes" : "No")<<nl;
	return 0;
}