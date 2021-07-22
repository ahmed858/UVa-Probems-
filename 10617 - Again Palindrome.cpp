#define _CRT_SECURE_NO_WARNINGS
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
#define MAX					100
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;

int dx[]{ 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[]{ 0, 1, -1, 0, 1, -1, 1, -1 };

//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}
string s;
ll memo[MAX][MAX];
ll solve(int i, int j) {
	if (i == j)return 1;
	if (i + 1 == j)return 2 + (s[i] == s[j]);
	ll& ret = memo[i][j];
	if (~ret)return ret;
	ret = 0;
	if (s[i] == s[j])
	{
		ret += 1 + solve(i + 1, j - 1);
	}
	ret += solve(i + 1, j);
	ret += solve(i, j-1);
	ret -= solve(i + 1, j-1);
	return ret;
}
int main() {
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		memset(memo, -1, sizeof memo);
		cout << solve(0, sz(s)-1) << endl;
	}

}
/*
				COMMENT THE FILE FUNCTION !?!
*/
