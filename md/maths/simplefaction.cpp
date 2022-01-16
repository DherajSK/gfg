// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int numerator, int denominator) 
	{
	    int quotient=numerator/denominator;
	    string res=to_string(quotient);
	    if(numerator%denominator==0)
	        return res;
        res+=".";
        int rem=numerator%denominator;
        map<int,int>mp;
        int index;
        bool repeating=false;
        while(rem>0 && !repeating)
        {
            if(mp.find(rem)!=mp.end())
            {
                index=mp[rem];
                repeating=true;
                break;
            }
            else
                mp[rem]=res.size();
                
            rem=rem*10;
            int temp=rem/denominator;
            res+=to_string(temp);
            rem=rem%denominator;
        }
        
        if(repeating)
        {
            res+=")";
            res.insert(index,"(");
        }
        return res;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
