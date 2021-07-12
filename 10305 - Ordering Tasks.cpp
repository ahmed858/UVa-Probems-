
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
void fast() {
	//freopen("jumping.in", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
bool valid(int i, int j) {
	int n = 0, m = 0;
	return i < n&& i >= 0 && j < m&& j >= 0;
}
int n, m;
vector<vi>adj;
bool vis[MAX];
vi res;
void TopologicalSort(int node) {
	vis[node] = 1;
	for (int child : adj[node])
		if (!vis[child]) {
			TopologicalSort(child);
		}
	res.push_back(node);
}
int main()
{
	fast();
	while (1) {
		cin >> n >> m;
		if (!n && !m)return 0;
		adj = vector<vi>(n + 5);
		while (m--)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);

		}
		res = vi();
		memset(vis, 0, sizeof vis);
		for (int i = 1; i <= n; i++) {
			if (!vis[i])
				TopologicalSort(i);
		}
		for (int i = n - 1; i >= 0; i--) {
			if (!i)
					cout << res[i];
			else cout << res[i] << " ";
		}
		cout << endl;
	}

}



