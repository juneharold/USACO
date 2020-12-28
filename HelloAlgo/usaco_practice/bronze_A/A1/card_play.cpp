// 카드놀이 
# include <cstdio>

int main()
{
    int a1, a2, a3, a4, a5, a6, a7, a8, a9, a10;
    scanf("%d %d %d %d %d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6, &a7, &a8, &a9, &a10);
    int b1, b2, b3, b4, b5, b6, b7, b8, b9, b10;
    scanf("%d %d %d %d %d %d %d %d %d %d", &b1, &b2, &b3, &b4, &b5, &b6, &b7, &b8, &b9, &b10);
    int A_score=0, B_score=0, last_winner=0; // last winner: 1 is A, 2 is B
    // round 1
    if (a1>b1)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b1>a1)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 2
    if (a2>b2)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b2>a2)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 3
    if (a3>b3)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b3>a3)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 4
    if (a4>b4)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b4>a4)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 5
    if (a5>b5)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b5>a5)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 6
    if (a6>b6)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b6>a6)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 7
    if (a7>b7)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b7>a7)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 8
    if (a8>b8)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b8>a8)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 9
    if (a9>b9)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b9>a9)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // round 10
    if (a10>b10)
    {
        A_score += 3;
        last_winner = 1;
    }
    else if (b10>a10)
    {
        B_score += 3;
        last_winner = 2;
    }
    else
    {
        A_score += 1;
        B_score += 1;
    }
    // results
    if (A_score>B_score)
    {
        printf("%d %d\n", A_score, B_score);
        printf("A");
    }
    else if (B_score>A_score)
    {
        printf("%d %d\n", A_score, B_score);
        printf("B");
    }
    else
    {
        printf("%d %d\n", A_score, B_score);
        if (last_winner==1)
        {
            printf("A");
        }
        else if (last_winner==2)
        {
            printf("B");
        }
        else
        {
            printf("D");
        }
    }
}
