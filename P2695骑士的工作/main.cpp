#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,siz_head[20003],abl[20003],nowh,ans;
bool visq[20003],tag;
int main()
{
    scanf("%d %d",&n,&m);
    if(n > m)
    {
        printf("you died!");
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&siz_head[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&abl[i]);
    }
    sort(siz_head + 1,siz_head + 1 + n);
    sort(abl + 1,abl + m + 1);
    nowh = n;
    for(int i = n;i >= 1;i--)
    {
        for(int j = 1;j <= m;j++)
        {
            if(abl[j] >= siz_head[i] && !visq[j])
            {
                visq[j] = 1;
                ans += abl[j];
                tag = 1;
                break;
            }
        }
        if(!tag)
        {
            printf("you died!");
            return 0;
        }
        tag = 0;
    }
    printf("%d",ans);
    return 0;
}
