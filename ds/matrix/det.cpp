#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



class Solution
{  
    
    public:
    //Function for finding determinant of matrix.
    vector<vector<int> > findCofactor(int n,vector<vector<int> > mat,int p,int q)
    {
        vector<vector<int> >temp;
        int j=0;
        vector<int> a;
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(row!=p && col!=q)
                {
                    //temp[i][j++]=mat[row][col];
                    j++;
                    a.push_back(mat[row][col]);
                    if(j==n-1)
                    {
                        temp.push_back(a);
                        j=0;
                        a.clear();
                    }
                }
            }
        }
        return temp;
    }
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        int d=0;
        if(n==1)
            return matrix[0][0];
        vector<vector<int> >temp;
        int sign=1;
        for(int k=0;k<n;k++)
        {
            temp=findCofactor(n,matrix,0,k);
            d+=sign*matrix[0][k]*determinantOfMatrix(temp,n-1);
            sign=-sign;
        }
        return d; 
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
} 
