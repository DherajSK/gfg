
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
// User function template for C++

// A[] : the input array of positive integers
// N : size of the array arr[]
// X : the required sum
class Solution
{
    public:
    bool keypair(vector<int> A, int N, int X)
    {
        unordered_set<int> s;
        for(int i=0;i<N;i++)
        {
            int temp=X-A[i];
            
            if(s.find(temp)!=s.end())
                return true;
            
            s.insert(A[i]);
        }
        return false;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> array(n);
        Solution ob;
        
        for (int i = 0; i < n; i++) cin >> array[i];
            cout << (ob.keypair(array, n, x) ? "Yes" : "No") << "\n";
    }
    return 0;
}
