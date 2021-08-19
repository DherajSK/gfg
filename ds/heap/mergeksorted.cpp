
#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
typedef pair<int,pair<int,int>>pq;

class Solution
{
    
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<pq,vector<pq>,greater<pq>> minheap;
        vector <int> ans;
        for(int i=0;i<K;i++)
            minheap.push(make_pair(arr[i][0],make_pair(i,0)));
        

        while(!minheap.empty())
        {
            pq curr=minheap.top();
            minheap.pop();
            ans.push_back(curr.first);
            int arridx=curr.second.first;
            int idx=curr.second.second;
            if(idx<K-1)
                minheap.push(make_pair(arr[arridx][idx+1],make_pair(arridx,idx+1)));
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}
