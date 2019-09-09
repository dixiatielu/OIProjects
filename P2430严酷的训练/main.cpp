#include <iostream>
#include <cstdio>
using namespace std;
int sp_wky,sp_lw,num_tm,num_zsd,tmew[5001],havetime,zsd[5001],jlz[5001],tmp,dp[5001][5002],tmet[5001];
int main()
{
    scanf("%d %d",&sp_wky,&sp_lw);
    scanf("%d %d",&num_tm,&num_zsd);
    for(int i = 1;i <= num_zsd;i++)
    {
        scanf("%d",&tmp);
        tmew[i] = tmp * sp_lw / sp_wky;
    }
    for(int i = 1;i <= num_tm;i++)
    {
        scanf("%d %d",&zsd[i],&jlz[i]);
        tmet[i] = tmew[zsd[i]];
    }
    scanf("%d",&havetime);
    for(int i = 1;i <= num_tm;i++)
    {
        for(int j = havetime;j >= 0;j--)
        {
            if(j >= tmet[i])
            {
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - tmet[i]] + jlz[i]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d",dp[num_tm][havetime]);
    return 0;
}
