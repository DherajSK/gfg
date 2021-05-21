#include <iostream>

using namespace std;

void swap(int arr[], int fi, int si, int d)
{
    int i,temp;
    for(int i=0;i<d;i++)
    {
        temp=arr[fi+i];
        arr[fi+i]=arr[si+i];
        arr[si+i]=temp;
    }
}
void rotatearray(int arr[],int n, int d)
{
    if(n==0 | n==d)
        return;
    if(n-d==d)
    {
        swap(arr,0,d,d);
        return;
    }
    if(n<n-d)
    {
        swap(arr,0,n-d,d);
        rotatearray(arr,n-d,d);
    }
    else
    {
        swap(arr,0,d,n-d);
        rotatearray(arr+n-d,d,2*d-n);
    }
}
int main() 
{
	int n,d;
	cin>>n>>d;
	int arr[n];
	d=d%n;
	for(int i=0;i<n;i++)
	    cin>>arr[i];
	rotatearray(arr,n,d);
	for(int i=0; i<n;i++)
	    cout<<arr[i]<<" ";
	return 0;
}
