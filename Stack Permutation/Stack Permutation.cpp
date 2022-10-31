
class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        
        stack<int>s;
        
        int i = 0;
        int j = 0;
        
        while(i<A.size() && j<B.size()){
            
            s.push(A[i]);
            
            i++;
            
            while(!s.empty() && s.top() == B[j]){
                
                s.pop();
                j++;
            }
        }
         
        if(s.size()>0){
            
            return 0;
        }
        
        return 1;
        
    }
};
