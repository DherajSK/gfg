#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int N){
        vector<int>ans;
        ans.push_back(1);
        int product=1;
        for(int i=2;i<=N;i++)
        {
            int carry=0;
            for(int j=0;j<ans.size();j++)
            {
                int product=ans[j]*i + carry;
                ans[j]=product%10;
                carry=product/10;
            }
            while(carry)
            {
                ans.push_back(carry%10);
                carry=carry/10;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
} 
