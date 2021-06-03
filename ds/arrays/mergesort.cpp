#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        int n1,n2;
        n1=m-l+1;
        n2=r-m;
        int a1[n1],a2[n2];
        for(int i=0;i<n1;i++)
        {
            a1[i]=arr[l+i];
            a2[i]=arr[m+i+1];
        }
        int i=0,j=0,k=l;
        while(i<n1 && j<n2)
        {
            if(a1[i]<a2[j])
            {
                arr[k]=a1[i];
                i++;
            }
            else{
                arr[k]=a2[j];
                j++;
            }
            k++;
        }
        while (i<n1) 
        {
            arr[k] = a1[i];
            i++;
            k++;
        }
        while(j<n2)
        {
            arr[k]=a2[j];
            j++;
            k++;
        }
    }

    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int mid=(l+r)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
