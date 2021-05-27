
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
 
class Solution{
    public:
        long long sumUnderModulo(long long a,long long b)
    {
        long long mod=pow(10,9)+7;
        long long sum=((a%mod)+(b%mod))%mod;
        return sum;
    }
};

// { Driver Code Starts.
int main() {
	int T;
	cin>>T;
	while(T--)
	{
	    long long a;
	    long long b;
	    cin>>a>>b;
	    Solution ob;
	    cout<<ob.sumUnderModulo(a,b)<<endl;
	}
	return 0;
}
