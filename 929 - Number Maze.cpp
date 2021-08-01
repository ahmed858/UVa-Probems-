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
int arr[N][N];
int dis[N][N];

bool valid(int i, int j) {
	return i < n&& i >= 0 && j < m&& j >= 0;
}
struct Edge
{
	int x, y;
	int cost;
	bool operator<(const Edge& e) const
	{
		return cost > e.cost;
	}
};
int main() {
    fast();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];

	
		priority_queue<Edge>Q;
		clr(dis, '?');
		Edge e;
		e.x = 0;
		e.y = 0;
		e.cost = arr[0][0];
		Q.push(e);
		dis[0][0] = e.cost;
		while (!Q.empty()) {
			Edge cur = Q.top();
			Q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (valid(nx, ny)) {
					if (dis[cur.x][cur.y] + arr[nx][ny] < dis[nx][ny]) {
						dis[nx][ny] = dis[cur.x][cur.y] + arr[nx][ny];
						Q.push({ nx, ny, dis[nx][ny] });
					}
				}
			}

		}
		cout << dis[n-1][m-1] << endl;
	}
	
}

