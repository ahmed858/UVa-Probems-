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
// up down right left  topright topleft bottonright bottonleft
int dx[] = { -1,1,0,0 - 1,-1,1,1 };
int dy[] = { 0,0,1,-1 ,1,-1,1,-1 };
void fast() { ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); }



bool valid(int i, int j) {
	int n = 0, m = 0;
	return i < n&& i >= 0 && j < m&& j >= 0;
}


int main()
{
	//fast();
	int n, m;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		int k, v;
		vector<vector<int>>adj(MAX);
		for (int i = 1; i <= n; i++)
			scanf("%d",&v), adj[v].push_back(i);
		while (m--)
		{
			scanf("%d %d", &k, &v);
			if (k - 1 < adj[v].size())
				printf("%d", adj[v][k - 1]);
			else printf("0\n");
		}
	}
}


