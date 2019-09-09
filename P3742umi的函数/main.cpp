#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char x[103],z[103];
int n;
int main()
{
    scanf("%d",&n);
    scanf("%s %s",x,z);
    for(int i = 0;i < n;i++)
    {
        if(x[i] < z[i])
        {
            printf("-1");
            return 0;
        }
    }
    printf("%s",z);
    return 0;
}
