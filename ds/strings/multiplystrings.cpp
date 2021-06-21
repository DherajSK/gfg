#include<bits/stdc++.h>
using namespace std;
 

 // } Driver Code Ends
class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
        bool neg;
        if((s1.at(0)=='-'||s2.at(0)=='-')&&(s1.at(0)!='-'||s2.at(0)!='-'))
            neg=true;
        if(s1.at(0)=='-')
            s1=s1.substr(1);
        if(s2.at(0)=='-')
            s2=s2.substr(1);
        int n1=s1.length();
        int n2=s2.length();
        vector<int> ans(n1+n2,0);
       
        int a=0;
        int b=0;
        for(int i=n1-1;i>=0;i--)
        {
            int carry=0;
            int dig1=s1[i]-'0';
           
            b=0;
            for(int j=n2-1;j>=0;j--)
            {
                int dig2=s2[j]-'0';
                int sum=(dig1*dig2)+ans[a+b]+carry;
                carry=sum/10;
                ans[a+b]=sum%10;
                b++;
            }
            if(carry>0)
                ans[a+b]+=carry;
            a++;
        }
        int i=ans.size()-1;
        while(i>=0 && ans[i]==0)
            i--;
        if(i==-1)
            return "0";
            
        string s="";
        while(i>=0)
            s+=to_string(ans[i--]);
       return neg?"-"+s:s;
    }

};

// { Driver Code Starts.
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
