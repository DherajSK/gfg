#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int ans=0;
	    vector <int>temp=nums;
	    sort(temp.begin(),temp.end());
	    map <int,int> mp;
	    for(int i=0;i<nums.size();i++)
	        mp[nums[i]]=i;
	        
	    for(int i=0;i<nums.size();i++)
	    {
	        if(temp[i]!=nums[i])
	       {
	            int idx=mp[temp[i]];
	            mp[nums[i]]=idx;
	            mp[nums[idx]]=i;
	            swap(nums[i],nums[idx]);
	            ans+=1;
	       }
	            
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
