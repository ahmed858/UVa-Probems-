#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<string>
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
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
}
const ll  N = 1002, M = 501, mod = 1e9 + 7, INF = 1e18, length = 25;
struct DSU
{
    int perant[N],sizo[N];
    void init()
    {
        iota(perant,perant+N,0);
        fill(sizo,sizo+N,1);
    }
    int find(int u)
    {
        if(u==perant[u])return u;
        else
            return perant[u]=find(perant[u]);
    }

    bool merge(int a,int b)
    {
        a=find(a);
        b=find(b);
        if(a==b)return false;
        if(sizo[a]<sizo[b])
        {
            swap(a,b);
        }
        perant[a]=b;
        sizo[b]+=sizo[a];
        return true;
    }

} dsu;
struct edge
{
    int u,v;
    double dis;
    edge(int a,int b,double c):u(a),v(b),dis(c) {};

    const bool operator<(const edge&other)const
    {
        return dis<other.dis;
    }
};
vector<edge>ee;
double MST()
{
    sort(all(ee));
    dsu.init();
    double ans=0;
    for(int i=0;i<sz(ee);i++){
        if(dsu.merge(ee[i].u,ee[i].v)){
            ans+=ee[i].dis;
        }
    }
    return ans;
}
int main()
{
    fast();
    int n;
    while(cin>>n)
    {

        if(n==0)RT("");
        int X[N],Y[N];

        for(int i=0; i<n; i++)
            cin>>X[i]>>Y[i];
        ee=vector<edge>();

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int u=i,v=j;
                double d=hypot(X[i]-X[j],Y[i]-Y[j]);
                ee.push_back(edge(u,v,d));
            }
        }
        cout<<fixed<<setprecision(2)<< MST()<<endl;
    }
}
/*
0 2 3
7 5 4
1 2 8
1 1 1 1 1 1 1 1
*/

