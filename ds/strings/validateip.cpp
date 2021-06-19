#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isvalidpart(char* a)
        {
            int n=strlen(a);
            if(n>3)
                return 0;
                
            for(int i=0;i<n;i++)
            {
                if((a[i]>='0' && a[i]<='9')==false)
                    return 0;
            }
            string str(a);
            if(str.find('0')==0 && n>1)
                return 0;
            stringstream stm(str);
            int x;
            stm>>x;
            return (x>=0 && x<=255);
        }
        int isValid(string s) {
            int n=s.length();
            int count=0,dots=0;
            
            if(n==0)
                return 0;
            
            for(int i=0;i<n;i++)
                if(s[i]=='.')   
                    count++;
            
            if(count !=3)
                return 0;
                
            string str1(s);
            char* ptr=strtok(&str1[0],".");
            
            if(ptr==NULL)
                return 0;
            
            while(ptr)
            {
                if(isvalidpart(ptr))
                {
                    ptr=strtok(NULL,".");
                    if(ptr!=NULL)
                        dots++;
                }
                else return 0;
            }
            
            if(dots!=3)
                return 0;
            return 1;
            
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
