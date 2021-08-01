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
const int  N = 1e6 + 5, M = 501, mod = 1e9 + 7, INF = 2e9, length = 25;

vi Dijkstra1(vector<vi>adjMAT, int src, int target = -1) {
	//(SSSP) Algo O(N^2)
	int n = sz(adjMAT);
	vi vis(n, 0), dis(n, INF),prev(n,-1);
	dis[src] = 0;
	while (true)
	{
		int val = INF, idx = -1;
		for (int i = 0; i < n; i++) {
			if (!vis[i] && dis[i] < val)
				val = dis[i], idx = i;
		}

		if (idx == -1 || target == idx)break;

		vis[idx] = true;
		for (int i = 0;i < n; i++) {
			if (dis[i] > (val=dis[idx] + adjMAT[idx][i])) {
				dis[i] = val;
				prev[i] = idx;
			}
		}
	}
	return dis;
}
struct edge {
	int from, to, w;
	edge(int f, int t, int w) :from(f), to(t), w(w){}
	bool operator<(const edge& other)const {
		return w > other.w;
	}
};
vi Dijkstra2(vector<vector<edge>> adjL, int src, int target) { // O( E log(V) )
	int n = sz(adjL);
	vi dis(n, INF),prev(n,-1);
	priority_queue<edge>pq;
	pq.push({ -1, src, 0 });
	while (!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();
		if (cur.w > dis[cur.to])// calc it before with best cost
			continue;
		prev[cur.to] = cur.from;
		for (auto child : adjL[cur.to]) {
			edge ne = child;
			if (dis[ne.to] > dis[ne.from] + ne.w) {
				ne.w = dis[ne.from] + ne.w;
				pq.push(ne);
			}
		}

	}
	return dis;
}
vi dijkstra_ALAKRAB_ELA_KALBY(vector < vector<pii>> adj, int src, int target) {//O((V+E log(E)))
	//   adj  <node ,cost> 
	int n = sz(adj);
	vi dis(n+5, -1);
	set<pii>st;//  <totalCost,node>
	//dis[src] = 0; dont because the first turn i reach the node its the best
	st.insert({ 0,src });
	while (!st.empty())
	{
		pii cur = *st.begin(); st.erase(cur);
		int node = cur.second, d = cur.first;
		if (dis[node] != -1)continue;

		dis[node] = d;
		for (pii child : adj[node])
			if (dis[child.first] == -1) {
				st.insert({ d + child.second ,child.first });
			}
	}
	return dis;
}
int main() {
    fast();
	int t,tt=1;
	cin >> t;
	while (t--)
	{
		int n, m, src, target;
		cin >> n >> m >> src >> target;
		vector<vector<pii>>adj(n+5);
		while (m--)
		{
			int u, v, c;
			cin >> u >> v >> c;
			//u--, v--; input 0 based
			adj[u].push_back({ v,c });
			adj[v].push_back({ u,c });
		}
		vi dis = dijkstra_ALAKRAB_ELA_KALBY(adj, src, target);
		cout << "Case #" << tt++ << ": ";
		if (dis[target] == -1)cout << "unreachable";
		else cout << dis[target];
		cout << endl;
	}
	
}

