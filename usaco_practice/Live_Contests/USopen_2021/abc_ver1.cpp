#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int t=0; t<T; t++)
    {
        int N; cin >> N;
        int num[10]={};
        for (int i=0; i<N; i++) cin >> num[i];
        sort(num, num+N);
        int counter=0;
        for (int a=0; a<=100; a++) {
            for (int b=a; b<=100; b++) {
                for (int c=b; c<=100; c++) {
                    int checker=0;
                    for (int i=0; i<N; i++) {
                        if (num[i]==a or num[i]==b or num[i]==c) checker++;
                        else if (num[i]==a+b or num[i]==b+c or num[i]==c+a) checker++;
                        else if (num[i]==a+b+c) checker++;
                    }
                    if (checker==N) counter++;
                }
            }
        }
        cout << counter << "\n";
    }
}
