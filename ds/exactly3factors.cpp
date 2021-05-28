
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool isprime(int a)
    {
        for(int i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)
                return false;
        }
        return true;
    }
    
    int exactly3Divisors(int N)
    {
        int count=1;
        if(N<=3)
            return 0;
    
        for(int i=3;i*i<=N;i++)
        {
            if(isprime(i))
                count++;
        }
        return count;
    }
};

// { Driver Code Starts.


int main()
 {
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling function exactly3Divisors()
        cout<<ob.exactly3Divisors(N)<<endl;
    }
	return 0;
} 
