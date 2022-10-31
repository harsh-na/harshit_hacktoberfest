//Spirally traversing a matrix
#include <bits/stdc++.h> 
using namespace std; 


class Solution
{   
  
    public: 
    
    vector<int> spirallyTraverse(vector<vector<int> > m, int r, int c) 
    {
       int rs=0,rl=r-1,cs=0,cl=c-1;
       vector<int> v;
       while(rl>=rs && cl>=cs)
       {  
          if(rl>=rs && cl>=cs)
          {for(int i=cs;i<=cl;i++)
          v.push_back(m[rs][i]);
          rs++;}
          
          if(rl>=rs && cl>=cs)
          {for(int i=rs;i<=rl;i++)
          v.push_back(m[i][cl]);
          cl--;}
          
          if(rl>=rs && cl>=cs)
          {for(int i=cl;i>=cs;i--)
          v.push_back(m[rl][i]);
          rl--;}
          
          if(rl>=rs && cl>=cs)
          {for(int i=rl;i>=rs;i--)
          v.push_back(m[i][cs]);
          cs++;}
       }
       return v;
    }
};


int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}