#include <iostream>
#include <cstdio>
using namespace std;
int n,cddx,fa[200004],dis[200004],ans = 0x7777777;//n���ˣ����ݶ��󣬸��ڵ�(���鼯),�����ڵ㳤��,��
int find(int x)
{
    if(fa[x] == x)
        return x;
    else
    {
        int l = fa[x];
        fa[x] = find(fa[x]);
        dis[x] += dis[l];
        return fa[x];
    }
}//������
void unin(int x,int y)
{
    int a = find(x);
    int b = find(y);
    if(a != b)
    {
        fa[a] = b;
        dis[x] = dis[y] + 1;
    }
    else
    {
        ans = min(ans,dis[x] + dis[y] + 1);
    }
    return;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        fa[i] = i;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&cddx);
        unin(i,cddx);
    }
    printf("%d",ans);
    return 0;
}
