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
int dx[] { 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[] { 0, 1, -1, 0, 1, -1, 1, -1 };

//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
enum list { NOT_TAKE, TAKE };
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const ll  N =2e5+5, mod = 1e9 + 7, inf = 2e18, length = 25;
struct edge
{
    int a, b, cost;
};
int n, m;
vector<edge> e;
const int INF = 1e9;
void solve()
{
    vector<int> d (n,INF);
    int x;
    d[0] = 0;
    for (int i=0; i<n; ++i)
    {
        x = -1;
        for (int j=0; j<m; j++)
            if (d[e[j].b] > d[e[j].a] + e[j].cost){
                d[e[j].b] = d[e[j].a] + e[j].cost;
                x = e[j].b;
            }
    }
    
    if (x == -1)
        cout<<"not possible\n";
    else
        cout<<"possible\n";
}
int main()
{
    fast();
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        e=vector<edge>();
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            e.push_back({a,b,c});
        }
        solve();
    }

}
