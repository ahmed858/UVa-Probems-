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
#define MAX					1005
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
//  down up right left  topright topleft bottomright bottomleft
int dx[] = { 1,-1,0,0 - 1,-1,1,1 };
int dy[] = { 0,0,-1,1 ,1,-1,1,-1 };
string dir[] = { "D","U","R","L" };
void fast() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }



int vis[MAX][MAX];
int n, m;
vector<vector<int>>adj;
char grid[MAX][MAX];
bool valid(int i, int j) {
	return i < n && i >= 0 && j < n && j >= 0;
}
void solve(int i, int j) {
	if (vis[i][j]||!valid(i,j)||grid[i][j]=='.')
		return;
	vis[i][j] = 1;
	solve(i + 1, j);
	solve(i - 1, j);
	solve(i, j + 1);
	solve(i, j - 1);
}
int main()
{
	fast();
	int t;
	cin >> t;
	for(int k=1;k<=t;k++)
	{
		int ans = 0;
		cin >> n ;
		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)cin >> grid[i][j];
		memset(vis, 0, sizeof vis);

		for (int i = 0; i < n; i++)for (int j = 0; j < n; j++) {
			if (!vis[i][j] && grid[i][j] == 'x')
			{
				ans++;
				solve(i, j);
			}
		}
		printf("Case %d: %d\n", k, ans);


	}


}



