#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n==1)
            return 0;
        long long sum=0;
        priority_queue<long long,vector<long long>, greater<long long>> minheap;
        for(long long i=0;i<n;i++)
            minheap.push(arr[i]);
        while(minheap.size()>1)
        {
            long long num1=minheap.top();
            minheap.pop();
            long long num2=minheap.top();
            minheap.pop();
            sum+=num1+num2;
            minheap.push(num1+num2);
        }
        return sum;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
