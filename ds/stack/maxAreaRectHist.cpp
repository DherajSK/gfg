#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        stack <long long> s;
        long long i=0;
        long long tp,area,maxarea=0;
        while(i<n)
        {
            if(s.empty()||arr[i]>=arr[s.top()])
                s.push(i++);
                
            else
            {
                tp=s.top();
                s.pop();
                area=arr[tp]*(s.empty()?i:i-1-s.top());
                
                maxarea=maxarea<area?area:maxarea;
            }
        }
        while(!s.empty())
        {
            tp=s.top();
            s.pop();
            area=arr[tp]*(s.empty()?i:i-1-s.top());
                
            maxarea=maxarea<area?area:maxarea;
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
