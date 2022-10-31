#include <bits/stdc++.h>
using namespace std;

string timeConversion(string s) {
    
    int hour = stoi(s.substr(0,2));
    if (s[8] == 'P' && hour < 12) {
        hour +=12;
    } else if (s[8] == 'A' && hour == 12) {
        hour = 0;
    }
    
    stringstream ss;
    ss  << hour;
    ss << s.substr(2, 6);
    return ss.str();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}