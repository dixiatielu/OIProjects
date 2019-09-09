#include <iostream>
#include <cstdio>
using namespace std;
int v,n,dp[20003],w[32];

int main()
{
    //freopwn(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&v,&n);
	for(int i = 1;i <= n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = v;j >= w[i];j--)
        {
            dp[j] = max(dp[j],dp[j - w[i]] + w[i]);
        }
    }
    printf("%d",v - dp[v]);
    return 0;
}
