#include <cstdio>
using namespace std;
long long d[600][600][600];
long long w(long long a,long long b,long long c)
{
    if(a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if(d[a][b][c])
        return d[a][b][c];
    else if(a > 20 || b > 20 || c>20)
        d[a][b][c] = w(20,20,20);
    else if(a < b && b < c)
        d[a][b][c] = w(a,b,c - 1) + w(a,b - 1,c - 1) - w(a,b - 1,c);
    else
        d[a][b][c] = w(a - 1,b,c) + w(a - 1,b - 1,c) + w(a - 1,b,c - 1) - w(a - 1,b - 1,c - 1);
    return d[a][b][c];
}
int main()
{
    long long a,b,c;
    while(1)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        if(a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
    }
    return 0;
}
