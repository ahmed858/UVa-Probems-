/*     pacman game problem */

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
int dx[]{ 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[]{ 0, 1, -1, 0, 1, -1, 1, -1 };
string dir[] = { "D","U","R","L" };
//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {
	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}


bool valid(int i, int j) {
	return i < 1e9&& i >= 0 && j < 1e9 && j >= 0;
}
vector<vector<pii>>adj;
vl dis;
ll bfs(int source) {
	queue<int>Q;
	dis = vl(1e6, -1);
	Q.push(source);
	dis[source] = 0;
	while (!Q.empty())
	{
		int parent = Q.front();Q.pop();
		for (pii child : adj[parent])if (dis[child.first] == -1) {
			Q.push(child.first);
			dis[child.first] = child.second + dis[parent];
		}
	}
	
	return *max_element(all(dis));
}
int main()
{
	fast();
	int u, v, len;
	set<int>st;
	adj = vector<vector<pii>>(1e6);
	while (cin >> u >> v >> len)
	{
		adj[u].push_back({ v,len });
		adj[v].push_back({ u,len });
		st.insert(u);
		st.insert(v);
	}
	ll ans = 0;
	for (auto i : st) 
		ans = max(ans, bfs(i));
	cout << ans;
}



