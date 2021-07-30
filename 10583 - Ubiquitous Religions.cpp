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
    freopen("out.txt", "w", stdout);
#endif
}
const int  N = 50000+1,M=501, mod = 1e9 + 7, inf = 2e18, length = 25;
struct DSU {
    int parant[N];
    int rate[N];
    void init(int n) {
        iota(parant, parant + n+1, 0);
        fill(rate, rate + n, 1);
    }
    int find_leader (int u) {
        if (parant[u] == u)return u;
        return parant[u] = find_leader(parant[u]);
    }
    bool Union(int a,int b){
        a = find_leader(a);
        b = find_leader(b);
        if (a == b)return false;
        if (rate[a] < rate[b])
            swap(a, b);
        // a large always
        parant[b] = a;
        rate[a] += rate[b];
        return true;
    }
    bool same_set(int a, int b) {
        a = find_leader(a);
        b = find_leader(b);
        return (a == b);
    }

}dsu;
int main() {
    fast();
    int t=1;
    //cin >> t;
    int n, m;
    while(cin >> n >> m)
    {
        
        if (!n && !m)return 0;
        dsu.init(n);
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            //cout << u << " "<<v << endl;
            dsu.Union(u, v);
        }
        set<int>s;
        for (int i = 1; i <= n; i++) 
            s.emplace(dsu.find_leader(i));
        cout << "Case "<<t++<<": "<< s.size() << endl;

    }
}
