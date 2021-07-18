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
#define MAX					5000
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

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
}
bool valid(int i, int j) {
	int n = 9, m = 9;
	return i < n&& i >= 0 && j < m&& j >= 0;
}
int A, B, N;
string move_names[6] = {
	"fill A",
	"fill B",
	"empty A",
	"empty B",
	"pour A B",
	"pour B A",
};
bool vis[MAX][MAX] ;
void BFS_buildSolution() {
	vi path;
	queue<pair<pii, vi>>Q;
	Q.push({ { 0,0},path });
	while (!Q.empty())
	{
		int a = Q.front().first.first;
		int b = Q.front().first.second;
		path = Q.front().second; 
		
		Q.pop();


		if (b == N) {
			for (int i = 0; i < path.size(); i++)
				cout << move_names[path[i]] << endl;
			printf("success\n");
			break;
		}

		int na = 0, nb = 0;
		if (a != A) {
			//fill A
			if (!vis[A][b]) {
				vis[A][b] = true;
				path.push_back(0);
				Q.push({ {A,b},path });
				path.pop_back();
			}

			// pour B A
			na = a + b;
			nb = 0;
			if (na > A) {
				nb = na - A;
				na = A;
			}
			if (b != 0 && !vis[na][nb]) {
				vis[na][nb] = true;
				path.push_back(5);
				Q.push({ {na,nb},path });
				path.pop_back();
			}
		}

		if (b != B) {
			//fill B
			if (!vis[a][B]) {
				vis[a][B] = true;
				path.push_back(1);
				Q.push({ {a,B},path });
				path.pop_back();
			}
			// pour A B
			na = 0;
			nb = a + b;
			if (nb > B) {
				na = nb - B;
				nb = B;
			}
			if (a != 0 && !vis[na][nb]) {
				vis[na][nb] = true;
				path.push_back(4);
				Q.push({ {na,nb},path });
				path.pop_back();
			}

		}
			// empty a
		if (a != 0 && !vis[0][b]) {
			vis[0][b] = true;
			path.push_back(2);
			Q.push(make_pair(make_pair(0, b), path));
			path.pop_back();
		}
			// empty b
		if (b != 0 && !vis[a][0]) {
			vis[a][0] = true;
			path.push_back(3);
			Q.push(make_pair(make_pair(a, 0), path));
			path.pop_back();
		}

	}
}
int main()
{
	fast();
	while (cin >> A >> B >> N)
	{
		memset(vis, 0, sizeof vis);
		BFS_buildSolution();

	}

}


/*
				COMMENT THE FILE FUNCTION !?!
*/
