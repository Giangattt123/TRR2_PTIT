#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxN = 1e4;

int n , u;
int a[maxN][maxN];
vector<int> adj[maxN];
bool visited[maxN];
vector<pair<int , int>> Tree;

void input(){
	cin >> n >> u;
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
			if (a[i][j] == 1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	memset(visited , false , sizeof(visited));
}
void DFS(int u){
	visited[u] = true;
	for (int x : adj[u]){
		if (!visited[x]){
			Tree.push_back({min(x , u) , max(x , u)});
			DFS(x);
		}
	}
}
	

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	DFS(u);
	if (Tree.size() == n - 1){
		for (auto it : Tree){
			cout << it.first << " " << it.second << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
}
/*
6 1
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 1 0 0
0 1 1 0 1 1 
0 1 0 1 0 1
0 0 0 1 1 0
*/