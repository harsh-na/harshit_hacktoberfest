#include <iostream>
using namespace std;

void perm(char s[], int k)
{
    static int a[5] = {0};
    static char Res[10];
    int i;
    if (s[k] == '\0')
    {
        Res[k] = '\0';
        cout<<Res<<endl;
    }
    else{
        for(i=0;s[i]!='\0';i++)
        {
            if(a[i]==0){
                Res[k]=s[i];
                a[i]=1;
                perm(s,k+1);
                a[i]=0;
            }
        }
    }
}

int main()
{
    char s[] = "abc";
    perm(s, 0);
}
