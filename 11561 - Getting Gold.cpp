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
#define MAX					55
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;

int dx[]{ 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[]{ 1, 0, -1, 0, 1, -1, 1, -1 };
string dir[] = { "D","U","R","L" };
//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}
int n,m;
char grid[MAX][MAX];
bool used[MAX][MAX];
int cnt = 0;
bool valid(int i, int j) {
	return i < n&& i >= 0 && j < m&& j >= 0;
}

void solve(int i, int j) {
	if (used[i][j]||  grid[i][j] == '#')
		return;
	if (grid[i][j] == 'G')cnt++;
	used[i][j] = 1;
	for (int k = 0; k < 4; k++)
		if (grid[i + dx[k]][j + dy[k]] == 'T')return;

	for (int k = 0; k < 4; k++) {
		int x = dx[k] + i;
		int y = dy[k] + j;
		solve(x, y);
	}
}
int main()
{
	fast();
	while (cin >> n >> m)
	{
		int x=0, y=0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'P')
					x = i, y = j;
			}
		}
		memset(used, 0, sizeof used);
		cnt = 0;
		solve(x,y);
		cout << cnt << endl;
	}
}


/*
				comment the file function
*/
