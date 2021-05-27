// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> quadraticRoots(int a, int b, int c) {
        vector<int> ans;
        float D=(b*b)-(4*a*c);
        if(D<0)
            ans.push_back(-1);
        else if(D==0)
        {
            ans.push_back(floor(-b/(2*a)));
            ans.push_back(floor(-b/(2*a)));
        }
        else
        {
            if(floor((-b+sqrt(D))/(2*a))>floor((-b-sqrt(D))/(2*a)))
            {
                ans.push_back(floor((-b+sqrt(D))/(2*a)));
                ans.push_back(floor((-b-sqrt(D))/(2*a)));
            }
            else
            {
                ans.push_back(floor((-b-sqrt(D))/(2*a)));
                ans.push_back(floor((-b+sqrt(D))/(2*a)));
        
                
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        Solution ob;
        vector<int> roots = ob.quadraticRoots(a, b, c);
        if (roots.size() == 1 && roots[0] == -1)
            cout << "Imaginary";
        else
            for (int i = 0; i < roots.size(); i++) cout << roots[i] << " ";
        cout << endl;
    }
    return 0;
} 
