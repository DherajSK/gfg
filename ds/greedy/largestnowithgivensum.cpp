// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
        if(sum>n*9)
            return "-1";
        string ans="";
        int i=0;
        int total=0;
        for(i=0;i<n;i++)
        {
            if(total+9<sum)
            {
                total+=9;
                ans+="9";
            }
                
            else 
            {
                ans+=to_string(sum-total);
                total+=(sum-total);
                break;
            }
        }
        i++;
        for(;i<n;i++)
        {
            ans+="0";
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
} 
