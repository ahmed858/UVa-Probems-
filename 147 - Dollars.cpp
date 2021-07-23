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
#define MAX					30000+1
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
	//freopen("out.txt", "w", stdout);
}
const int N = 11;

int coin[] = { 5, 10, 20,50,100,200,500,1000,2000,5000,10000 };
ll memo[N][MAX];

ll solve(int idx, int remainder) {
	if (remainder == 0)return 1;
	if (idx == N )return 0;

	ll& ret = memo[idx][remainder];
	if (~ret)return ret;

	ret = solve(idx + 1, remainder);//leave it

	if (remainder >= coin[idx])
		ret += solve(idx, remainder - coin[idx]);
	return ret;
}
int main() {
	fast();
	double x;
	while (cin >> x, x != 0.0)
	{
		memset(memo, -1, sizeof memo);
		int value = (int)((x + .001) * 100);
		cout << fixed << setprecision(2) << setw(6) << x << setw(17) << solve(0, value) << endl;
	}
}
/*
				COMMENT THE FILE FUNCTION !?!
*/
