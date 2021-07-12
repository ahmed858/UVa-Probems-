
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
#define MAX					100005
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
//  down up right left  topright topleft bottomright bottomleft
int dx[] = { 1,-1,0,0 - 1,-1,1,1 };
int dy[] = { 0,0,-1,1 ,1,-1,1,-1 };
string dir[] = { "D","U","R","L" };
//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {
	//freopen("jumping.in", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
bool valid(int i, int j) {
	int n = 8, m = 8;
	return i < n&& i >= 0 && j < m && j >= 0;
}
pii start, goal;
int dis[10][10];
int bfs() {
	memset(dis, -1, sizeof dis);
	dis[start.first][start.second] = 0;
	queue<pii> q;
	q.push(start);
	while (!q.empty()) {
		pii cur = q.front();
		q.pop();
		if (cur == goal) {
			return dis[cur.first][cur.second];
		}
		int r = cur.first;
		int c = cur.second;
		for (int k = 0; k < 8; k++) { // try all 8 moves
			int nr = r + DX[k]; // new row
			int nc = c + DY[k]; // new column
			if (!valid(nr, nc)) continue; // if out of boar
			if (dis[nr][nc] == -1) // if we didn't already visit it
				dis[nr][nc] = dis[r][c] + 1, q.push({ nr,nc });
		}
	}
	return -1;
}
int main()
{
	fast();
	string s,t;
	while (cin>>s>>t)
	{
		start.first = s[1] - '1';
		start.second = s[0] - 'a';

		goal.first = t[1] - '1';
		goal.second = t[0] - 'a';		
		cout << "To get from " << s << " to " << t << " takes " << bfs() << " knight moves." << endl;
	}


}



