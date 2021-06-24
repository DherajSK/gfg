
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        n++;
        int ans=n/2;
        int powerof2=2;
        int totalpairs;
        while(powerof2<=n)
        {
            totalpairs=n/powerof2;
            ans+=(totalpairs/2)*powerof2;
            ans+=(totalpairs%2)?n%powerof2:0;
            powerof2*=2;
        }
        return ans;
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
