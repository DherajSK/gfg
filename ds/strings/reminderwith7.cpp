#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int remainderWith7(string n)
    {
        int series[]={1,3,2,-1,-3,-2};
        int res=0,idx=0;
        for(int i = n.length()-1;i>=0;i--)
        {
            res+=series[idx]*(n[i]-'0');
            idx=(idx+1)%6;
            res%=7;
        }
        if(res<0)
            return (res+7)%7;
        return res%7;
    }
};

// { Driver Code Starts.
int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
    string n;
    cin>>n;
    Solution ob;
    cout<<ob.remainderWith7(n)<<endl;
    
    }
	return 0;
} 
