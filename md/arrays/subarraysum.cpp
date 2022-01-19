#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int low=0,i=1;
        int sum=arr[0];
        vector <int> ans;
        while(i<=n)
        {
            
            if(sum<s)
            {
                sum+=arr[i];
                i++;
            }
            else if(sum==s)
            {
                ans.push_back(low+1);
                ans.push_back(i);
                return ans;
            }
            else
            {
                sum=sum-arr[low];
                low++;
            }
            
        }
        ans.push_back(-1);
        return ans;
        // for(int i=1;i<=n;i++)
        // {
        //     if(sum<s)
        //         sum+=arr[i];
        //     if(sum==s)
        //     {
        //         ans.push_back(low+1);
        //         ans.push_back(i+1);
        //         return ans;
        //     }
        //     if(sum>s && low<i-1)
        //     {
        //         sum=sum-arr[low];
        //         low++;
        //     }
        // }
        // ans.push_back(-1);
        // return ans;
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
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
