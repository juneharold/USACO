/* 유학 금지
# include <cstdio>
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string word;
    cin >> word;
    int size = word.size();
    for (int t=0; t<size; t++)
    {
        for (int i=0; i<word.size(); i++)
        {
            for (int k=0; k<9; k++)
            {
                if (word[i] == "CAMBRIDGE"[k])
                {
                    word.erase(i, 1);
                }
            }
        }
    }
    cout << word;
}
*/

/* KMP
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string long_form;
    cin >> long_form;
    for (int i=0; i<long_form.size(); i++)
    {
        if (i==0)
        {
            cout << long_form[0];
        }
        if (long_form[i]=='-')
        {
            cout << long_form[i+1];
        }
    }
}
*/

/* JOI와 IOI
# include <iostream>
# include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int joi=0, ioi=0;
    for (int i; i<input.size(); i++)
    {
        if (input[i]=='J' && input[i+1]=='O' && input[i+2]=='I')
        {
            joi += 1;
        }
        else if (input[i]=='I' && input[i+1]=='O' && input[i+2]=='I')
        {
            ioi += 1;
        }
    }
    cout << joi << endl;
    cout << ioi << endl;
}
*/

/*아스키 코드
#include <iostream>
#include <string>
using namespace std;

int main()
{
    char input;
    cin >> input;
    printf("%d", input);
}
*/

/*입실 요원
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        string a;
        cin >> a;
        for (int i=0; i<a.size(); i++)
        {
            int b=a[i];
            if(b>64 and b<=90)
            {
                printf("%c", b+32);
            }
            else
            {
                printf("%c", b);
            }
        }
        printf("\n");
    }
}
*/
/*FBI
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 0;
    for(int i=0; i<5; i++)
    {
        string code;
        cin >> code;
        for (int j=0; j<code.size(); j++)
        {
            if (code[j]=='F' and code[j+1]=='B' and code[j+2]=='I')
            {
                printf("%d ", i+1);
                num += 1;
                break;
            }
        }
    }
    if (num==0)
    {
        printf("HE GOT AWAY!");
    }
}
*/

/*알파벳 거리 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        string a, b;
        cin >> a;
        cin >> b;
        printf("Distances: ");
        for (int j=0; j<a.size(); j++)
        {
            int p=a[j], q=b[j];
            if (q>=p)
            {
                printf("%d ", q-p);
            }
            else
            {
                printf("%d ", 26+q-p);
            }
        }
        printf("\n");
    }
}
*/

/*문자열 반복
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int i=0; i<N; i++)
    {
        int R;
        cin >> R;
        string S;
        cin >> S;
        for (int j=0; j<S.size(); j++)
        {
            for (int k=0; k<R; k++)
            {
                printf("%c", S[j]);
            }
        }
        printf("\n");
    }
}
*/
/* 창영마을 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cin >> a;
    int x=1, y=0, z=0;
    for (int i=0; i<a.size(); i++)
    {
        if (a[i]=='A')
        {
            int t;
            t=x;
            x=y;
            y=t;
        }
        else if (a[i]=='B')
        {
            int t;
            t=y;
            y=z;
            z=t;
        }
        else
        {
            int t;
            t=x;
            x=z;
            z=t;
        }
    }
    if (x==1)
    {
        printf("1");
    }
    else if (y==1)
    {
        printf("2");
    }
    else
    {
        printf("3");
    } 
}
*/

/* 컵홀더 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int per;
    cin >> per;
    string seats;
    cin >> seats;
    int cupholder = 1;
    int i = 0;
    while (i<seats.size()){
        if (seats[i]=='S'){
            cupholder += 1;
            i += 1;
        }
        else if (seats[i]=='L' and seats[i+1]=='L'){
            cupholder += 1;
            i += 2;
        }
    }
    if (cupholder>per){
        printf("%d", per);
    }
    else{
        printf("%d", cupholder);
    }
}
*/
