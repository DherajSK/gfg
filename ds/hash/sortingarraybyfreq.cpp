#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool fcompare(pair<int,pair<int,int>>p,pair<int,pair<int,int>>p1)
    {
        if(p.second.second!=p1.second.second)
            return (p.second.second>p1.second.second);
        else
            return (p.first<p1.first);
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        unordered_map<int, pair<int,int>>map;
        for(int i=0;i<n;i++)
        {
            if(map.find(arr[i])!=map.end())
                map[arr[i]].second++;
            else
                map[arr[i]]=make_pair(i,1);
        }
        auto it=map.begin();
        vector<pair<int, pair<int, int> > > ans;
        
        for(it;it!=map.end();it++)
            ans.push_back(make_pair(it->first,it->second));
        
            
        sort(ans.begin(), ans.end(), fcompare);
        vector<int>res;
        for(int i=0;i<ans.size();i++)
        {
            int count=ans[i].second.second;
            while(count--)
                res.push_back(ans[i].first);
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}
