#include <iostream>
#include <cstdio>

using namespace std;
int c[500007],m,n,a[500007],o,p,q;
int lowbit(int x)
{
    return x & -x;
}
void add(int f,int r)
{
    while(f <= n)
    {
        c[f] += r;
        f += lowbit(f);
    }
}
int sum(int k)
{
    int ans = 0;
    while(k)
    {
        ans += c[k];
        k -= lowbit(k);
    }
    return ans;
}
int main()
{
    scanf("%d%d",&n,&m);
    int tmp1,cz;
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&cz);
        if(cz == 1)
        {
            scanf("%d%d%d",&o,&p,&q);
            add(o,q);
            add(p + 1,-q);
        }
        if(cz == 2)
        {
            scanf("%d",&o);
            printf("%d\n",a[o] + sum(o));
        }
    }
    return 0;
}
