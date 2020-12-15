/* factorial 
# include <cstdio>

int main()
{
    int a;
    scanf("%d", &a);
    int b=1;
    for (int i=1; i<=a; i++)
    {
        b = b * i;
    }
    printf("%d", b);
}*/

/*to the power of k
# include <cstdio>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a = 1;
    for (int i=1; i<=k; i++)
    {
        a *= n;
    }
    printf("%d", a);
}*/

/* 
# include <cstdio>

int main()
{
    int N;
    scanf("%d", &N);
    int mid = N/2 + 1;
    if (N == 1)
    {
        int a;
        scanf("%d", &a);
        printf("%d %d %d", a, a, a);
    }
    else
    {
        for (int i=1; i <= N; i++)
    {
        int a;
        scanf("%d", &a);
        if (i==1 or i==mid or i==N)
        {
            printf("%d ", a);
        }
    }
    }
}*/

/* 홀수 짝수 
# include <cstdio>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans = 0;
    for (int i=a; i<=b; i++)
    {
        if (i==a and a%2==0)
        {
            printf("%d", i);
        }
        else if (i%2==0)
        {
            ans -= i;
            printf("-%d", i);
        }
        else
        {
            ans += i;
            printf("+%d", i);
        }
        
    }
    printf("=%d", ans);
} */

/* 기억력 테스트

# include <cstdio>

int main()
{
    int a[9];
    for (int i=0; i<10; i++)
    {
        scanf("%d ", &a[i]);
    }
    int k;
    scanf("%d", &k);
    printf("%d", a[k-1]);
}*/

/* 배열 두 번
# include <cstdio>

int main()
{
    int k;
    scanf("%d", &k);
    int arr[k];
    for (int i=0; i<k; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<k; i++)
    {
        printf("%d\n", arr[i]);
    }
    for (int i=0; i<k; i++)
    {
        printf("%d\n", arr[i]);
    }
}*/

/* 거꾸로 출력 
# include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i=n-1; i>=0; i--)
    {
        printf("%d ", arr[i]);
    }
} */

/*
# include <cstdio>
# include <string>
using namespace std;

int main()
{
    string a;
    scanf("%s", &a);
    printf("%s", a.length());
}*/

/* 숫자 거꾸로
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    for (int i=a.size()-1; i>=0; i--)
    {
        cout << a[i];
    }
}*/

/*
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    if (a=="love")
    {
        cout << "I love you.";
    }
}*/

/* t 찾기 
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string a;
    char b = "t";
    cin >> a;
    for (int i=0; i<=a.size()-1; i++)
    {
        if (a[i]==b)
        {
            cout << i+1;
        }
    }
}*/

/* 대소문자 변환
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    for (int i=0; i<=a.size()-1; i++)
    {
        if (isupper(a[i])==0)
        {
            printf("%c", toupper(a[i]));
        }
        else
        {
            printf("%c", tolower(a[i]));
        }
        
    }
} */

/*
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string id;
    cin >> id;
    printf("welcome! ");
    cout << id;
}*/

# include <iostream>
# include <string>
using namespace std;

int main()
{
    string s1;
    string s2;
    string s3;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    if (s1[s1.size()-1]==s2[0] and s2[s2.size()-1]== s3[0] and s3[s3.size()-1]== s1[0])
    {
        printf("good");
    }
    else
    {
        printf("bad");
    }
}




