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
#define MAX					1009
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
// up down right left  topright topleft bottonright bottonleft
int dx[] = { -1,1,0,0 - 1,-1,1,1 };
int dy[] = { 0,0,1,-1 ,1,-1,1,-1 };
void fast() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }

int n;
char grid[MAX][MAX];
bool vis[MAX][MAX];

bool valid(int i, int j) {
	return i < n&& i >= 0 && j < n&& j >= 0;
}

void solve(int i, int j) {
	if (!valid(i, j) || vis[i][j] || grid[i][j] == '0')
		return;
	vis[i][j] = true;

	for (int k = 0; k < 8; k++) {
		solve(i + dx[k], j + dy[k]);
	}
}
int main()
{
	//fast();
	int t = 1;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> grid[i][j];
		memset(vis, 0, sizeof vis);
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1' && !vis[i][j]) {
					ans++;
					solve(i, j);
				}
			}
		printf("Image number %d contains %d war eagles.\n", t++, ans);
	}
}


