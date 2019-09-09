#include <iostream>
#include <cstdio>
#define reg register
#define IL inline
#define ll long long
using namespace std;
ll n,m,k,x;
ll ksm(ll a,ll z)
{
    int ans = 1,base = a;
    while(z)
    {
        if(z & 1)
        {
            ans = ans * base % n;
        }
        base = base * base % n;
        z >>= 1;
    }
    return ans;
}
int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%lld%lld%lld%lld",&n,&m,&k,&x);
	printf("%lld",(x % n + m % n * ksm(10,k) % n) % n);
    return 0;
}
