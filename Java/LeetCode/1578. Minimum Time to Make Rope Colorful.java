public int minCost(String colors, int[] neededTime) {
        int mincost = 0, max = 0,len = colors.length();
        
        
        for(int i=0; i< len; i++){
            if(i>0 && colors.charAt(i) != colors.charAt(i-1)){
                max = 0;
            }
            
            mincost += Math.min(max,neededTime[i]);
            max = Math.max(max,neededTime[i]);
        }
            
        
        
        return mincost;
        
}
