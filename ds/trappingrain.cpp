//trapping rain water
#include<bits/stdc++.h>

using namespace std;

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int leftmax=0, rightmax=0, water=0;
        int lo=0,hi=n-1;
        while(lo<=hi)
        {
            if(arr[lo]<arr[hi])
            {
                if(arr[lo]>leftmax)
                    leftmax=arr[lo];
                else
                    water+=leftmax-arr[lo];

                lo++;
            }
            else
            {
                if(arr[hi]>rightmax)
                    rightmax=arr[hi];
                else
                    water+=rightmax-arr[hi];

                hi--;
            }
        }
        return water;
    }
};

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
