#include <bits/stdc++.h>
using namespace std;

int main(){

    multimap<int,int> m1;

    m1.insert(pair<int, int>(1,10)); //inserting key-value pair
    m1.insert(pair<int, int>(2,20));
    m1.insert(pair<int, int>(3,30));
    m1.insert(pair<int, int>(4,40));
    m1.insert(pair<int, int>(5,50));

    cout<<" The multimap m1: \n";

    cout<<"\tKEY\tELEMENT\n";

    for(pair<int,int> itr: m1) { //printing key-value pair elements of multimap m1
        cout << '\t' << itr.first << '\t' <<i tr.second << '\n';
    }

    m1.insert(pair<int, int>(6,60)); //inserting {6,60} in m1
    m1.insert(pair<int, int>(7,70)); //inserting {7,70} in m1

    cout<<"\n The multimap m1 after inserting extra elements: \n";

    cout<<"\tKEY\tELEMENT\n";

    for(auto itr:m1){ 
        //printing m1 multimap after inserting new key-value pair above
        cout << '\t' << itr.first << '\t' << itr.second << '\n';
    }

    multimap<int, int> m2(m1.begin(),m1.end());

    cout<<"\n m2 after removal of elements less than key=3 : \n";

    cout<<"\tKEY\tELEMENT\n";

    m2.erase(m2.begin(),m2.find(3)); 

    //removal of key-value pair having key less than 3 
    for(auto itr: m2){
        cout << '\t' << itr.first << '\t' << itr.second <<'\n';
    }
    
    cout << "\n m1.lower_bound(5): " << "\tKEY = ";
    cout << m1.lower_bound(5)->first << '\t'; //lower_bound value of key = 5
    cout << "\tELEMENT = " << m1.lower_bound(5)->second << endl;
    
    return 0;
}
