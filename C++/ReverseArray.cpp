#include <bits/stdc++.h>
using namespace std;
void reversearray(vector<int> &ans)
{
    if(ans.size()==0) return ;
    int first=ans[0];
    ans.erase(ans.begin());
    reversearray(ans);
    ans.push_back(first);
}

int main(){
    int n;
    cin>>n;
    vector<int>ans(n);
    for(int i=0; i<n; i++){
        cin>>ans[i];
    }
    reversearray(ans);
    for(auto it:ans){
        cout<<it<<" ";
    }
}
