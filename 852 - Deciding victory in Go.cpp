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
#define MAX					10
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
//  down up right left  topright topleft bottomright bottomleft
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


bool valid(int i, int j) {
	int n=9, m = 9;
	return i < n && i >= 0 && j < m && j >= 0;
}
char grid[MAX][MAX];
bool vis[MAX][MAX];
int black=0, white=0;
int blackleaves = 0, whiteleaves=0,cnt=0;
void solve(int i, int j) {
	if (vis[i][j] || !valid(i, j))
		return;
	if (grid[i][j] == 'X') {
		blackleaves++;
		return;
	}
	if (grid[i][j] == 'O') {
		whiteleaves++;
		return;
	}
	vis[i][j] = 1;
	cnt++;
	for (int k = 0; k < 4; k++) {
		solve(i + dx[k], j + dy[k]);
	}
}
int main()
{
	fast();
	int n;
	cin >> n;
	while (n--)
	{
		black = 0, white = 0;
		memset(vis, 0, sizeof vis);
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				cin >> grid[i][j];
				if (grid[i][j] == 'X')black++;
				if (grid[i][j] == 'O')white++;
			}

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (grid[i][j] == '.' && !vis[i][j]) {
					blackleaves = whiteleaves = 0;
					cnt = 0;
					solve(i, j);
					if (blackleaves && !whiteleaves) {
						black += cnt;
					}
					else if (!blackleaves && whiteleaves) {
						white += cnt;
					}
				}
			}

		}
		cout << "Black " << black << " White " << white << endl;
	}
}

