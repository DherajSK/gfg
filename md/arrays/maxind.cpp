#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        int rightMax[n];
        rightMax[n-1]= arr[n-1];
        for(int i = n-2; i>=0; i--)
            rightMax[i] = max(rightMax[i+1] , arr[i]);
        
        //rightMax[i] = max{ arr[i...(n-1] }


        
        int maxDist = INT_MIN;
        int i = 0, j = 0;
        while(i<n && j<n)
        {
            if(rightMax[j] >= arr[i])
            {
                maxDist = max( maxDist, j-i );
                j++;
            }
            else // if(rightMax[j] < leftMin[i]) 
                i++;
        }
        
        return maxDist;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}
