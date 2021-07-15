/*
---------------------Time limit--------



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
	return i < 1e9 && i >= 0 && j < 1e9 && j >= 0;
}
int n;
vector<vi>adj(MAX);
int bfs(int source) {
	vi dis(n + 1, -1);
	queue<int>Q;
	Q.push(source);
	dis[source] = 0;
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int child : adj[cur])if (dis[child] == -1) {
			Q.push(child);
			dis[child] = 1 + dis[cur];
		}
	}
	return *max_element(all(dis));
}
int main()
{
//	fast();
	while (scanf("%d", &n) != EOF) {
		adj = vector<vi>(n+5);
		int k;
		for (int node = 1; node <= n; node++) {

			scanf("%d", &k);
			for (int i = 0; i < k; i++) {
				int x;
				scanf("%d", &x);
				adj[node].push_back(x);
				adj[x].push_back(node);
			}
		}

		vi ans(MAX);
		int mn = 1e9, mx = 0;
		for (int node = 1; node <= n; node++) {
			ans[node] = bfs(node);
			mn = min(mn, ans[node]);
			mx = max(mx, ans[node]);
		}
		vi best, worst;
		for (int node = 1; node <= n; node++) {
			if (ans[node] == mn)
				best.push_back(node);
			else if (ans[node] == mx)
				worst.push_back(node);
		}
		cout << "Best Roots  : ";
		for (int i = 0; i < sz(best); i++) {
			if (!i)
				cout << best[i];
			else
				cout << " " << best[i];

		}
		cout << "\nWorst Roots : ";
		for (int i = 0; i < sz(worst); i++) {
			if (!i)
				cout << worst[i];
			else
				cout << " " << worst[i];
		}
		cout << endl;
	}
}



*/
/*ان شاء الله اكسيبتيد */


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
#define MAX					5002
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
	return i < 1e9 && i >= 0 && j < 1e9 && j >= 0;
}
int n;
vector<vi>adj(MAX);
int memo[MAX][MAX];
int dfs(int node, int parant) {
	if (memo[node][parant] != -1)return memo[node][parant];
	int h = 0;
	for (int child : adj[node])if (child != parant) {
		h = max(h, 1 + dfs(child, node));
	}
	return memo[node][parant] = h;
}
int main()
{
	fast();
	while (scanf("%d", &n) != EOF) {
		adj = vector<vi>(n + 5);
		int k;
		for (int node = 1; node <= n; node++) {

			scanf("%d", &k);
			for (int i = 0; i < k; i++) {
				int x;
				scanf("%d", &x);
				adj[node].push_back(x);
				//adj[x].push_back(node);
			}
		}

		vi ans(MAX);
		int mn = 1e9, mx = 0;
		memset(memo, -1, sizeof memo);
		for (int node = 1; node <= n; node++) {
			ans[node] = dfs(node, 0);
			mn = min(mn, ans[node]);
			mx = max(mx, ans[node]);
		}
		printf("Best Roots  : ");
		for (int node = 1; node <= n; node++) {
			if (ans[node] == mn)
				printf("%d ", node);

		}
		printf("\nWorst Roots : ");
		for (int node = 1; node <= n; node++) {
			if (ans[node] == mx)
				printf("%d ", node);

		}
			printf("\n");
	}
}




