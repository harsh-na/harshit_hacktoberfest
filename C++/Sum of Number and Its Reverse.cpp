#Problem statement
#Level-Leetcode contest medium level
#Given a non-negative integer num, return true if num can be expressed as the sum of any non-negative integer and its reverse, or false otherwise.
// Example 1:

// Input: num = 443
// Output: true
// Explanation: 172 + 271 = 443 so we return true.

// Code 
class Solution {
public:
    int reverse(int n){
        int sum=0;
        while(n!=0){
            sum=sum*10+n%10;
            n/=10;
        }
        return sum;
    }
    bool sumOfNumberAndReverse(int num) {
        if(num==0) return true;
     for(int i=1; i<=num; i++){
         int ans=reverse(i);
         if(i+ans==num){
             return true;
         }
     }
        return false;
    }
};

