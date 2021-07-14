#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack <char> s;
        for(int i=0;i<x.length();i++)
        {
            char c=x[i];
            if(c=='{' || c=='(' || c=='[')
                s.push(c);
            else
            {
                if(s.empty())
                    return false;
                char ch=s.top();
                s.pop();
                if(x[i]=='}' && ch !='{')
                    return false;
                else if( x[i]==')' && ch !='(')
                    return false;
                else if( x[i]==']' && ch !='[')
                    return false;
            }
        }
        if(s.empty())
            return true;
        return false;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
} 
