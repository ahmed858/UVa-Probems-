#include<iostream>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cstdio>
#define	    Ninja				ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define		ll					long long 
#define     pii					pair<int,int>
#define     vii					vector<pair<int,int>>
#define     vi					vector<int>
#define     vb					vector<bool>

using namespace std;
int n,E,u,v;

bool bip(int source,vector<vb>edg, vi color)
{
	queue<int>Q;
	color[source] = 1;
	Q.push(source);
	while (!Q.empty())
	{
		int node = Q.front();
		Q.pop();
		for (size_t i = 0; i < n; i++)
		{
			if (edg[node][i] && color[i] == -1)
			{
				color[i] = 1 - color[node];
				Q.push(i);
			}
			else if (edg[node][i] && color[i] == color[node])
				return false;

		}
	}
	return true;

}
int main()
{
	while (cin >> n)
	{
		if (!n)break;
		vector<vb>adj(2001,vb(201,0));
		vi Color(201, -1);
		cin >> E;
		while (E--)
		{
			cin >> u >> v;
			adj[u][v] = 1;
			adj[v][u] = 1;

		}
		if (!bip(0, adj, Color))
			cout << "NOT BICOLORABLE.\n";
		else cout << "BICOLORABLE.\n";
	}

}
/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
*/
