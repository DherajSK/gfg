#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
// Function to print the k numbers with most occurrences 

class Solution
{
    public:
    //Function to return the sum of frequencies of k numbers
    //with most occurrences in an array.
    int kMostFrequent(int arr[], int n, int k) 
    { 
        unordered_map<int,int>mp;
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
        
        for(auto x:mp)
            maxheap.push(x.second);
      
        int ans=0;
        int i=0;
        while(!maxheap.empty() && i<k)
        {
            ans+=maxheap.top();
            maxheap.pop();
            i++;
        }
        return ans;
    }
    
};

// { Driver Code Starts.
// Driver program to test above 
int main() 
{
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.kMostFrequent(arr, n, k) << endl; 
    }

	return 0; 
}
