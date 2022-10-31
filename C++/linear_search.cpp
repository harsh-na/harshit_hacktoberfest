#include <iostream>
using namespace std;
bool isPresent(int arr[], int size, int data)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == data)
            return 1;
    }
    return 0;
}
int main()
{
    int arr[10] = {5, 7, -2, 10, 22, -2, 0, 5, 22, 1};
    int data;
    cin >> data;
    if (isPresent(arr, 10, data))
        cout << "Yes " << data << " is present in the array" << endl;
    else
        cout << "No " << data << " is not present in the array" << endl;

    return 0;
}