#include <bits/stdc++.h>
using namespace std;
#define ROW 5
#define COL 5
int canVisit(int bin[][COL], int row, int col, bool visited[][COL]){
   return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (bin[row][col] && !visited[row][col]);
}
void DFS(int bin[][COL], int row, int col, bool visited[][COL]){
   static int getNeighbourRow[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
   static int getNeighbourCol[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
   visited[row][col] = true;
   for (int k = 0; k < 8; ++k)
      if (canVisit(bin, row + getNeighbourRow[k], col + getNeighbourCol[k], visited))
         DFS(bin, row + getNeighbourRow[k], col + getNeighbourCol[k], visited);
}
int findIslandCount(int bin[][COL]){
   bool visited[ROW][COL];
   memset(visited, 0, sizeof(visited));
   int islandCount = 0;
   for (int i = 0; i < ROW; ++i)
   for (int j = 0; j < COL; ++j)
   if (bin[i][j] && !visited[i][j]) {
      DFS(bin, i, j, visited);
      islandCount++;
   }
   return islandCount;
}
int main(){
   int temp[][COL] = {{1, 0, 0, 0},
   {0, 1, 0, 1},
   {0, 0, 0, 0},
   {0, 0, 1, 0}};
   cout<<findIslandCount(temp);
   return 0;
}
