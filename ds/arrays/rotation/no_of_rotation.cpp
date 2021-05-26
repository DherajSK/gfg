//to find the number of rotations in a sorted rotated array
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n)
	{
	    int low=0, high=n-1;
	    if(arr[low]<arr[high])
	        return 0;
	    int mid;
	    while(low<high)
	    {
	        mid=(low+high)/2;
	        if(arr[mid+1]<arr[mid])
	            return mid+1;
	        if(arr[mid]<arr[high])
	            high=mid;
	        else
	            low=mid;
	    }
	        
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}
