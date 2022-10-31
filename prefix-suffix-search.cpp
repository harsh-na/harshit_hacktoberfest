//https://leetcode.com/problems/prefix-and-suffix-search/

class WordFilter {
public:
    unordered_map<string, int> hsMp;
    WordFilter(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i < n; i++){
            string new_word = words[i];
            int len = new_word.length();

            for(int j = 1; j <= len; j++){
                string pref = new_word.substr(0, j);
                for(int k = 0; k < len; k++){
                    string suff = new_word.substr(k);

                    hsMp[pref+'|'+suff] = i + 1;
                }
            }
        }
    }

    int f(string pref, string suff) {
        string s = pref + '|' + suff;
        return hsMp[s] - 1;
    }
};