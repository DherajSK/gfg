#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int,int> map;
        int count=0;
        vector<int>ans;
        for(int i=0;i<k;i++)
        {
            if(map[A[i]]==0)
                count++;
                map[A[i]]++;
        }
        ans.push_back(count);
        
        for(int i=k;i<n;i++)
        {
            if(map[A[i-k]]==1)
                count--;
                
            map[A[i-k]]-=1;
            
            if(map[A[i]]==0)
                count++;
            map[A[i]]+=1;
            
            ans.push_back(count);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
