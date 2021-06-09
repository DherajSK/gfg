#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{   
    public:
    //Function to add two matrices.
    vector<vector<int> > sumMatrix( const vector<vector<int> >& A, const vector<vector<int> >& B)
    {
        vector<vector<int>>C;
        int n1,m1,n2,m2,t;
        n1=A.size();
        m1=A[0].size();
        n2=B.size();
        m2=B[0].size();
        if(n1!=n2 || m1!=m2)
            return C;
        for(int i=0;i<n1;i++)
        {
            vector<int>v;
            for(int j=0;j<m1;j++)
            {
                t=A[i][j]+B[i][j];
                v.push_back(t);
            }
            C.push_back(v);
        }
        return C;
            
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > A(row); 
        for(int i=0; i<row; i++)
        {
            A[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>A[i][j];
            }
        }
        cin>> row>> col;
        vector<vector<int> > B(row);
        for(int i=0; i<row; i++)
        {
            B[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>B[i][j];
            }
        }
        Solution ob;
        vector<vector<int> > result = ob.sumMatrix(A,B);
        if(result.size() == 0)
            cout<<"-1";
        else
        {
            for (int i = 0; i < result.size(); ++i)
            {
                for (int j = 0; j < result[0].size(); ++j)
                {
                    cout<<result[i][j]<<" ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
