class Solution {
    public int longestConsecutive(int[] nums) {
        HashSet<Integer> mp = new HashSet<>();
        for(int num : nums){
            mp.add(num);
        }
        int longlength =0;
       
       
        for(int num:nums){
        
        if(!mp.contains(num - 1)){
           int  currnum = num;
           int  currlong = 1;
        
            while(mp.contains(currnum + 1)){
                currnum += 1;
                currlong += 1;
            }
        
          longlength = Math.max(longlength,currlong);
        }
        }
        return longlength;
    }
      
    }
