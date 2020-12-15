/* 네 점
# include <cstdio>

int main()
{
    int x1,y1;
    int x2, y2;
    int x3, y3;
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    if (x1==x2)
    {
        printf("%d ", x3);
    }
    else if (x1==x3)
    {
        printf("%d ", x2);
    }
    else
    {
        printf("%d ", x1);
    }
    if (y1==y2)
    {
        printf("%d", y3);
    }
    else if (y1==y3)
    {
        printf("%d", y2);
    }
    else
    {
        printf("%d", y1);
    }
}*/

/* 앵그리 창영
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
*/

/* 나는 요리사다
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
*/

/*
# include <cstdio>
# include <cmath>

int main()
{
    int A, B, revA=0, remainderA, revB=0, remainderB;
    scanf("%d %d", &A, &B);
    while (A != 0) 
    {
        remainderA = A % 10;
        revA = revA * 10 + remainderA;
        A /= 10;
    }
    while (B != 0) 
    {
        remainderB = B % 10;
        revB = revB * 10 + remainderB;
        B /= 10;
    }
    if (revA>revB)
    {
        printf("%d", revA);
    }
    else
    {
        printf("%d", revB);    
    }
}
*/

/* 알람 시계
# include <cstdio>

int main()
{
    int H, M;
    scanf("%d %d", &H, &M);
    if (M>=45)
    {
        printf("%d %d", H, M-45);
    }
    else if (M<45 && H>1)
    {
        printf("%d %d", H-1, M+15);
    }
    else if (M<45 && H==0)
    {
        printf("%d %d", 23, M+15);
    }
}
*/
/*
# include <cstdio>
# include <cmath>

int main()
{
    int a, b, x, y;
    scanf("%d %d %d %d", &a, &b, &x, &y);
    if (((abs(x-a)+abs(y-b)) or (abs(y-a)+abs(x-b)))<=abs(a-b))  // if AX +YB or AY +BX <= AB --> use teleport 
    {
        if ((abs(x-a)+abs(y-b)) < (abs(y-a)+abs(x-b)))
        {
            printf("%d", (abs(x-a)+abs(y-b)));
        }
        else
        {
            printf("%d", (abs(y-a)+abs(x-b)));
        }
    }
    else
    {
        printf("%d", abs(a-b));
    }
}*/

/* teleportation
# include <cstdio>
# include <cmath>

int main()
{
    int a, b, t1, t2, p1, p2, t; // p1 = use teleport
    scanf("%d %d %d %d", &a, &b, &t1, &t2);
    if (t1>t2)
    {
        t=t2;
        t2=t1;
        t1=t;
    }
    if (a>b)
    {
        p1=abs(t1-b) + abs(t2-a);
        p2=a-b;
    }
    else 
    {
        p1=abs(t1-a) + abs(t2-b);
        p2=b-a;
    }
    if (p1>p2)
    {
        printf("%d", p2);
    }
    else
    {
        printf("%d", p1);
    }
}
*/

/* square pasture
# include <cstdio>

int main()
{
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int x3, y3, x4, y4;
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
    int mx, my, Mx, My;
    // compare x1, x3 --> mx
    if (x1>x3)
    {
        mx = x3;
    }
    else
    {
        mx = x1;
    }
    // compare x2, x4 --> Mx
    if (x2>x4)
    {
        Mx = x2;
    }
    else
    {
        Mx = x4;
    }
    // compare y1, y3 --> my
    if (y1>y3)
    {
        my = y3;
    }
    else
    {
        my = y1;
    }
    // compare y2, y4 --> My
    if (y2>y4)
    {
        My = y2;
    }
    else
    {
        My = y4;
    }
    // calculate area 
    if ((Mx-mx)>(My-my))
    {
        printf("%d", (Mx-mx)*(Mx-mx));
    }
    else
    {
        printf("%d", (My-my)*(My-my));
    }   
}
*/

/* 주사위
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
*/


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
