#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
int n,x;
ll a[100007],ate;
int main()
{
    scanf("%d %d",&n,&x);
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i = 1;i < n;i++)
    {
        if(a[i] + a[i + 1] > x)
        {
            a[i + 1] = x - a[i];
            ate = ate + a[i] + a[i + 1] - x;
        }
    }
    cout << ate;
    return 0;
}
