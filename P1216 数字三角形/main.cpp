#include <iostream>
#include <cstdio>
using namespace std;
int f[1001][1001],n,m[1001][1001];
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= i;j++)
        {
            scanf("%d",&f[i][j]);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        m[n][i] = f[n][i];
    }
    for(int i = n - 1;i >= 1;i--)
    {
        for(int j = 1;j <= i;j++)
        {
            m[i][j] = max(f[i][j] + m[i + 1][j],f[i][j] + m[i + 1][j + 1]);
        }
    }
    printf("%d",m[1][1]);
    return 0;
}
