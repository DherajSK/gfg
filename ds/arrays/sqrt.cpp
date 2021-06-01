
#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
    if(x==0||x==1)
        return x;
    long long int low=1, high=x, mid, ans;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid*mid==x)
            return mid;
        if(mid<=x/mid)
        {
            low=mid+1;
            ans=mid;
        }
        else
            high=mid-1;
    }
    return ans;
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
