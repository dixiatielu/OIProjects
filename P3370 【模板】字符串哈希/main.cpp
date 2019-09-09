#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MOD 15146548842656
#define base 131
#define prime 233312
using namespace std;
typedef unsigned long long ull;
int n;
char str[1505];
ull a[10003];
ull zh(char x)
{
    if(x >= 'a' && x <= 'z')
    {
        return (ull)(x - 'a' + 1);
    }
    if(x >= 'A' && x <= 'Z')
    {
        return (ull)(x - 'A' + 27);
    }
    if(x >= '0' && x <= '9')
    {
        return (ull)(x - '0' + 53);
    }
}
/****
a=1
b=2
c=3
d=4
e=5
f=6
g=7
h=8
i=9
j=10
k=11
l=12
m=13
n=14
o=15
p=16
q=17
r=18
s=19
t=20
u=21
v=22
w=23
x=24
y=25
z=26
*****
A=27
B=28
C=29
D=30
E=31
F=32
G=33
H=34
I=35
J=36
K=37
L=38
M=39
N=40
O=41
P=42
Q=43
R=44
S=45
T=46
U=47
V=48
W=49
X=50
Y=51
Z=52
*****
0=53
1=54
2=55
3=56
4=57
5=58
6=59
7=60
8=61
9=62
*****/
ull Hash(char s[])
{
    ull ans = 0;
    for(int k = 0;k <= strlen(s);k++)
    {
        ans = (ans * base + zh(s[k])) % MOD + prime;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%s",str);
        a[i] = Hash(str);
    }
    sort(a + 1,a + n + 1);
    int ans = 1;
    for(int i = 1;i < n;i++)
    {
        if(a[i] != a[i + 1])
            ans++;
    }
    printf("%d",ans);
    return 0;
}
