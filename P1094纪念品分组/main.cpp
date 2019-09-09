#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,w,p[30007],num;
bool vis[30007];
int main()
{
    scanf("%d %d",&w,&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&p[i]);
    }
    sort(p + 1,p + n + 1);
    int head = 1;
    int tail = n;
    while(head < tail)
    {
        if(p[head] + p[tail] <= w)
        {
            head++;
            tail--;
            num++;
        }
        else
        {
            tail--;
            num++;
        }
    }
    printf("%d",num);
    return 0;
}
