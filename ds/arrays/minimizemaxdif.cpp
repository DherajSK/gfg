
#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int minimizedMaxDiff(int arr[], int n, int k);

int main()
{
    int arr[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> arr[i];
        
        int k;
        cin>>k;
        
        cout<< minimizedMaxDiff(arr,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends


//User function Template for C++

int minimizedMaxDiff(int arr[], int n, int k)
{
    int max_adj_diff=INT_MIN;
    for(int i=0;i<n-1;i++)
        max_adj_diff=max(abs(arr[i]-arr[i+1]),max_adj_diff);
        
    int best=1;
    int worst=max_adj_diff;
    int mid,required;
    while(best<worst)
    {
        mid=(worst+best)/2;
        required=0;
        
        for(int i=0;i<n-1;i++)
            required+=(abs(arr[i]-arr[i+1])-1)/mid;
        
        if(required>k)
            best=mid+1;
            
        else
            worst=mid;
    }
    return worst;
}
