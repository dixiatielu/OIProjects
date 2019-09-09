#include <iostream>
#include <cstdio>
using namespace std;
int n,m,ma[52][52],dp[52][52][52][52];
int max4(int a,int b,int c,int d)
{
    if(b > a)
        a = b;
    if(c > a)
        a = c;
    if(d > a)
        a = d;
    return a;
}
int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&m,&n);
	for(int i = 1;i <= m;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            scanf("%d",&ma[i][j]);
        }
    }
    for(int h = 1;h <= m;h++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= m;k++)
            {
                for(int l = j + 1;l <= n;l++)
                {
                    dp[h][j][k][l] = max4(dp[h - 1][j][k - 1][l],dp[h - 1][j][k][l - 1],dp[h][j - 1][k - 1][l],dp[h][j - 1][k][l - 1]) + ma[h][j] + ma[k][l];
                }
            }
        }
    }
    printf("%d",dp[m][n - 1][m - 1][n]);
    return 0;
}
