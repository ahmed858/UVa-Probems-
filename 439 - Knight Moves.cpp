/*     pacman game problem */

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
#define MAX					100005
using namespace std;
const ll mod = 1e6;
const double EPS = 1e-10;
const double pi = 3.14159265358979323846;
const int Inf = 1e9;
//  down up right left  topright topleft bottomright bottomleft
int dx[] = { 1,-1,0,0 - 1,-1,1,1 };
int dy[] = { 0,0,-1,1 ,1,-1,1,-1 };
string dir[] = { "D","U","R","L" };
//TK
int DX[] = { 1,1,-1,-1,2,2,-2,-2 };
int DY[] = { 2,-2,2,-2,1,-1,1,-1 };
void fast() {
	//freopen("jumping.in", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
bool valid(int i, int j) {
	int n = 8, m = 8;
	return i < n&& i >= 0 && j < m && j >= 0;
}
int main()
{
	char s[2], t[2];
	while (scanf("%s %s",&s,&t)!=EOF)
	{
		pii start, goal;
		start.first = s[0] - 'a';
		start.second = s[1] - '1';
		goal.first = t[0] - 'a';
		goal.second = t[1] - '1';

	

		map<pii, int>dis;
		queue<pii>Q;
		Q.push(start);
		dis[start] = 0;
		while (!Q.empty())
		{
			pii cur = Q.front();
			Q.pop();
			if (cur == goal) {

				break;
			}
			int i = cur.first;
			int j = cur.second;
			if (!valid(i, j))
				continue;
			vector<pii>adj;
			for (int k = 0; k < 8; k++)
				adj.push_back({ i + DX[k] ,j + DY[k] });


			
			for (pii child : adj) {
				if (dis.find(child) == dis.end()) {
					dis[child] = dis[cur] + 1;
					Q.push(child);
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n",s,t, dis[goal]);
	}
	

}



