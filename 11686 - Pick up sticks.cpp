/*
wrong anser but im do not know why??????????

topogical sort idea like that:  
https://github.com/lamphanviet/competitive-programming/blob/master/uva-online-judge/accepted-solutions/11686%20-%20Pick%20up%20sticks.cpp
*/

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
#define MAX					100111
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

int Px, Py;

bool valid(int i, int j) {
int n = 9, m = 9;
return i < n && i >=0 && j < m && j >=0;
}
vector<vi> adj;
int n, m;
int color[ MAX];
vi ans;
bool flag = 1;
void topo(int node) {
    if (!flag)return;
    color[node] = 1;
    for (int child : adj[node]) {
        if (color[child] == 0) {
            topo(child);
        }
        else if(color[child]==1){
            flag = 0;
            return;
        }
    }
    ans.push_back(node);
    color[node] = 2;
}
int main()
{
    fast();

    while ((cin >> n >> m)) {
        if (!n && !m)
            return 0;
        adj = vector<vi>(MAX);
        memset(color, 0, sizeof color);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        flag = 1;
        ans = vi();
        for (int i = 1; i <= n && flag; i++) {
            if (!color[i])
                topo(i);
        }
        if (!flag)
            puts("IMPOSSIBLE");
        else {
            for (int i = ans.size() - 1; i >= 0; i--)
                cout << ans[i] << endl;
        }
    }
}
