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
const int  N = 50 + 5, M = 501, mod = 1e9 + 7, INF = 2e9, length = 25;
int n;
double X[N], Y[N], people[N];
struct edge
{
	int u, v;
	double d;
	edge(int U, int V, double D) :u(U), v(V), d(D) {};
	const bool operator <(const edge& other)const {
		return d < other.d;
	}
};
struct DSU {
	int perant[N], size[N];
	double weight[N];
	void init() {
		iota(perant, perant + n, 0);
		fill(size, size + n, 1);
		for (int i = 0; i < n; i++) {
				weight[i] = people[i];
		}
	}
	int Find_perant(int u) {
		return perant[u] == u ? u : perant[u] = Find_perant(perant[u]);
	}
	bool Union(int a, int b) {
		a = Find_perant(a);
		b = Find_perant(b);
		if (a == b)
			return false;
		if (size[a] < size[b])
			swap(a, b);

		perant[b] = a;
		size[a] += size[b];
		weight[a] += weight[b];
		return 1;
	}
}dsu;
vector<edge>edges;
double kruskal() {
	
	sort(all(edges));
	double div = 0, sum = 0;
	dsu.init();
	for (int i = 0; i < n; i++)
		div += people[i];

	for (int i = 0; i < sz(edges); i++) {
		int u = edges[i].u, v = edges[i].v;
		double d = edges[i].d;

		if (dsu.Find_perant(u) != dsu.Find_perant(v)) {

			if (dsu.Find_perant(u) == dsu.Find_perant(0))
				sum +=  dsu.weight[dsu.Find_perant(v)] * d;
			
			if (dsu.Find_perant(v) == dsu.Find_perant(0)) 
				sum +=  dsu.weight[dsu.Find_perant(u)] * d;
			
			dsu.Union(u, v);
		}
	}
	return sum / div;
}
int main() {

	fast();
	int cases = 0;
	while (cin >> n)	{
		if (!n)
			return 0;
		edges = vector<edge>();
		for (int i = 0; i < n; i++)
			cin >> X[i] >> Y[i] >> people[i];
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				double d = hypot(X[i] - X[j], Y[i] - Y[j]);
				edges.push_back(edge(i, j, d));
			}
		}

		double averge = kruskal();
		printf("Island Group: %d Average %.2lf\n", ++cases, averge);
		puts("");
	}
}

