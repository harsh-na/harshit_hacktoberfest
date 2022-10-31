#include<bits/stdc++.h>
using namespace std;
// Function to find the length of LPS
int LPS (string s, int low, int high){

    // Base case 1: String of length 1.
    if(low == high)
        return 1;

    // Base case 2: String of length 2.
    if(high - low == 1){
        // If both characters are equal
        if(s[low] == s[high])
            return 2;
        // Otherwise
        else 
            return 1;
    }
    // If s[low] and s[high] are equal
    if(s[low] == s[high])
        return 2 + LPS (s, low + 1, high - 1);
    // Otherwise
    return max( LPS (s, low, high - 1), 
                        LPS(s, low + 1, high));
}


int main(){
    // Trying for string "abbab"
    string s = "abbab";
    int len = LPS (s, 0, s.length() - 1);
    cout << "Length of LPS of " << s 
                    << " is " << len << endl;

    // Trying for string "abaaba"
    s = "abaaba";
    len = LPS (s, 0, s.length() - 1);
    cout << "Length of LPS of " << s 
                    << " is " << len << endl;
    return 0;
}
