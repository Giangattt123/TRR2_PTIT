#include <bits/stdc++.h>
using namespace std;
// Thuật toán tìm đường đi ngắn nhất giữa 2 đỉnh bất kì sử dụng Dijikstra
// Tìm đường đi ngắn nhất từ 1 đỉnh đến các đỉnh còn lại
// d[v] : khoảng cách đường đi ngắn nhất từ đỉnh u đến đỉnh v
// Sử dụng : d[v] = min(d[v] , d(u , v))
#define pa pair<int , int>
const int maxW = 1e9;
const int maxn = 1e4;
int n , m , u , v , w , a[maxn][maxn];
vector<pair<int, int>> adj[maxn];
int d[maxn];
void input(){
	cin >> n;
	for (int i = 1 ; i <= n ; i++){
		for (int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
			if (a[i][j] != 0 && a[i][j] != maxW){
				adj[i].push_back({j , a[i][j]});
				adj[j].push_back({i , a[i][j]});
			}
		}
	}
}
void Dijkstra(int s){
	for(int i = 1 ; i <= n ; i++)
		d[i] = maxW;
	d[s] = 0;
	priority_queue<pa , vector<pa> , greater<pa>>  Q;
	Q.push({0 , s});
	while(!Q.empty()){
		pa top = Q.top();
		Q.pop();
		int len = top.first;
		int u = top.second;
		if (len > d[u]) continue;
		for (pa it : adj[u]){
			int w = it.second;
			int v = it.first;
			if (d[v] > d[u] + w){
				d[v] = d[u] + w;
				Q.push({d[v] , v});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	input();
	cin >> u >> v;
	Dijkstra(u);
	cout << d[v] << endl;
}
