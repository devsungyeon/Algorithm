#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int main()
{
	int V, E;
	scanf("%d %d", &V, &E);
	int start;
	scanf("%d", &start);
	vector<pair<int,int>> arr[V+1];

	for(int i = 0 ; i< E; i++) {
		int from, to, val;
		scanf("%d %d %d", &from, &to, &val);
		arr[from].push_back({to, val});
	}
	
	int dist[V+1];
	fill(dist, dist+V+1, INF);
	priority_queue<pair<int,int>> qu;

	qu.push({0, start});
	dist[start]=0;

	while(!qu.empty()) {
		int cost=-qu.top().first;
		int here=qu.top().second;

		qu.pop();

		for(int i=0; i<arr[here].size(); i++){
			int next = arr[here][i].first;
			int nextcost=arr[here][i].second;

			if(dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				qu.push({-dist[next], next});
			}
		}
	}
	for (int i = 1; i<=V; i++ ){
		printf("%d\n", dist[i]);
	}
}
