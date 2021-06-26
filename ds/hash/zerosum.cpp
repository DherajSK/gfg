
#include<bits/stdc++.h>
using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map <int,int>presum;
        ll currsum=0;
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            currsum+=arr[i];

            if(currsum==0)
                ans++;
            if(presum.find(currsum)!=presum.end())
                ans+=presum[currsum];
            presum[currsum]++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
} 
