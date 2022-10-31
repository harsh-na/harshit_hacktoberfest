class Solution {
public:
    unordered_map<string,bool>mp;
    bool scramble(string s1,string s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1==s2){
            return true;
        }
        
        int n=s1.length();
        string temp1=s1;
        string temp2=s2;
        sort(temp1.begin(),temp1.end());
        sort(temp2.begin(),temp2.end());
        if(temp1!=temp2){
            return false;
        }
        string key=s1+" "+s2;
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        bool flag=false;
        for(int i=1;i<n;i++){
            if(scramble(s1.substr(0,i),s2.substr(0,i)) && scramble(s1.substr(i,n-i),s2.substr(i,n-i))){
                flag=true;
                return true;
                
            }
            
                       if(scramble(s1.substr(0,i),s2.substr(n-i,i)) && scramble(s1.substr(i,n-i),s2.substr(0,n-i))){
                           flag=true;
                return true;
            }
            mp[key]=flag;
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
       return scramble(s1,s2);
    }
};
