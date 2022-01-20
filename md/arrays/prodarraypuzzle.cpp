
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        int count=0;
        int pos;
        long long int prod=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
                prod*=nums[i];
            else 
            {   count++;
                pos=i;
                
            }
        }
        
        if(count==0)
        {
            vector<long long int>ans;
            for(int i=0;i<n;i++)
                    ans.push_back(prod/nums[i]);
            return ans;        
        }
        vector<long long int>ans(n,0);
        if(count==1)
            ans[pos]=prod;
        return ans;

    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
