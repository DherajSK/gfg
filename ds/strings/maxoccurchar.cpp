
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int freq[26] = { 0 };
 
    
    int max = -1;
    char result;
    int len = str.length();
    
    for (int i = 0; i < len; i++)
        freq[str[i] - 'a']++;
        
    for (int i = 0; i < 26; i++)
        if (max < freq[i]) {
            max = freq[i];
            result = (char)(i + 'a');
        }
 
    return result;
    }

};

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}
