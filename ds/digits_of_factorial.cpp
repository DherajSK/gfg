

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int digitsInFactorial(int N)
    {
        double digits=0;
        for(int i=1;i<=N;i++)
            {
                digits+=log10(i);
            }
        return floor(digits)+1;
    }
};


int main()
{
    int T;
    
    //taking testcases
    cin>>T;
    while(T--)
    {
        int N;
        
        //taking N
        cin>>N;
        Solution ob;
        //calling method digitsInFactorial()
        cout<<ob.digitsInFactorial(N)<<endl;
    }
    return 0;
}
