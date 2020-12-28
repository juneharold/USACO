// 나는 요리사다
# include <cstdio>

int main()
{
    int score = 0;
    int player = 0;
    for (int i=1; i<=5; i++)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (score<(a + b + c + d))
        {
            score = (a + b + c + d);
            player = i;
        }
    }
    printf("%d %d", player, score);
}
