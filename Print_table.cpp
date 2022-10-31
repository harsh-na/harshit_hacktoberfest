#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"Hello Friend !\nThis program will print the table of your chosen number !"<<endl;
	cout<<"\nEnter the number : ";
	cin>>n;
	for(int i=1;i<=10;i++){
		cout<<n<<" * "<<i<<" = "<<n*i<<endl;
	}
}
