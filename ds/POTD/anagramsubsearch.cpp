#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> v(26,0);int k=1;
	    for(int i=0;i<pat.size();i++){
	        v[pat[i]-'a']++;
	    }
	    vector<int> v1(26,0);int count=0;
	    for(int i=0;i<pat.size();i++){
	        v1[txt[i]-'a']++;
	    }
	    if(v==v1) count++;
	    v1[txt[0]-'a']--;
	    for(int i=pat.size();i<txt.size();i++){
	        v1[txt[i]-'a']++;
	        if(v==v1) count++;
	        v1[txt[k]-'a']--;
	        k++;
	    }
	    return count;
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
