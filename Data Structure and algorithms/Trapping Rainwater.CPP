#include <bits/stdc++.h>
using namespace std;

int maxWater(int arr[], int n)
{
	
	int left = 0;
	int right = n-1;

	
	int left_min = 0;
	int right_max = 0;

	// the total amount of rain water trapped
	int result = 0;
	while (left <= right)
	{

	
	if(right_max <= left_min)
	{

		
		result += max(0, right_max-arr[right]);

	
		right_max = max(right_max, arr[right]);

	
		right -= 1;
	}
	else
	{

		
		result += max(0, left_min-arr[left]);

		
		left_min = max(left_min, arr[left]);

		
		left += 1;
	}
	}
	return result;
}

int main() 
{
    int n; 
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)   cin>>arr[i];
	int N = sizeof(arr)/sizeof(arr[0]);
	cout << maxWater(arr, N) << endl;
	return 0;
}

