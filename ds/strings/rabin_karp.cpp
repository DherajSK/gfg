#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int m=pat.length();
            int n=txt.length();
            int i,j;
            int q=101;
            int p=0,t=0,h=1,d=256;
            vector <int> ans;
            for(i=0;i<m-1;i++)
                h=(h*d)%q;
            for(i=0;i<m;i++)
            {
                p=(p*d + pat[i])%q;
                t=(t*d + txt[i])%q;
            }
            for(i=0;i<=n-m;i++)
            {
                if(p==t)
                {
                    for(j=0;j<m;j++)
                        if(pat[j]!=txt[i+j])
                            break;
                            
                    if(j==m)
                        ans.push_back(i+1);     
                }
                
                if(i<n-m)
                {
                    t=(d*(t-txt[i]*h) + txt[i+m])%q;
                    if(t<0)
                        t+=q;
                }
            }
            if (ans.empty())
                ans.push_back(-1);
            return ans;
        }
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
