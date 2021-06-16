#include<bits/stdc++.h>
using namespace std;

int strstr(string ,string);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        string b;
        
        cin>>a;
        cin>>b;
        
        cout<<strstr(a,b)<<endl;
    }
}
// } Driver Code Ends




//Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x)
{
    int slen=s.length();
    int xlen=x.length();
    for(int i=0;i<=(slen-xlen);i++)
    {
        int j;
        for(j=0;j<xlen;j++)
            if(x[j]!=s[i+j])
                break;
        if(j==xlen)
            return i;
    }
    return -1;
}
