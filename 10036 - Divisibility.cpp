#include<bits/stdc++.h>

#define ll				    long long
#define all(v)			    v.begin(),v.end()
#define allr(v)			    v.rbegin(),v.rend()
#define YES				    cout << "YES\n";
#define NO				    cout << "NO\n";
#define endl			    "\n"
#define vi				    vector<int>
#define vl				    vector<ll>
#define wach(x)			    cerr<<(#x)<<" = ("<<(x)<<")"<<"\n"
#define RT(v)			    return cout<<v,0
#define sz(x)			    x.size()
#define pii					pair<int,int>
#define MAX					1001
using namespace std;
const ll mod = 1e6 + 3;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
}
int n, k;
vi v;
int memo[20000][200];
int fix(int n) {
	return  (n % k + k) % k;
}
bool solve(int i, int mod) {
	int& ret = memo[i][mod];
	if (ret != -1)
		return ret;
	if (i == n)
		return ret = mod == 0;
	if (solve(i + 1, fix(mod + v[i])) || solve(i + 1, fix(mod - v[i])))
		return ret = 1;
	return ret = 0;
}
int main()
{
    fast();
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		memset(memo, -1, sizeof memo);
		v = vi(n);
		for (int& i : v)
			cin >> i;
		if (solve(1, v[0]))
			cout << "Divisible";
		else
			cout << "Not divisible";
		cout << endl;
	}
}
