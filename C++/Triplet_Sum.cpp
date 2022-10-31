// Problem Link: https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/0

#include <bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        int sum = (X - A[i]);
        int l = i + 1, r = n - 1;
        while (r > l)
        {
            if (A[l] + A[r] == sum)
            {
                return true;
            }
            else if (A[l] + A[r] > sum)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
    }
    return false;
}

int main()
{
    int n=6;
    int arr[n]={1,4,45,6,10,8};
    int target = 13;

    if(find3Numbers(arr,n,target)){
        cout<<"Target Found"<<endl;
    }else{
        cout<<"Target Not Found"<<endl;
    }
    return 0;
}