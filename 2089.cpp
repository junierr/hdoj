#include<cstdio>
int a[1000005];
int fun(int x)
{
    while(x != 0)
    {
        if(x % 100 == 62 || x % 10 == 4)
            return 0;
        x /= 10;
    }
    return 1;
}
int main()
{
    int n, m;
    a[0] = 0;
    for(int i = 1; i <= 1000005; i++)
            a[i] = a[i - 1] + fun(i - 1);
    while(scanf("%d %d", &n, &m) != EOF &&(n != 0 || m != 0))
        printf("%d\n", a[m] - a[n] + fun(m));
    return 0;
}
