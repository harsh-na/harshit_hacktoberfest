/*
#include<iostream>
using namespace std;
void movezero(int arr[],int n)
{
    int temp[n];
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=0)
        {
            temp[k]=arr[i];
            k++;
        }
        
    }
    while(k<n)
        {
            temp[k]=0;
            k++;
        }
    cout<<"move zero at enf";
    for(int i=0;i<k;i++)
    {
        cout<<temp[i]<<" ";
    }

   
}
int main()
{
    int arr[]={1,0,3,0,2,0,0,7,4,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    movezero(arr,n);

    

}

*/
/// it takes O(n) space
/////////////////////////////////////////
// Alternate Approach
#include<iostream>
#include<algorithm>
using namespace std;
void movezero(int arr[], int n)
{
    int p1=0;
    int p2=0;
    if(n==0 || n==1)
    return;
    
    while(p2<n)
    {
        if(arr[p2]==0)
        {
            p2++;
        }
        else{
            int temp=0;
            temp=arr[p2];
            arr[p2]=arr[p1];
            arr[p1]=temp;
            p2++;
            p1++;
        }

    }
    cout<<"printing";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
     int arr[]={1,0,3,0,2,0,0,7,4,0,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    movezero(arr,n);

}
