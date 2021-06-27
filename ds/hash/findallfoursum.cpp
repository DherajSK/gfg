#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool compare(vector<int> a,vector<int>b)
    {
        if(a[0]!=b[0])
            return a[0]<b[0];
        else if(a[1]!=b[1])
            return a[1]<b[1];
        else if(a[2]!=b[2])
            return a[2]<b[2];
        else 
            return a[3]<b[3];
    }
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int l, r;
        
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n=arr.size();
    for (int i = 0; i < n - 3; i++)
        for (int j = i+1; j < n - 2; j++)
        {

            l = j + 1;
            r = n-1;
 
            while (l < r)
            {
                if( arr[i] + arr[j] + arr[l] + arr[r] == k)
                {
                    vector<int>temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[l]);
                    temp.push_back(arr[r]);
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);
                    l++; r--;
                }
                else if (arr[i] + arr[j] + arr[l] + arr[r] < k)
                    l++;
                else 
                    r--;
            }
        }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
