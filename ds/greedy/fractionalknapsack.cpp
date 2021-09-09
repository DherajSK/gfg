#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    
    public:
    static bool comparision(Item arr1, Item arr2)
    {
        return ((arr1.value*arr2.weight)>(arr2.value*arr1.weight));
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comparision);
        
        // for(int i=0;i<n;i++)
        //     cout<<arr[i].value<<":"<<arr[i].weight<<endl;
        double ans=0;
        int knapweight=0;
        for(int i=0;i<n;i++)
        {
                if(knapweight+arr[i].weight<=W)
                {
                    ans+=arr[i].value;
                    knapweight+=arr[i].weight;
                }
                else
                {
                    int remain=W-knapweight;
                    ans+=(double)(remain*arr[i].value)/arr[i].weight;
                    break;
                }
                    
            
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
