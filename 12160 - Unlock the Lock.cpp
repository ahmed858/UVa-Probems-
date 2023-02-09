#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<iostream>
#include<vector>
#include<math.h>
#include<string>
#include<sstream>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>
#include<unordered_set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;
#define all(x) x.begin(), x.end()
#define endl '\n'
#define sz(x) x.size()
#define clr(x,v)  memset(x,v,sizeof x);
typedef  long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif

}

const int N = 1e5 + 5, MOD = 1e9 + 7;


vector<int >v;
int  src, trg;
int m;
int dis[N];
void BFS() {
	clr(dis, -1);
	queue<int>q;
	dis[src] = 0;
	q.push(src);

	while (q.size())
	{
		int u = q.front();
		q.pop();

		for (int i = 0; i < m; i++) {
			int  newnum = v[i] + u;
			if (newnum >= 10000)
				newnum -= 10000;

			if (dis[newnum] == -1) {
				dis[newnum] = dis[u] + 1;
				q.push(newnum);
			}
		}
	}
	
}
int main()

{
	fast();
	int c = 1;
	while (cin >> src >> trg >> m)
	{
		if (!m && !src && !trg) {
			break;
		}

		v.clear(); 
		v.resize(m);

		for (int i = 0; i < m; i++) {
			cin >> v[i];
		}
		BFS();
		cout << "Case " << c++ << ": ";
		if (dis[trg] != -1)
			cout << dis[trg] << endl;

		else cout<< "Permanently Locked\n";


	}

}
