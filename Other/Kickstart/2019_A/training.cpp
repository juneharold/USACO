#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t; cin >> t;
    for (int c=1; c<=t; c++) {
        int N, P; cin >> N >> P;
        int students[100005]={};
        for (int i=0; i<N; i++) cin >> students[i];
        sort(students, students+N);
        int need=students[P-1];
        int sum=0;
        for (int i=0; i<P; i++) {
            sum+=need-students[i];
        }
        cout << "Case #" << c << ": " << sum << "\n";
    }
    return 0;
}
