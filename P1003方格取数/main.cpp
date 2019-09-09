#include <iostream>
#include <cstdio>
using namespace std;
int n,ma[10][10],x,y,num,dp[10][10][10][10];

int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&n);
	while(1)
    {
        scanf("%d%d%d",&x,&y,&num);
        if(x == 0 && y == 0 && num == 0)
            break;
        else
        {
            ma[x][y] = num;
        }
    }
    for(int v = 1;v <= n;v++)
    {
        for(int b = 1;b <= n;b++)
        {
            for(int j = 1;j <= n;j++)
            {
                for(int k = 1;k <= n;k++)
                {
                    dp[v][b][j][k] = max(max(dp[v - 1][b][j][k - 1],dp[v - 1][b][j - 1][k]),max(dp[v][b - 1][j][k - 1],dp[v][b - 1][j - 1][k])) + ma[v][b] + ma[j][k];
                    if(v == j && b == k)
                        dp[v][b][j][k] -= ma[v][b];
                }
            }
        }
    }
    printf("%d",dp[n][n][n][n]);
    return 0;
}
