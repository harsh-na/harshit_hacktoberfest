
#include <bits/stdc++.h>
using namespace std;

int recurFact(int n) {
    return (n == 0) ? 1 : n * recurFact(n-1);
}

int main(int argc, char const *argv[])
{
    int x;
    cout << "\nEnter a number: ";
    cin >> x;
    cout << x << "! = " << recurFact(x) << endl;

    return 0;
}
