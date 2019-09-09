#include <iostream>
#include <cstdio>
using namespace std;
int m,t,w[10003],c[10003],f[100003];
int main()
{
    scanf("%d %d",&t,&m);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d",&w[i],&c[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = w[i];j <= t;j++)
        {
            f[j] = max(f[j],f[j - w[i]] + c[i]);
        }
    }
    printf("%d",f[t]);
    return 0;
}
