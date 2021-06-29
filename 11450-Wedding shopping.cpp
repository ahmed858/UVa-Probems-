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
#define MAX					101
using namespace std;
const ll mod = 1e6 + 3;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
void fast(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
}
		int C, n;
vector < pair<int, vi>>v;
int memo[MAX][MAX];
void input() {
	cin >> C >> n;
	v = vector<pair<int, vi>>();
	memset(memo, -1, sizeof memo);
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		vi a(k);
		for (int j = 0; j < k; j++)
			cin >> a[j];
		v.push_back({ k,a });
	}
}
int slowSolve(int mony, int idx) {
	if (mony < 0)
		return -1;
	if (idx == n)
		return C - mony;
	int ans = -1;
	//transaction
	int k = v[idx].first;
	for (int model = 0; model < k; model++) {
		ans = max(slowSolve(mony - v[idx].second[model], idx + 1), ans);
	}
	return ans;
}//very slow 



int memoSolve(int mony, int idx) {
	if (mony < 0)
		return -1;
	if (idx == n)
		return C - mony;
	int &ans = memo[mony][idx];
	if (ans != -1)
		return ans;
	//transaction
	int k = v[idx].first;
	for (int model = 0; model < k; model++) {
		ans = max(memoSolve(mony - v[idx].second[model], idx + 1), ans);
	}
	return ans;
}
int main()
{
	fast();
	int t = 1;
	cin >> t;
	while (t--)
	{
		input();
		int x = memoSolve(C, 0);
		if (x == -1)
			cout << "no solution";
		else
			cout << x;
		cout << endl;


	}
}
