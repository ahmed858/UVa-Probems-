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
#define clr(x,y)			memset(x,y,sizeof x)
#define RT(v)			    return cout<<v,0
#define sz(x)			    x.size()
#define pii					pair<int,int>
using namespace std;
const double EPS = 1e-10, pi = 3.14159265358979323846;
int dx[]{ 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[]{ 0, 1, -1, 0, 1, -1, 1, -1 };
//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE 
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif
}
const int  N = 1e3 + 5, M = 501, mod = 1e9 + 7, INF = 2e9, length = 25;

#define BOMB 1
int n, m;
bool grid[N][N];
int dis[N][N];
bool vis[N][N];
bool valid(int i, int j) {
	return i < n&& i >= 0 && j < m&& j >= 0 && grid[i][j] != BOMB;
}
int main() {
    fast();
	while (cin>>n>>m)
	{
		if (!n && !m)return 0;
		int R;
		cin >> R;
		clr(grid, 0);
		for (int i = 0; i < R; i++) {
			int row;
			cin >> row;
			int ncol;
			cin >> ncol;
			for (int j = 0; j < ncol; j++)
			{
				int col;
				cin >> col;
				grid[row][col] = BOMB;
			}
		}
		pii src, target;
		cin >> src.first >> src.second >> target.first >> target.second;
		queue<pii>Q;
		clr(dis, -1);
		dis[src.first][src.second] = 0;
		Q.push(src);
		while (!Q.empty()){
			pii cur = Q.front(); 
			Q.pop();
			if (cur == target)break;
			int x = cur.first, y = cur.second;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (valid(nx, ny)) {
					if (dis[nx][ny]==-1) {
						dis[nx][ny] = dis[x][y] + 1;
						Q.push({ nx,ny });
					}
				}
			}
		}
		cout << dis[target.first][target.second] << endl;
	}
	
}

