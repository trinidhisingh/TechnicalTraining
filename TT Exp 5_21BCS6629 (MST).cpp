#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        int sum=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1)continue;
            sum+=wt;
            vis[node]=1;
            for(auto it:adj[node]){
                int v=it[0];
                int cst=it[1];
                if(!vis[v])pq.push({cst,v});
            }
        }
        return sum;
    }
};
int main()
{
int t;
cin >> t;

while ( t --) {
int V, E;
cin >> V >> E;

vector<vector<int>> adj[V];

int i = 0;
while (i++<E) {
int u, v, w;
cin >> u >>v >> w; 
vector<int>t1,t2;
t1.push_back(v); 
t1.push_back(w); 
adj [u].push_back(t1);
t2.push_back(u); 
t2.push_back(w); 
adj[v].push_back(t2);
}

Solution obj;
cout << obj.spanningTree(V, adj )<<"/n";
}
return 0;
}
