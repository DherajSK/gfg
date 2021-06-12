#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends

/*You are required to complete this method*/

class Solution{
  public:
    int maxHist(int m, int arr[])
    {
        int i=0,tp;
        int ans=0,max=0;
        stack <int> s;
        while(i<m)
        {
            if(s.empty()||arr[s.top()]<=arr[i])
                s.push(i++);
            else
            {
                tp=s.top();
                s.pop();
                ans=arr[tp]*(s.empty()?i:i-s.top()-1);
                
                max=max>ans?max:ans;
            }
        }
        while(s.empty()==false)
        {
            tp=s.top();
            s.pop();
            ans=arr[tp]*(s.empty()?i:i-s.top()-1);
                
            max=max>ans?max:ans;
        }
        return max;
        
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int result=maxHist(m,M[0]);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
                if(M[i][j])
                    M[i][j]+=M[i-1][j];
            result=max(result,maxHist(m,M[i]));
        }
        return result;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
