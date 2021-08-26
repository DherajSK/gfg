#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclicUtil(int v, bool visited[], bool recstack[],vector<int> adj[])
	{
	    if(!visited[v])
	    {
	        visited[v]=true;
	        recstack[v]=true;
	        for(auto it=adj[v].begin();it!=adj[v].end();it++)
	        {
	            if(!visited[*it] && isCyclicUtil(*it,visited,recstack,adj))
	                return true;
	            else if(recstack[*it])
	                return true;
	        }
	    }
	    recstack[v]=false;
	    return false;
	}
	
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	bool visited[V]={false};
	   	bool recstack[V]={false};
	   	
	   	for(int i =0;i<V;i++)
	   	    if(isCyclicUtil(i,visited,recstack,adj))
	   	        return true;
	   	return false;
	}
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
