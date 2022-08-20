#include <bits/stdc++.h>

#define outfile freopen(".txt", "w", stdout);
#define infile freopen(".txt", "r", stdin);
#define TEST  \
    int t;    \
    cin >> t; \
    while (t--)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define ll long long
#define endl "\n"
#define vi vector<int>
#define vl vector<ll>
#define vs vector<string>
#define vp vector<pair<int, int>>
#define Pb push_back
#define clr(v, d) memset(v, d, sizeof(v))
using namespace std;
void fast()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int fix_mod(int n, int k) // N%K
{
    return (n % k + k) % k;
}
int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

int dxKing[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dyKing[] = {2, -2, 2, -2, 1, -1, 1, -1};
const int N = 201, Mod = 1e9 + 7;
int n, m;
char arr[505][505];
bool vis[505][505];
char cur;
int cnt=0;
void solve(int i, int j)
{
    if (i >= n || j >= m || i < 0 || j < 0)
        return;
    if (vis[i][j] || cur != arr[i][j])
        return;

    vis[i][j] = 1;
    cnt++;
    solve(i, j + 1);
    solve(i + 1, j);
    solve(i - 1, j);
    solve(i, j - 1);
}
int main()
{
    fast();
    // freopen("transmitters.in", "r", stdin);
    //   solve();

    int t;
    cin >> t;
    int w=1;
    while (t--)
    {
        cin >> n >> m;
        vi frq(26);
        set<pair<int,char>>st;
        clr(vis,0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
         for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cnt=0;
              if(!vis[i][j]){
                cur=arr[i][j];
                solve(i,j);
                frq[arr[i][j]-'a']++;
              }
            }
        }
        for(int i=0;i<26;i++){
            if(frq[i])
                st.insert({-frq[i],'a'+i});

        }
        cout<<"World #"<<w++<<endl;
        for(auto it:st)
        cout<<it.second<<": "<<- it.first<<endl;   
    }
}
