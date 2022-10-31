// C++ program to Count trailing zeroes in factorial of a number


#include <iostream>
using namespace std;
 
int Zeros(int n)
{
    if (n < 0){
        return -1;
    }

    int ptr = 0;
 
    for (int i = 5; n / i >= 1; i *= 5)
        ptr += n / i;
 
    return ptr;
}
 
// Driver Code
int main()
{
    int n = 50;
    cout << "Total Trailing 0s" << 50 << "! is "
         << Zeros(n);
    return 0;
}