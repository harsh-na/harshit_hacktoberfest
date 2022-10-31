//leetcode_692
class Solution {
private:
static bool comp(pair<string,int> &a, pair<string,int>&b){
if(a.second!=b.second) return a.second<b.second;
else if(a.second==b.second) return a.first>b.first;
return false;
}
public:
vector topKFrequent(vector& words, int k) {
map<string,int> map;
for(auto&i:words) map[i]++;
vector<pair<string,int>> vpair;
for(auto&i:map) vpair.push_back(make_pair(i.first,i.second));
sort(vpair.begin(),vpair.end(),comp);
reverse(vpair.begin(),vpair.end());

// for(auto&i:vpair) cout<<i.first<<" "<<i.second<<endl;
vector ans;
for(int i=0;i<k;i++) ans.push_back(vpair[i].first);

    return ans;
}
};
