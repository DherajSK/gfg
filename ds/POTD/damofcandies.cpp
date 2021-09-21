
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    
    public:
    int maxCandy(int height[], int n) 
    { 

        int start=0;
        int end=n-1;
        int result=0;
        while(start<end)
        {
            int temp=(end-start-1)*min(height[start],height[end]);
            result=max(result,temp);
            
            if(height[start]<height[end])
                start++;
            else
                end--;
            
        }
        return result;
    }   
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int height[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>height[i];
    	}
    	
    	Solution obj;
    	
    	cout << obj.maxCandy(height,n)<<"\n";
    }
    return 0;
}
