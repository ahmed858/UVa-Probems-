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
#define MAX					1e5
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

freopen("in.txt", "r", stdin);
freopen("out.txt", "w", stdout);
ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}

bool valid(int i, int j) {
int n = 9, m = 9;
return i < n && i >=0 && j <= m && j >=-1;
}
vector<vi> adj;
int n, m;
bool bipartiteDfs(int node, int color[]) {
    for (auto it : adj[node]) {
        if (color[it] == -1) {
            color[it] = 1 - color[node];
            if (!bipartiteDfs(it,  color)) {
                return false;
            }
        }
        else if (color[it] == color[node]) return false;
    }
    return true;
}
bool checkBipartite() {
    int color[205];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 1;
            if (!bipartiteDfs(i, color)) {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    fast();
    
    while (cin >> n) {
        if (!n)return 0;
        adj = vector<vi>(205);

        cin >> m;

        while (m--)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (checkBipartite()) {
            cout << "BICOLORABLE." << endl;
        }
        else
            cout << "NOT BICOLORABLE." << endl;

    }
}
	


