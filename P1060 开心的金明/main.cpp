#include <iostream>
#include <cstdio>
using namespace std;
int n,m,c[30],pri[30],p,dp[35000];

int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i++)
    {
        scanf("%d%d",&pri[i],&p);
        c[i] = pri[i] * p;
    }
    for(int i = 1;i <= m;i++)
    {
        for(int j = n;j >= pri[i];j--)
        {
            dp[j] = max(dp[j],dp[j - pri[i]] + c[i]);
        }
    }
    printf("%d",dp[n]);
    return 0;
}
