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
#define MAX					25
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;

int dx[]{ 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[]{ 0, 1, -1, 0, 1, -1, 1, -1 };
string dir[] = { "D","U","R","L" };
//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}


int n=9, m = 9,cnt=0;
bool valid(int i, int j) {
	return i < n && i >=0 && j <= m && j >=-1;
}
char grid[MAX][MAX];
bool vis[MAX][MAX];
char cur;

void solve(int i, int j) {
	if (!valid(i, j)) {
		return;
	}
	if (j < 0)
		j = m-1;
	if (j >=m)
		j = 0;
	if (vis[i][j]!=0|| (grid[i][j] != cur))
		return;


	vis[i][j] = 1;
	cnt++;
	for (int k = 0; k < 4; k++) {
		solve(i + dx[k], j + dy[k]);
	}

}
int main()
{
	fast();
	while (cin >> n >> m)
	{
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];
		int x, y;
		cin >> x >> y;
		cur = grid[x][y];
		solve(x, y);// need to biggest one but not the current
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {

				cnt = 0;
				solve(i, j);

				ans = max(ans, cnt);

			}
		cout << ans << endl;

	}
}
	


