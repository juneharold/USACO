// 상수 
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