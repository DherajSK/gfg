
#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void allPossibleWords(string keypad[],int a[], string res, vector <string> &ans, int index)
    {
        if(index==-1)
        {
            ans.push_back(res);
            return;
        }
        int digit=a[index];
        int len=keypad[digit].length();
        for(int i=0;i<len;i++)
            allPossibleWords(keypad,a,string(keypad[digit][i]+res), ans, index-1);
        
    }
    vector<string> possibleWords(int a[], int N)
    {
        vector <string> ans;
        string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        allPossibleWords(keypad,a,string(""),ans,N-1);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
} 
