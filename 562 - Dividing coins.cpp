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
#define MAX					1001
using namespace std;
const ll mod = 1e6 + 3;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
bool valid(int i, int j) 
{
int n=0, m=0;
	return 
		i < n && i >= 0 &&
		j < m && j >= 0;
}
void fast() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}


int n,sum;
int memo[100][50001];// 100 *500 at most  
int coin[100];
int solve(int i, int curSum) {
	if (i == n)return abs(curSum - (sum-curSum));// the 1th person sbset  - reminder

	int& ret = memo[i][curSum];
	if (~ret)
		return ret;

	int ch1 = solve(i + 1, curSum);
	int ch2 = solve(i + 1, curSum + coin[i]);
	return ret=min(ch1, ch2);
}
int main()
{
	fast();
	int t=1; 
	cin >> t;

	while (t--)
	{
		
		memset(memo, -1, sizeof(memo));
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; i++)
			cin >> coin[i],
			sum+=coin[i];
		cout << solve(0, 0) << endl;
	}


}


