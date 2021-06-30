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

int x;
int weather[10][MAX];
int memo[10][MAX];

int solve(int level, int mile) {
	//base case
	if (level > 9 || level<0 || mile>x)
		return 1e9;
	int& ret = memo[level][mile];
	if (mile == x) {
		if (level == 0)
			return 0;
		else
			return 1e9;
	}
	if (ret != -1)
		return ret;

	return ret=min({ 30 + -weather[level][mile] + solve(level, mile + 1),
		60 - weather[level][mile] + solve(level + 1, mile + 1),
		20 - weather[level][mile] + solve(level - 1, mile + 1) });
}
int main()
{
    fast();
	int t;
	cin >> t;
	while (t--) {
		cin >> x;
		x /= 100;
		memset(memo, -1, sizeof memo);
		for (int i = 9; i >=0; i--) {
			for (int j = 0; j < x; j++) {
				cin >> weather[i][j];
			}
		}

		cout << solve(0, 0) << endl;
		cout << endl;
	}
}
