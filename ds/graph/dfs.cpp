#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	void DFSUtil(int v, bool visited[], vector<int> adj[],vector<int> &res)
	{
	    visited[v]=true;
	    res.push_back(v);
	    for(int it:adj[v])
	    {
	        if(!visited[it])
	            DFSUtil(it,visited,adj,res);
	    }
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    bool visited[V]={false};

	    vector<int> res;
	    DFSUtil(0,visited,adj,res);
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
} 
