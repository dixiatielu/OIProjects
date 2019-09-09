#include <iostream>
#include <cstdio>
using namespace std;
int n,a[101],ans;
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]) ans++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1)
        {
            ans ++;
        }
    }
    printf("%d",ans);
    return 0;
}
