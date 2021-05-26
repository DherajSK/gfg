//Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed
//Rj - Rj-1 = arrSum - n * arr[n-j]
//R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]
#include <iostream>
using namespace std;
int Maxsum(int arr[], int n)
{
    int sum,sumvalue=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        sumvalue+=(arr[i]*i);
    }
    int maxvalue=sumvalue;
    for(int j=1;j<n;j++)
    {
        sumvalue+=(sum-(arr[n-j]*n));
        maxvalue=(sumvalue>maxvalue)?sumvalue:maxvalue;
    }
    return maxvalue;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<Maxsum(arr,n);
    return 0;
}
