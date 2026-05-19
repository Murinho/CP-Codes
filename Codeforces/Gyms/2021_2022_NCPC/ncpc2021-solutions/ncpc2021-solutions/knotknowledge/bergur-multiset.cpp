#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;

int main()
{
	int i, n, x;
	cin >> n;
	multiset<int> s;
	rep(i, n) { cin >> x; s.insert(x); }
	rep(i, n - 1) { cin >> x; s.erase(s.find(x)); }
	cout << *s.begin() << endl;
}

