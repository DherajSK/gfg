#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    void fillStack(int i, vector<int>adj[], bool visited[],stack <int> &s)
    {
        visited[i]=true;
        for(auto it:adj[i])
            if(!visited[it])
                fillStack(it, adj, visited, s);
                
        s.push(i);
    }
    void getTranspose(vector<int>adj[],int V,vector<int> revadj[])
    {
        for(int i=0;i<V;i++)
            for(auto u:adj[i])
                revadj[u].push_back(i);
                
    }
	public:
	//Function to find number of strongly connected components in the graph.
	void dfsUtil(int v, vector<int> revadj[], bool visited[])
	{
	    visited[v]=true;
	    
	    for(auto it:revadj[v])
	        if(!visited[it])
	            dfsUtil(it,revadj,visited);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        bool visited[V]={false};
        stack <int> s;
        
        for(int i=0;i<V;i++)
            if(!visited[i])
                fillStack(i, adj,visited, s);
        
        vector<int> revadj[V];        
        getTranspose(adj,V,revadj);
        
        for(int i=0;i<V;i++)
            visited[i]=false;
        
        int ans=0;
        
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(!visited[top])
            {
                dfsUtil(top,revadj,visited);
                ans++;
            }
            
        }
            
        return ans;        
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
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}
