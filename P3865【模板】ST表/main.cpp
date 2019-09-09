#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,f[100006][40],tmp,LC,l,r,tmp2;
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&tmp);
        f[i][0] = tmp;
    }
    LC = (int)(log(n) / log(2));
    for(int j = 1;j <= LC;j++)
    {
        for(int i = 1;i <= n - (1 << j) + 1;i++)
        {
            f[i][j]=max(f[i][j - 1],f[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d %d",&l,&r);
        tmp2 = (int)(log(r - l + 1) / log(2));
        printf("%d\n",max(f[l][tmp2],f[r - (1 << tmp) + 1][tmp2]));
    }
    return 0;
}
