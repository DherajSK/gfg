
#include <bits/stdc++.h> 
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    int candies(int m, int n) 
    { 
    	return ((m-1)*(n-1))/2;
    	
    } 
};

// { Driver Code Starts.
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		Solution obj;
		cout << obj.candies(m,n)<<endl; 
	}
	return 0; 
} 
