
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        int len=S.length();
        stack <int> st;
        for(int i=0;i<len;i++)
        {
            if(S[i]>='0' && S[i]<='9')
                st.push(S[i]-'0');
            else
            {
                int n1=st.top();
                st.pop();
                int n2=st.top();
                st.pop();
                switch(S[i])
                {
                    case '*':st.push(n1*n2);
                        break;
                    case '+':st.push(n1+n2);
                        break;
                    case '-':st.push(n2-n1);
                        break;
                    case '/':st.push(n2/n1);
                        break;
                }
            }
        }
        return st.top();
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
