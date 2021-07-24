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
#define MAX					266
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
	freopen("out.txt", "w", stdout);
}

struct node {
	int x, y, dir, time;

	node(int a, int b, int c, int d) {
		x = a;
		y = b;
		dir = c;
		time = d;
	}
};
int M, N;
int di[] = { -1,0,1,0 };
int dj[] = { 0,1,0,-1 };
bool obstacle[50][50];
bool visited[51][51][4];// x,y,direction
bool valid(int x, int y) {
	if (x <= 0 || y <= 0 || x >= M || y >= N) return false;
	if (obstacle[x - 1][y - 1])
		return false;
	if (obstacle[x - 1][y]) return false;
	if (obstacle[x][y - 1]) return false;
	if (obstacle[x][y]) return false;

	return true;
}
int shortest_time(int startx, int starty, int dir, int endx, int endy) {
	queue<node>Q;
	if (valid(startx, starty)) {
		Q.push({ startx, starty, dir, 0 });
		visited[startx][starty][dir] = true;
	}
	while (!Q.empty())
	{
		node cur = Q.front();
		Q.pop();
		if (cur.x == endx && cur.y == endy)
			return cur.time;

		if (!visited[cur.x][cur.y][(cur.dir + 1) % 4]) {
			visited[cur.x][cur.y][(cur.dir + 1) % 4] = true;
			Q.push({ cur.x, cur.y, (cur.dir + 1) % 4, cur.time + 1 });
		}
		if (!visited[cur.x][cur.y][(cur.dir + 3) % 4]) {
			visited[cur.x][cur.y][(cur.dir + 3) % 4] = true;
			Q.push({ cur.x, cur.y, (cur.dir + 3) % 4, cur.time + 1 });

		}
		for (int i = 1; i <= 3; i++) {
			int nx = cur.x + di[cur.dir] * i;
			int ny = cur.y + dj[cur.dir] * i;
			if (valid(nx, ny)) {
				if (visited[nx][ny][cur.dir])
					continue;
				visited[nx][ny][cur.dir] = true;
				Q.push({ nx,ny,cur.dir,cur.time + 1 });
			}
			else break;
		}
	}
	return -1;
}
int main() {
	fast();
	int startx, starty, endx, endy, dir;
	string s;
	while (cin >> N >> M) {
		if (!N && !M)return 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> obstacle[i][j];


		cin >> startx >> starty >> endx >> endy >> s;
		
		if (s[0] == 'n') dir = 0;
		else if (s[0] == 'e') dir = 1;
		else if (s[0] == 's') dir = 2;
		else dir = 3;
		memset(visited, 0, sizeof visited);
		cout << shortest_time(startx, starty, dir, endx, endy) << endl;
	}


}


/*
				COMMENT THE FILE FUNCTION !?!
*/
