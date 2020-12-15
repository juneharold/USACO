# include <cstdio>

int main()
{
    int a[10];
    for (int i=1; i<=10; i++)
    {
        scanf("%d ", &a[i]);
    }
    int k;
    scanf("%d", &k);
    printf("%d", &a[k]);
}