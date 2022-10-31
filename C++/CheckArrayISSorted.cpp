#include<iostream>
using namespace std;
bool sortedarray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[i+1]) ///1,2,3,
        {
            return false;
        }
      
    }
    return true;

}
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    bool ans =sortedarray(arr,n);
    if(ans)
    {
    cout<<"Sorted";
    }
    else{
    cout<<"not sorted";
    }
}
