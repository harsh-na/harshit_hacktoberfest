#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>
using namespace std;
 
bool similar(vector<int> &T, int k)
{
    unordered_map<int, int> map;
 
    for (int i = 0; i < T.size(); i++)
    {
        
        if (map.find(T[i]) != map.end())
        {
            if (i - map[T[i]] <= k) {
                return true;
            }
        }
        map[T[i]] = i;
    }
    return false;
}
 
int main()
{
    vector<int> T = { 5, 6, 8, 2, 4, 6, 9 };
    int k = 4;
 
    if (similar(T, k)) {
        cout << "Duplicates found";
    }
    else {
        cout << "No duplicates were found";
    }
 
    return 0;
}