
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        int min=-1;
        set<int> myset;
        for(int i=n-1;i>=0;i--)
        {
            if(myset.find(arr[i])!=myset.end())
                min=i;
            else
                myset.insert(arr[i]);
        }

        if(min==-1)
            return -1;
        return min+1;
    }
};

// { Driver Code Starts.
int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        int arr[n];
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> arr[i] ;
        Solution ob;    
        cout << ob.firstRepeated(arr,n) << "\n";
    }

    return 0;
}
