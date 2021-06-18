#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        int m=s1.length();
        int n=s2.length();
        int lps[m];
        lps[0]=0;
        if(m!=n)
            return false;
        int len=0;
        int i=1;
        while(i<n)
        {
            if(s1[i]==s2[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else 
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    len=lps[len-1];
                }
            }
        }
        i=0;
        for(int k=lps[n-1];k<m;k++)
        {
            if(s2[k]!=s1[i++])
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}
