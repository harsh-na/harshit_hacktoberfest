#include <iostream>
using namespace std;

bool possibleSolution(int arr[],int n,int m, int mid){
    int studentCount = 1;
    int pageSum = 0;

    for(int i=0;i<n;i++){
        if(pageSum + arr[i] <= mid){
            pageSum += arr[i];
        }
        else{
            studentCount +=1;
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int bookAllocation(int arr[],int n,int m){
    int s =0,sum=0;

    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    int e =sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <=e){

        if(possibleSolution(arr,n,m,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid  =  s + (e-s)/2;
    }
    return ans;
}

int main(){

    int n,m;
    cout << "Enter Size: ";
    cin >> n;
    int arr[n];
    cout << "Enter Array: ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << "Enter NUmber of Students: ";
    cin >> m;

    cout << bookAllocation(arr,n,m);

return 0;

}