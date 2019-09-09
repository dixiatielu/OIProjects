#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n;
bool x;
int main()
{
    scanf("%lld",&n);
    while(n)
    {
        if(!(n & 1) && x)
            n = (n >> 1) - 1;
        else
            n >>= 1;
        x = !x;
    }
    if(x)
    {
        printf("Aoki\n");
    }
    else
    {
        printf("Takahashi\n");
    }
    return 0;
}
