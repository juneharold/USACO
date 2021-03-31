#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int c=1; c<=t; c++)
    {
        int N, L;
        cin >> N >> L;
        int max_cost=(N*(N+1))/2 -1;
        int min_cost=N-1;
        if (L>max_cost or min_cost>L)
        {
            cout << "Case #" << c << ": " << "IMPOSSIBLE" << "\n";
            continue;
        }
        int arr[10]={};
        // use next_permutation
        for (int i=1; i<=N; i++)
        {
            arr[i]=i;
        }
        sort(&arr[1], &arr[N+1]);
        int indicator=0;
        do {
            int counter=0;
            int arr2[10]={};
            for (int i=1; i<=N; i++) arr2[i]=arr[i];
            // reversort
            for (int i=1; i<=N-1; i++)
            {
                int min=arr2[i];
                int index=i;
                for (int j=i; j<=N; j++)
                {
                    if (arr2[j]<min)
                    {
                        min=arr2[j];
                        index=j;
                    }
                }
                if (arr2[index]<arr2[i]) reverse(arr2+i, arr2+index+1);
                counter+=index-i+1;
            }
            if (counter==L)
            {
                cout << "Case #" << c << ": ";
                for (int i=1; i<=N; i++) cout << arr[i] << " ";
                cout << "\n";
                indicator=1;
                break;
            }
        } while(next_permutation(&arr[1], &arr[N+1]));
        if (indicator==0) cout << "Case #" << c << ": " << "IMPOSSIBLE" << "\n";
    }
}

/*
5
4 6
2 1
7 12
7 2
2 1000

1
4 6
*/
