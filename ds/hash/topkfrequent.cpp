#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    static bool compare(pair<int,int>p1,pair<int,int>p2)
    {
        if(p1.second==p2.second)
            return p1.first>p2.first;
        return p1.second>p2.second;
    }
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++)
            map[nums[i]]++;
        vector<pair<int,int>>freq(map.begin(),map.end());
        
        sort(freq.begin(),freq.end(),compare);
        vector<int>ans;
        for(int i=0;i<k;i++)
            ans.push_back(freq[i].first);
            
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
} 
