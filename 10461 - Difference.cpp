// 10461 - Difference 


#include <bits/stdc++.h>

#define NinjaTurtle                   \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define outfile freopen(".txt", "w", stdout);
#define infile freopen(".txt", "r", stdin);
#define test  \
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

using namespace std;
const int N = 2 * 1e5;

bool valid(int i, int j)
{
    int n = 8, m = 8;
    return i < n && i >= 0 && j < m && j >= 0;
}
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxK[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dyK[] = {2, -2, 2, -2, 1, -1, 1, -1};

int main()
{
    NinjaTurtle
        // freopen ("input.txt","r",stdin);
        // freopen ("output.txt","w",stdout);

        int c = 1;
    int n, m, q, x, u, v;
    while (cin >> n >> m)
    {
        if (!n && !m)
            break;

        vector<int> val(n+1);
        for (int i = 1; i <= n; i++)
            cin >> val[i];
        vector<int> org[600];
        vector<int> rev[600];
        while (m--)
        {
            cin >> u >> v;
            org[u].push_back(v);
            rev[v].push_back(u);
        }

        cout << "Case #" + to_string(c++) + ":\n";
        cin>>q;
        while (q--)
        {
            cin >> x;

            queue<int> q;
            bool vis[505];
            memset(vis, 0, sizeof vis);

            

            // easy peazy BFS
            q.push(x);
            vis[x] = true;
            int mn = 0;
            while (q.size())
            {
                u = q.front();
                q.pop();

                for (int i = 0; i < org[u].size(); i++)
                {
                    v = org[u][i];
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                        mn += val[v];
                    }
                }
            }

            // reversed BFS
            int mx = 0;
            q.push(x);
            memset(vis, 0, sizeof vis);
            vis[x]= 1;

            while (q.size())
            {
                u = q.front();
                q.pop();

                for (int i = 0; i < rev[u].size(); i++)
                {
                    v = rev[u][i];
                    if (!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (!vis   [i])
                    mx += val[i];
            }
            
            cout << abs(mx - mn) << endl;
        }
        cout<<"\n";
    }
}
