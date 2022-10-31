#include <iostream>

using namespace std;
int anagram(char s1[], char s2[])
{
    int i, flag = 0,  x[26] = {0}, y[26] = {0};
    for(i = 0; s1[i] != '\0'; i++)
        x[s1[i] - 'a']++;
    for(i = 0; s2[i] != '\0'; i++)
        y[s2[i] - 'a']++;
    for (i = 0; i < 26; i++)
    {
        if (x[i] != y[i])
            flag = 1; 
    }
    if (flag == 1)
        cout << "Strings are Not Anagrams.";
    else
        cout << "Strings are Anagrams.";
}
 
int main ()
{
    char s1[50], s2[50];
    int flag;
    cout << "Enter string 1: ";
    gets(s1);
    cout << "Enter string 2: ";
    gets(s2);
    anagram(s1, s2);
    return 0;
}
