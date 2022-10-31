class Solution {
public int missingNumber(int[] nums) {
int real =0;
int should =0;
for(int i=0;i <nums.length;i++){
real = real + nums[i];
should = should + i;
}
should = should+nums.length;
return should-real;
}
}
