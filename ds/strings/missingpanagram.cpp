
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++


class Solution{
  public:
    string missingPanagram(string str){
    
     string ans="";
     int arr[26]={0};
     
     for(int i=0;i<str.length();i++)
     {
         if(str[i]>='a' && str[i]<='z')
             arr[str[i]-'a']=1;
         
         else if(str[i]>='A' && str[i]<='Z')
            arr[str[i]-'A']=1;
     }
     for(int i=0;i<26;i++)
     {
         if(arr[i]==0)
            ans.push_back((char)i+'a');
     }
    if(ans.empty())
        return "-1";
    return ans;
    }

};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	Solution obj;
	cout << obj.missingPanagram(s) << endl;
	}
	return 0;
	
}
