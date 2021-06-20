#include <bits/stdc++.h>
using namespace std;




 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    // s is the given string
    int SubsequenceLength (string s) 
    {
        int n=s.length();
        int res=0;
        vector <int> lastindex(256,-1);
        int i=0;
        for(int j=0;j<n;j++)
        {
            i=max(i,lastindex[s[j]]+1);
            
            res=max(res,j-i+1);
            
            lastindex[s[j]]=j;
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    cin>>ws;
    while(t--)
    {
        string str;
        getline(cin,str);
        Solution obj;
        cout<<obj.SubsequenceLength(str)<<"\n";
    }
    return 0;
}
