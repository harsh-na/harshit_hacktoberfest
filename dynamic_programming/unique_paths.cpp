/*
The problem is to count all the possible paths from top left to bottom
right of a mXn matrix with the constraints that from each cell you can
either move only to right or down
*/

// Recursive Dynamic Programming
#include <iostream>
#include <cstring>
using namespace std;

// Returns count of possible paths to reach
// cell at row number m and column number n from
// the topmost leftmost cell (cell at 1, 1)
int numberOfPaths(int n,int m,int DP[4][4]){

	if(n == 1 || m == 1)
		return DP[n][m] = 1;
	
	// Add the element in the DP table
	// If it is was not computed before
	if(DP[n][m] == 0)
		DP[n][m] = numberOfPaths(n - 1, m,DP) + numberOfPaths(n, m - 1,DP);

	return DP[n][m];
}

// Driver code
int main()
{
	// Create an empty 2D table
	int DP[4][4] = {0};
	memset(DP, 0, sizeof(DP));

	cout << numberOfPaths(3, 3,DP);

	return 0;
}
// This code is contributed
// by Gatea David
