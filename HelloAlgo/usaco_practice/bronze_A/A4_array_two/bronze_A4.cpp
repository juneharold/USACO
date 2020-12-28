/* Missing Numbers
#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int runners[N-1];
    for (int i=0; i<N-1; i++)
    {
        cin >> runners[i];
    }
    // finding the sum of 1 to N
    int sum=0;
    for (int j=1; j<=N; j++)
    {
        sum += j;
    }
    // finding the sum of elements in runners array
    int sum_r=0;
    for (int k=0; k<N-1; k++)
    {
        sum_r += runners[k];
    }
    // sum - sum_r == missing runner
    printf("%d", sum-sum_r);
}
*/

/* 피시방 알바
#include <iostream>
using namespace std;

int main()
{
    int comp[101]={};
    int N;
    cin >> N;
    int counter = 0;
    for (int i=0; i<N; i++)
    {
        int person;
        scanf("%d ", &person);
        if (comp[person]==0)
        {
            comp[person] = 1;
        }
        else
        {
            counter += 1;
        }
    }
    printf("%d", counter);
}
*/

/* Fence Painting
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    int total = (b-a) + (d-c);
    int intersect = max(min(b, d)-max(a, c), 0);
    cout << total - intersect;
}
*/

/* 알파벳 개수 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int alphabet[26]={};
    string input;
    cin >> input;
    // filling out alphabet array
    for (int i=0; i<input.size(); i++)
    {
        int a = input[i];
        alphabet[a-97] += 1;
    }
    // output
    for (int j=0; j<26; j++)
    {
        printf("%d ", alphabet[j]);
    }
}
*/

/* 알파벳 찾기 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int alphabet[26]={};
    string input;
    cin >> input;
    // filling out alphabet array
    for (int i=1; i<=input.size(); i++)
    {
        int a = input[i-1];
        if (alphabet[a-97]==0)
        {
            alphabet[a-97] = i;
        }
    }
    // output
    for (int j=0; j<26; j++)
    {
        if (alphabet[j]==0)
        {
            printf("%d ", -1);
        }
        else
        {
            printf("%d ", alphabet[j]-1);
        }
    }
}
*/

/* 단어 공부 
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int alphabet[26]={};
    string input;
    cin >> input;
    // filling out alphabet array
    for (int i=0; i<input.size(); i++)
    {
        int a = input[i];
        if (a <= 90)
        {
            alphabet[a-65] += 1;
        }
        else
        {
            alphabet[a-97] += 1;
        }
    }
    // output
    int max = 0, max_index=-2; // ascii code 63==? --> -2+65
    for (int j=0; j<26; j++)
    {
        if (alphabet[j]>max)
        {
            max = alphabet[j];
            max_index = j;
        }
        else if (alphabet[j]==max)
        {
            max_index=-2;
        }
    }
    printf("%c", max_index+65);
}
*/

/* 최댓값
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int numbers[81]={};
    for (int i=0; i<81; i++)
    {
        cin >> numbers[i];
    }
    // strategy: use mod %
    // finding max value
    int max=0, max_index=0;
    for (int j=0; j<81; j++)
    {
        if (numbers[j]>max)
        {
            max = numbers[j];
            max_index = j;
        }
    }
    printf("%d\n", max);
    printf("%d %d", (max_index-(max_index%9))/9+1, max_index%9+1);
}
*/

/* 2차원 배열의 합
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    // N is row, M is column
    int N, M;
    cin >> N >> M;
    // reading given array. 
    int array[90000] = {};
    for (int i=0; i<N*M; i++)
    {
        cin >> array[i];
    }
    int K;
    cin >> K;
    // reading (i, j), (x,y) positions
    int locations[40000] = {};
    for (int k=0; k<4*K; k++)
    {
        cin >> locations[k];
    }
    //
    for (int n=0; n<K; n++)
    {
        int i = locations[4*n], j = locations[4*n+1], x = locations[4*n+2], y = locations[4*n+3];
        // (i-1)*M+(j-1) this is the starting point
        // (x-1)*M+(y-1) this is ending point
        // (y-j) is width
        // (x-i) is height 
        int sum=0;
        // sum from (i-1)*M+(j-1) to (i-1)*M+(j-1) + (y-j)
        // then go from ((i-1)*M+(j-1))+M to ((i-1)*M+(j-1))+M + (y-j)
        for (int row=0; row<=(x-i); row++)
        {
            for (int col=0; col<=(y-j); col++)
            {
                sum += array[((i-1)*M+(j-1)) + row*M + col];
            }
        }
        printf("%d\n", sum);
    }
}
*/