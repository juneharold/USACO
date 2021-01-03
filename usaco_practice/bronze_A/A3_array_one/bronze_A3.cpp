/*수 정렬하기 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int a[N];
    for (int i=0; i<N; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+N);
    for (int i=0; i<N; i++){
        printf("%d\n", a[i]);
    }
}
*/

/* 거북이
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int sides[4];
    for (int i=0; i<4; i++){
        scanf("%d ", &sides[i]);
    }
    sort(sides, sides+4);
    printf("%d", sides[0]*sides[2]);
}
*/

/* 음계
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int sounds[8];
    for (int i=0; i<8; i++)
    {
        scanf("%d ", &sounds[i]);
    }
    int counter=0;
    for (int j=1; j<8; j++)
    {
        if (sounds[j-1] > sounds[j])
        {
            counter += 1;
        }
    }
    if (counter == 7)
    {
        printf("descending");
    }
    else if (counter == 0)
    {
        printf("ascending");
    }
    else
    {
        printf("mixed");
    }
}
*/

/* 수빈이와 수열 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int sequence[N]; // this is sequence B
    for (int i=0; i<N; i++)
    {
        scanf("%d ", &sequence[i]);
    }
    printf("%d ", sequence[0]);
    for (int j=2; j<=N; j++)
    {
        printf("%d ", sequence[j-1]*j-sequence[j-2]*(j-1));
    }
}
*/

/* FUNGHI
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int slices[11];
    for (int i=0; i<8; i++)
    {
        scanf("%d", &slices[i]);
    }
    // appending slices at index 0, 1, 2 at the back. 
    for (int k=0; k<3; k++)
    {
        slices[k+8] = slices[k];
    }
    // finding the max number of mushrooms
    int max=0;
    for (int j=0; j<8; j++)
    {
        if (slices[j]+slices[j+1]+slices[j+2]+slices[j+3] > max)
        {
            max = slices[j]+slices[j+1]+slices[j+2]+slices[j+3];
        }
    }
    printf("%d", max);
}
*/

/* OX 퀴즈
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for (int test_case=0; test_case<N; test_case++)
    {
        string pattern;
        cin >> pattern;
        int results=0, point=1;
        for (int i=0; i<pattern.size(); i++)
        {
            if (pattern[i]=='O')
            {
                results += point;
                point += 1;
            }
            else
            {
                point = 1;
            }
        }
        cout << results << endl;
    }
}
*/

/* 점수 계산 
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int pattern[N];
    for (int j=0; j<N; j++)
    {
        scanf("%d ", &pattern[j]);
    }
    int results=0, point=1;
    for (int i=0; i<N; i++)
    {
        if (pattern[i]==1)
        {
            results += point;
            point += 1;
        }
        else
        {
            point = 1;
        }
    }
    cout << results << endl;
}
*/

/* cow routing
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    // declaring min_price
    int min_price=1001;
    // 
    for (int i=0; i<N; i++)
    {
        int price, num_cities;
        cin >> price >> num_cities;
        int cities[num_cities];
        for (int j=0; j<num_cities; j++)
        {
            cin >> cities[j];
        }
        // check if A and B in cities
        int counter=0;
        for (int k=0; k<num_cities; k++)
        {
            if (cities[k]==A and counter==0)
            {
                counter=1;
            } 
            if (cities[k]==B and counter==1)
            {
                counter=2;
            }
        }
        if (counter==2 and min_price > price) 
        {
            min_price=price;
        }
    }
    if (min_price==1001)
    {
        printf("%d", -1);
    }
    else
    {
        printf("%d", min_price);
    }
}
*/

// Mixing milk
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int c1, m1, c2, m2, c3, m3;
    cin >> c1 >> m1;
    cin >> c2 >> m2;
    cin >> c3 >> m3;
    for (int i=1; i<=33; i++)
    {
        // operation from c1 to c2
        if (c2-m2>=m1)
        {
            m2 += m1;
            m1 = 0;
        }
        else
        {
            m1 -= (c2-m2);
            m2 = c2;
        }
        // operation from c2 to c3
        if (c3-m3>=m2)
        {
            m3 += m2;
            m2 = 0;
        }
        else
        {
            m2 -= (c3-m3);
            m3 = c3;
        }
        // operation from c3 to c1
        if (c1-m1>=m3)
        {
            m1 += m3;
            m3 = 0;
        }
        else
        {
            m3 -= (c1-m1);
            m1 = c1;
        }
    }
    // the hundreth operation
    if (c2-m2>=m1)
    {
        m2 += m1;
        m1 = 0;
    }
    else
    {
        m1 -= (c2-m2);
        m2 = c2;
    }
    // printing answersss
    printf("%d\n", m1);
    printf("%d\n", m2);
    printf("%d\n", m3);
}



