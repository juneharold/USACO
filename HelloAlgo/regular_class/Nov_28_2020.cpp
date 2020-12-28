#include <cstdio>

int main()
{
    int a, b, c;
    int answer1 = 1;
    int i = 1;
    scanf("%d %d", &a, &b);
    while (true)
    {
        if (a%i==0 and b%i==0)
        {
            answer1 = i;
        }
        if (i == a or i == b)
        {
            break;
        }
        i++;
    }
    printf("%d\n", answer1);
    int k = a;
    int answer2 = a;
    while (true)
    {
        if (k%a==0 and k%b==0)
        {
            answer2 = k;
            break;
        }
        k++;
    }
    printf("%d", answer2);
}

