#include <stdio.h>
#include <limits.h>
#include <math.h>

int dp[100][100];
int count;

int matrixChainStore(int p[], int i, int j)
{
  count++;
  int cost1 = 0;
  int cost2 = 0;
  if(i == j)
  {
    return 0;
  }
  if(dp[i][j] != 0)
  {
    return dp[i][j];
  }
  dp[i][j]++;
  int minCost = INT_MAX;
  for(int k = i; k < j; k++)
  {
    int cost = matrixChainStore(p,i,k) + matrixChainStore(p,k+1,j) + p[i-1]*p[k]*p[j];
    if(cost < minCost)
    {
      minCost = cost;
    }
  }
  dp[i][j] = minCost;
  return minCost;
}

int main()
{
  int N;
  printf("Enter the number of matrices to multiply: \n");
  scanf("%d",&N);
  int arr[N+1];
  printf("Enter the sizes: \n");
  for(int i = 0; i < N+1; i++)
  {
      scanf("%d", &arr[i]);
  }
  printf("The minimum number of scalar multiplications is: %d\n",matrixChainStore(arr,1,N));
  int subproblemCount = (N*(N-1))/2;
  printf("\n Number of subproblems: %d", subproblemCount);
  printf("\n Number of times each subproblem is solved: %d", count);
  return 0;
}