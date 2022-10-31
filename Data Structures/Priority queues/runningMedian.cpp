/*Running median
You are given a stream of n integers. For every ith integer, add it to the running list of integers and print the resulting median (of the list till now).
Print the only integer part of median.
Input Format :
Line 1 : An integer N denoting the number of integers in the stream
Line 2 : N integers which are separated by spaces
Output Format :
After each new integer is added to the list print the updated median on a new line
Input Constraints
1 <= n <= 10^5
1 <= Ai <= 10^5
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6
4
2
2
3
4
Sample Output explanation :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4*/

// incomplete

#include <bits/stdc++.h>
using namespace std;

void printMedian(int *a, int n)
{
    int t = 0;
    priority_queue<int> p;
    priority_queue<int, vector<int>, greater<int>> m;

    for (int i = 0; i < n; i++)
    {
        if (p.empty())
        {
            p.push(a[i]);
            t++;
        }
        else if (p.top() > a[i])
        {
            m.push(p.top());
            p.push(a[i]);
            p.pop();
            t++;
        }
        else if (p.top() < a[i])
        {
            m.push(a[i]);
            t++;
        }

        if (t % 2 == 0)
        {
            cout << (p.top() + m.top()) / 2 << endl;
        }
        else
        {
            if (p.top() > m.top())
            {
                cout << p.top() << endl;
            }
            else
            {
                cout << m.top() << endl;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printMedian(a, n);
    return 0;
}
