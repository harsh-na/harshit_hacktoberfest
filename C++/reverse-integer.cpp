#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int n=x;
        int b,ans=0,i=1;
        while(n!=0){
            b=n%10;
            if(ans>(INT_MAX/10)|| (ans<(INT_MIN/10))){
                return 0;
            }
            ans=ans*pow (10,i)+b;
            n=n/10;
    }
               return ans;
    }
};
