#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        int i=0,tp;
        long long ans,maxarea=0;
        
        stack<int> s;
        while(i<n)
        {
            if(s.empty()||arr[s.top()]<=arr[i])
                s.push(i++);
            else
            {
                tp=s.top();
                s.pop();
                ans=arr[tp]*(s.empty()? i:i-s.top()-1);
                
                maxarea=(maxarea>ans)?maxarea:ans;
            }
        }
         while(s.empty()==false)
            {
                tp=s.top();
                s.pop();
                ans=arr[tp]*(s.empty()? i:i-s.top()-1);
                
                maxarea=(maxarea>ans)?maxarea:ans;
            }
        return maxarea;
    }
};


// { Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
