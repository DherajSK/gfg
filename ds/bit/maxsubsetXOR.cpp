#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int N)
    {
        int bits=32;
        int index=0;
        for(int i=bits-1;i>=0;i--)
        {
            int maxindex=index;
            int maxEle=INT_MIN;
            for(int j=index;j<N;j++)
            {
                if((arr[j]&(1<<i))!=0 && arr[j]>maxEle)
                {
                 maxEle=arr[j];
                 maxindex=j;
                }
            }
            if(maxEle==INT_MIN)
                continue;
            
            swap(arr[index],arr[maxindex]);
            maxindex=index;
            
            for(int j=0;j<N;j++)
            {
                if(j!=maxindex && (arr[j]&(1<<i))!=0)
                    arr[j]=arr[j]^arr[maxindex];
            }
            index++;
            
        }
        int res=0;
        for(int j=0;j<N;j++)
            res=res^arr[j];
        return res;
    }
};

// { Driver Code Starts.
int main()
{

    int t,n,a[100004],k;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n;
       scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        Solution obj;
        printf("%d\n",obj.maxSubarrayXOR(a,n));
       // cout<<bin(a,0,n-1,k)<<endl;
    }
}
