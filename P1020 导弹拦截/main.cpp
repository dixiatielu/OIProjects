#include <iostream>
#include <cstdio>

using namespace std;

int dp[100007],hei[100007],xt = 1,mxdd = 1,lstdd[100007],nowmx;
int main()
{
    int cnt = 1;
    while(scanf("%d",&hei[cnt]) != EOF)
        cnt++;
    cnt -= 1;
    int num_tt = cnt;
    for(cnt = 1;cnt <= num_tt;cnt ++)
    {
        dp[cnt] = 1;
        for(int i = nowmx;i > 0;i--)
        {
            if(hei[cnt] <= hei[lstdd[i]])
            {
                dp[cnt] = dp[lstdd[i]] + 1;
                break;
            }
        }
        nowmx = max(nowmx,dp[cnt]);
        lstdd[dp[cnt]] = cnt;
        mxdd = max(mxdd,dp[cnt]);
    }
    nowmx = 0;
    for(cnt = 1;cnt <= num_tt;cnt ++)
    {
        dp[cnt] = 1;
        for(int i = nowmx;i > 0;i--)
        {
            if(hei[cnt] > hei[lstdd[i]])
            {
                dp[cnt] = dp[lstdd[i]] + 1;
                break;
            }
        }
        nowmx = max(nowmx,dp[cnt]);
        lstdd[dp[cnt]] = cnt;
        xt = max(xt,dp[cnt]);
    }
    printf("%d\n%d",mxdd,xt);
    return 0;
}
