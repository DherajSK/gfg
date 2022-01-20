#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution{
public:
    long long fact(long long n , vector<long long> &dp){
              if(dp[n]!=-1) return dp[n];
           
            return dp[n] = (n*fact(n-1, dp))%1000000007;        
            
            
            
    }
    vector<long long> factorial(vector<long long> a, int n) {
        vector<long long> dp(1000009, -1);
        dp[0]=dp[1] = 1;
        long long m = fact(100009, dp);
        vector<long long> v(a.size());
        for(int i = 0; i<a.size(); i++){
          v[i] = dp[a[i]];
        }
        
        return v;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
