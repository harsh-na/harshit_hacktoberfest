#include<iostream>
#include<cmath>
using namespace std;

int main(){

int n;
cout<<"enter any number:"<<endl;
cin>>n;
 
 bool flag=0;
for(int i=2; i<=sqrt(n); i++){
    if(n%i==0){
        cout<<"the number is not prime number"<<endl;
        flag=1;
        break;
    }else{
        cout<<"the number is prime number";
    }
    cout<<endl;
}
return 0;
}
