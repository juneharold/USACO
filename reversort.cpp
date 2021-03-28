#include <iostream>
#include <algorithm>
using namespace std;
/*
Reversort(int L)
{
    for (int i=1; i<=L.size()-1; i++)
    {
        int min=L[i];
        int index=i;
        for (int j=i; j<=L.size(); j++)
        {
            if (L[j]<min) index=j;
        }
        swap(L[index], L[i]);
        counter+= index-i+1;
    }
}*/


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int c=1; c<=t; c++)
    {
        int N; cin >> N;
        int arr[105]={};
        for (int a=1; a<=N; a++) cin >> arr[a];
        int counter=0;
        // reversort
        for (int i=1; i<=N-1; i++)
        {
            int min=arr[i];
            int index=i;
            for (int j=i; j<=N; j++)
            {
                if (arr[j]<min)
                {
                    min=arr[j];
                    index=j;
                }
            }
            if (arr[index]<arr[i]) reverse(arr+i, arr+index+1);
            counter+=index-i+1;
        }
        cout << "Case #" << c << ": " << counter << "\n";
    }
}

/*
3
4
1 3 4 2
2
1 2
7
7 6 5 4 3 2 1

Case #1: 1 3 4 2
Case #2: 1 2
Case #3: 1 2 3 5 7 6 4

*/
