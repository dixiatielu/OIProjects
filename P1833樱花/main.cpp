#include <cstdio>
using namespace std;
int tmnowH, tmnowM, tmeH, tmeM, lftme, n, c[10003], mxSeeTime[10003], usTime[10003], dp[1010];
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	scanf("%d:%d %d:%d %d", &tmnowH, &tmnowM, &tmeH, &tmeM,&n);
	lftme = tmeH * 60 + tmeM - tmnowH * 60 - tmnowM;
	for (int i = 1; i <= n; i++)
	{
	    scanf("%d %d %d",&usTime[i],&c[i],&mxSeeTime[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!mxSeeTime[i] || usTime[i] * mxSeeTime[i] > lftme)//ÍêÈ«±³°ü
		{
			for (int j = usTime[i]; j <= lftme; j++)
			{
				dp[j] = max(dp[j], dp[j - usTime[i]] + c[i]);
			}
		}
		else
		{
			for (int j = 1; j <= mxSeeTime[i]; j <<= 1)
			{
				for (int k = lftme; k >= j * usTime[i]; k--)
				{
					dp[k] = max(dp[k], dp[k - j * usTime[i]] + c[i] * j);
				}
				mxSeeTime[i] -= j;
			}
			if(mxSeeTime[i])
            {
                for (int k = lftme; k >= mxSeeTime[i] * usTime[i]; k--)
                {
                    dp[k] = max(dp[k],dp[k - mxSeeTime[i] * usTime[i]] + c[i] * mxSeeTime[i]);
                }
            }
		}
	}
	printf("%d",dp[lftme]);
}
