
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    string ExcelColumn(int N)
    {
        string result="";
        int rem;
        while(N>0)
        {
            rem=N%26;
            if(rem==0)
            {
                result+="Z";
                N=(N/26)-1;
            }
            else
            {
                result+=(rem-1)+'A';
                N=N/26;
            }
        }
        reverse(result.begin(),result.end());
        return result;
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
        cin>>n;
        Solution ob;
        cout<<ob.ExcelColumn(n)<<endl;
    }
    return 0;
}
