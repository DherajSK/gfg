
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to find out the number of ways to use the coins to
    //sum up to a certain required value.
    long long numberOfWays(int coins[],int numberOfCoins,int value)
    {
        int i,j,x,y;
        int m=numberOfCoins;
        int n=value;
        int table[n+1][m];
        
        for(i=0;i<m;i++)
            table[0][i]=1;
            
        for(i=1;i<n+1;i++)
        {
            for(j=0;j<m;j++)
            {
                x=(i-coins[j]>=0)?table[i-coins[j]][j]:0;
                
                y=(j>=1)?table[i][j-1]:0;
                
                table[i][j]=x+y;
                
            }
        }
        return table[n][m-1];
    }
};

