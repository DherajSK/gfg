
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    bool checktree(int preorder[], int inorder[], int postorder[], int N) 
    { 
    	if(N==0)
    	    return true;
    	if(N==1)
    	    return(preorder[0]==inorder[0] && preorder[0]==postorder[0]);
    	        
    	int idx=-1,f=0;
    	for(int i=0;i<N;i++)
    	{
    	    if(inorder[i]==preorder[0])
    	    {
    	        idx=i;
    	        break;
    	    }
    	}
    	if(idx!=-1)
    	    for(int i=0;i<N;i++)
        	    if(preorder[0]==postorder[i])
            	{
            	    f=1;
            	    break;
            	}
    	if(idx==-1 || f==0)
    	return 0;
    	
    	int ret1=checktree(preorder+1,inorder,postorder,idx);
    	
    	int ret2=checktree(preorder+idx+1,inorder+idx+1,postorder+idx,N-idx-1);
    	
    	return ret1&&ret2;
    } 

};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 
