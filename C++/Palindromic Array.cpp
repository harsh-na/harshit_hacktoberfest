/*
Question:
Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

 

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1
0

Explanation:
For First test case.
n=5;
A[0] = 111    //which is a palindrome number.
A[1] = 222   //which is a palindrome number.
A[2] = 333   //which is a palindrome number.
A[3] = 444  //which is a palindrome number.
A[4] = 555  //which is a palindrome number.
As all numbers are palindrome so This will return 1.

Constraints:
1 <=T<= 50
1 <=n<= 20
1 <=A[]<= 10000

*/

// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int PalinArray(int arr[], int n)
    {
    	for(int i=0; i<n; ++i){
    	    int c=0;
    	    for(int j=arr[i]; j>0;j=j/10){
    	        c = 10*c+(j%10);
    	    }
    	    if(arr[i]==c)
    	    continue;
    	    else 
    	    return 0;
    	}
    	return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends


