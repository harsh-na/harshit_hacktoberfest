
#include<iostream>
using namespace std;

int factorial(int n){
    if (n<=1){
        return 1;
    }
    return n * factorial(n-1);
}
// Fibonnaci Series:-
int fib(int n){
    if (n<2){     
        return n;
    }
    return fib(n-2) + fib(n-1);
}
int main(){
    int a;
    cout<<"enter number"<<endl;
    cin>>a;
    cout<<"the factorial of a is "<<factorial(a)<<endl;

    cout<<"fibonnaci of "<<a<<fib(a)<<endl;
    return 0;



}

