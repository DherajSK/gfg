#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    unordered_map<int,int>presum;
    int sum=0;
    int maxlen=0;
    
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(A[i]==0 && maxlen==0)
            maxlen=1;
        if(sum==0)
            maxlen=i+1;
            
        if(presum.find(sum)!=presum.end())
            maxlen=max(maxlen,i-presum[sum]);
        else
            presum[sum]=i;
    }
    return maxlen;
}
