#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b){
        
        int m=a.length();
        int n=b.length();
        if(m!=n)
            return false;
        int count1[256]={0};
        int count2[256]={0};
        int i;
        
        for(i=0;i<n;i<i++)
        {
            count1[a[i]]++;
            count2[b[i]]++;
        }
        for(int i=0;i<256;i++)
            if(count1[i]!=count2[i])
                return false;
        return true;
    }

};

// { Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}
