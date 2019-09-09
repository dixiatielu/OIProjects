#include <iostream>
#include <cstdio>
using namespace std;
int n,m,a[100007];
int main()
{
    scanf("%d %d",&n,&m);
    int now = 0,ds = 1;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(now + a[i] <= m)
        {
            now += a[i];
        }
        else
        {
            ds++;
            now = a[i];
        }
    }
    printf("%d",ds);
    return 0;
}
