#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        char* word=strtok(&S[0],".");
        string ans="";
        while(word!=NULL)
        {
            ans=word+ans;
            word=strtok(NULL,".");
            ans='.'+ans;
        }
        ans.erase(ans.begin());
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
