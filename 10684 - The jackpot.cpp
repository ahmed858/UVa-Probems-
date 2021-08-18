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
const double EPS = 1e-10, pi = 3.14159265;
int dx[] { 1, 0, 0, -1, 1, 1, -1, -1 };
int dy[] { 0, 1, -1, 0, 1, -1, 1, -1 };
char dir[]= {'D','R','U','L'};
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
const ll  N = 1e3+1, M = 501, mod =(1<<30), INF = 1e18, length = 25;
void dijkstra(int src,vector<vector<pair<int,ll>>>&graph,vl& dis){
    // in graph <node,cost>
    //in prio <cost,node>
    priority_queue<pair<ll,int>>Q;
    dis=vl(sz(graph),1e18);
    dis[src]=0;
    Q.push({0,src});
    while(sz(Q)){
        ll c= -Q.top().first;
        int u=Q.top().second;
        Q.pop();
        if(dis[u]!=c)continue;

        for(pair<int,ll> child:graph[u]){
            ll cc=child.second+c;
            int v=child.first;
            if(cc<dis[v]){
                dis[v]=cc;
                Q.push({-cc,v});

            }
        }
    }

}

int main()
{

    fast();
    int n;
    while(cin>>n,n){
        int mx=0,sum=0;
        while(n--){
            int x;
            cin>>x;
            mx=max(mx,sum+=x);
            if(sum<0)sum=0;

        }
        if(mx)
            cout<<"The maximum winning streak is "<<mx<<".\n";
        else cout<<"Losing streak.\n";
    }
}
/*
 * don't be lazy in thinking ya 3l2
 * Think twice, code once
 * Think of different approaches to tackle a problem: write them down.
 * Think of different views of the problem. don't look from only one side.
 * don't get stuck in one approach.
 * common mistakes: over_flow
 *                  - out_of_bound index
 *                  -infinite loop
 *                  -corner cases
 *                  -double counting.
 //	Always think of patterns (LCM, GCD)
//	Be careful of unsigned
//	Think of a solution that gets TLE and optimize it
//	Use binary search
//	Solve on paper first
//	Reverse Thinking
//	Monotonic stack/dequeue
//	EV is computed using probabilities or number of ways
//	E(X + Y) = E(X) + E(Y)
//	E(X * Y) = E(X) * E(Y)
//	If there's an equation, transform it into an easy one
//	Try not to use doubles
//	Don't do DP in graphs on anything rather than DAGs
//	Don't use the fucking "double"
//	READ ALL PROBLEMS
 */
