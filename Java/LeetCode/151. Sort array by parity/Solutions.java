class Solutions {
    public int[] sortArrayByParity(int[] nums) {
        int last= nums.length-1;
        for (int i = 0; i < last;) {
            // find the max item in the remaining array and swap with correct index
            if(nums[i]%2==0)
            {
                i++;
                continue;
            }
            else
            {
                int temp= nums[i];
                nums[i]=nums[last];
                nums[last]=temp;
                last--;
            }
        }
        return nums;
    }
}
