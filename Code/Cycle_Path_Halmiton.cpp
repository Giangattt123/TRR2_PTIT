#include <bits/stdc++.h>
using namespace std;
// Tìm chu trình và đường đi Halmiton cho bởi ma trận kề
const int maxn = 1e4;
vector<int> adj[maxn];
int n , a[maxn][maxn];
bool visited[maxn];
int cycle[maxn] , deg[maxn];

void input(){
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
			if (a[i][j] == 1){
				deg[i]++; deg[j]++;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	memset(visited , false , sizeof(visited));
}

bool checked(){
	for(int i = 1 ; i <= n ; i++){
		if(deg[i] < n / 2)
			return false;
	}
	return true;
}
void Halmiton(int pos , int u){
	cycle[pos] = u;
	visited[u] = true;
	if (pos == n){
		vector<int>::iterator it = find(adj[u].begin() , adj[u].end() , cycle[1]);
		if(it != adj[u].end()){
			cycle[++pos] = cycle[1];
			for(int i = 1 ; i <= pos ; i++)
				cout << cycle[i] << " ";  
			cout << endl;
		}
		return;
	}
	for(int v : adj[u]){
		if(!visited[v]){
			Halmiton(pos + 1 , v);
			visited[v] = false;
		}
	}
	visited[u] = false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	if (checked())
		Halmiton(1 , 1);
	else
		cout << "Not found!!";
}
/*
Test m?u:
5 8
1 2
1 3
1 4
2 3
2 4
3 4
3 5
4 5
=> 4 halmiton_cycle: 
1 2 3 5 4 1
1 2 4 5 3 1
1 3 5 4 2 1
1 4 5 3 2 1
*/
