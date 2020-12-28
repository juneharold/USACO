// square pasture
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
