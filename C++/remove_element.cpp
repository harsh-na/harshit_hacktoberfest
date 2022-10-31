class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>:: iterator it;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                it=nums.begin()+i;
                nums.erase(it);
                i=i-1;
            }
        }
        return nums.size();
    }
};
