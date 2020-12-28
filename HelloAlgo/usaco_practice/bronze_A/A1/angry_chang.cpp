// 앵그리 창영 
# include <cstdio>
# include <cmath>

int main()
{
    int N, W, H;
    scanf("%d %d %d", &N, &W, &H);
    int max;
    max = sqrt(W*W+H*H);
    for (int i=1; i<=N; i++)
    {
        int a;
        scanf("%d", &a);
        if (max>=a)
        {
            printf("DA\n");
        }
        else
        {
            printf("NE\n");
        }
    }
}
