#include <bits/stdc++.h>
using namespace std;
// Đồ thị cho dưới dạng ma trận kề
const int maxn = 1e4;
int n , s;
vector<int> v;
set<int> adj[maxn];
int a[maxn][maxn];
int degree[maxn];
bool checked(){
	int odd = 0;
	for (int i = 1 ; i <= n ; i++){
		int cnt = 0;
		for (int j = 1 ; j <= n ; j++)
			cnt += a[i][j];
		if (cnt % 2 == 1)
			++odd;
	}
	if(odd == 2) return 2;
	else if(!odd) return 1;
	return 0;
}

void euler1(int v){
	stack<int> st;
	vector<int> EC;
	st.push(v);
	while (!st.empty()){
		int x = st.top();
		if (adj[x].size() != 0){
			int y = *adj[x].begin();
			st.push(y);
			adj[x].erase(y);
			adj[y].erase(x);
		}else {
			st.pop();
			EC.push_back(x);
		}
	}
	reverse(EC.begin() , EC.end());
	for(int val : EC)
		cout << val << " ";
	cout << endl;
}

void euler2(){
	for (int k = 1 ; k <= n ; k++){
		if (degree[k] % 2 == 1)
			v.push_back(k);
	}
	int i = *v.begin();
	euler1(i);
}
void solve(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			cin >> a[i][j];
			if (a[i][j]){
				degree[i]++;
				degree[j]++;
				adj[i].insert(j);
				adj[j].insert(i);
			}
		}
	}
	if (checked() == 1) euler1(1);
	else if (checked() == 2) euler2();
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
/*
Input : 
10 
0 1 0 0 0 0 0 1 0 1
1 0 1 1 0 1 0 0 0 0 
0 1 0 1 0 0 0 0 0 0
0 1 1 0 0 1 0 1 0 0
0 0 0 0 0 1 1 1 1 1
0 1 0 1 1 0 1 0 0 0 
0 0 0 0 1 1 0 1 1 0
1 0 0 1 1 0 1 0 0 0
0 0 0 0 1 0 1 0 0 0
1 0 0 0 1 0 0 0 0 0
Ouput :
1 2 3 4 2 6 4 8 1 10 5 6 7 5 8 7 9 5
*/