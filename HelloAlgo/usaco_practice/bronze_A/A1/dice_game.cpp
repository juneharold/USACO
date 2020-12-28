// 주사위 게임 
# include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    int max=0;
    for (int i=0; i<=N; i++)
    {
        int a, b, c, money;
        scanf("%d %d %d", &a, &b, &c);
        if (a==b and b==c and c==a)
        {
            money = 10000+a*1000;
        }
        else if(a==b)
        {
            money = 1000+a*100;
        }
        else if(b==c)
        {
            money = 1000+b*100;
        }
        else if(c==a)
        {
            money = 1000+a*100;
        }
        else
        {
            if (a>=b and a>=c)
            {
                money = a*100;
            }
            else if (b>=a and b>=c)
            {
                money = b*100;
            }
            else
            {
                money = c*100;
            }   
        }
        // if money >max
        if (money>max)
        {
            max=money;
        }
    }
    printf("%d", max);
}
