#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    bool isCycleUtil(int v, bool visited[], vector <int> adj[],int parent)
    {
            visited[v]=true;
            for(auto it=adj[v].begin();it!=adj[v].end();it++)
            {
                if(!visited[*it])
                {
                    if(isCycleUtil(*it,visited,adj,v))
                        return true;
                }
                else if(*it!=parent)
                    return true;
            }
            return false;
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V]={false};
	    for(int i=0;i<V;i++)
	        if(!visited[i])
	            if(isCycleUtil(i,visited,adj,-1))
	                return true;
	            
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
} 
