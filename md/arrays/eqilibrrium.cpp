#include <iostream>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) 
    {
    int sum=0;  
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum==arr[0])
        return 1;
    int temp=0;
    for(int i=0;i<n-1;i++)
    {
        temp+=arr[i];
        if(temp==sum-temp-arr[i+1])

            return i+2;
        
    }
    return -1;
    }
};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
