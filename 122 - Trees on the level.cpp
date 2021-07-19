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
#define MAX					266
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

struct Node{
	int value;
	Node* left;
	Node* right;
	Node() :value(-1), left(NULL), right(NULL) {};
};
Node* root;
bool faild;
int nodes=0,inputnodes=0;
string path = "";

void add_node(Node*root,int v,int i) {
	if (i == sz(path)) {
		if (root->value != -1)faild = true;
		root->value = v;
	}
	else if (path[i] == 'L') {
		if (root->left == NULL) {
			nodes++;
			Node* node = new Node;
			root->left = node;
			add_node(node, v, i + 1);
		}
		else
			add_node(root->left, v, i + 1);
	}
	else {
		if (root->right == NULL) {
			nodes++;
			Node* node = new Node;
			root->right = node;
			add_node(node, v, i + 1);
		}
		else
			add_node(root->right, v, i + 1);
		
	}
}
void remove_tree(Node* u) {
	if (u == NULL) return;
	remove_tree(u->left);
	remove_tree(u->right);
	delete u;
}
void bfs() {
	queue<Node*>Q;
	Q.push(root);
	vi ans;
	while (!Q.empty())
	{
		Node* node = Q.front(); Q.pop();
		ans.push_back(node->value);
		if (node->left != NULL)Q.push(node->left);
		if (node->right != NULL)Q.push(node->right);
	}
	for (int i = 0; i < (int)ans.size() - 1; i++)
		cout << ans[i] << " ";
	cout << ans[sz(ans) - 1] << endl;
}
void solve() {
	//cout << inputnodes << " " << nodes << endl;
	if (faild || inputnodes != nodes)
		cout << "not complete\n";
	else bfs();
}
void initialize() {
	remove_tree(root);
	root = new Node;
	nodes = 1;
	inputnodes = 0;
	faild = false;
}
int main() {
	fast();
	string s;
	initialize();
	while (cin>>s)
	{
		if (s == "()") {
			solve();
			initialize();
		} 
		else {
			inputnodes++;
			stringstream ss;
			for (int i = 0; i < s.size(); i++)
				if (s[i] == '(' || s[i] == ')' || s[i] == ',') s[i] = ' ';
			int val;
			ss << s;
			ss >> val;
			path = "";
			ss >> path;
			add_node(root,val,0);
		}
	}
}


/*
				COMMENT THE FILE FUNCTION !?!
*/
