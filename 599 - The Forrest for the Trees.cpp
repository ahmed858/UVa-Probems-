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
#define MAX					1000005
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
// up down right left  topright topleft bottomright bottomleft
int dx[] = { -1,1,0,0 - 1,-1,1,1 };
int dy[] = { 0,0,1,-1 ,1,-1,1,-1 };
void fast() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }
bool valid(int i, int j) {
	int n = 0, m = 0;
	return i < n&& i >= 0 && j < m&& j >= 0;
}
int vis[26], cnt = 0;
vector<vector<int>> adj;
void dfs(int node) {
	if (vis[node])return;

	vis[node] = true; 
	cnt++;
	for (int i = 0; i < sz(adj[node]); i++)
	
		dfs(adj[node][i]);
	
}

int main()
{
	fast();
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		adj = vector<vector<int>>(26);
		memset(vis, 0, sizeof vis);
		while (getline(cin, s), s[0] != '*') {
		adj[s[1]-'A'].push_back( s[3]-'A');
		adj[s[3]-'A'].push_back( s[1] -'A');
		}
			
		//cin.ignore();
		getline(cin, s);
		int acorns = 0, trees = 0;
		for (int i = 0; i < sz(s); i++)
		{
			if (s[i] != ',' &&!vis[s[i]-'A']) {
				cnt = 0;
				dfs(s[i] - 'A');
				if (cnt == 1)acorns++;
				else trees++;
			}
		}
		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);

	}
}


