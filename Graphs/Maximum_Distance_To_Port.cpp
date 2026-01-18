#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int src,vector<int>&dist,vector<vector<int>>&edges,vector<bool>&vis){
	vis[src]=true;
	dist[src]=0;
	
	queue<pair<int,int>>qu;
	qu.push(make_pair(0,0));
	
	while(!qu.empty()){
		auto Node = qu.front();
		qu.pop();
		int node = Node.first;
		int d = Node.second;
		dist[node]=d;
		for(const auto &it:edges[node]){
			if(!vis[it]){
				vis[it]=true;
				qu.push(make_pair(it,d+1));
			}
		}
	}
	
	return;
}

int main(){
	
	
	int n,m,k;
	cin>>n>>m>>k;
	
	vector<vector<int>>edges(n,vector<int>());
	vector<int> prod (n);
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		x--;
		prod[i]=x;
	}
	
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	vector<int>dist(n,0);
	vector<bool>vis(n,false);
	int src = 0;
	bfs(src,dist,edges,vis);
	
	vector<int>ans(k,-1e9);
	
	vector<vector<int>>x(k,vector<int>());
	
	for(int i=0;i<n;i++){
		x[prod[i]].push_back(i);
	}
	
	for(int i=0;i<k;i++){
		for(const auto &it:x[i]){
			ans[i] = max(ans[i],dist[it]);
		}
	}
	
	
	for(const auto &it:ans){
		cout<<it<<" ";
	}
	
	return 0;
}
