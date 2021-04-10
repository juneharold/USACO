#include <iostream>
#include <algorithm>
using namespace std;

int M[100005]={}; //first는 max second는 min;
int m[100005]={};

pair <int, int> Mm[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i=0; i<n; i++)
    {
        int len; cin >> len;
        int max=0, min=1e9;
        for (int j=0; j<len; j++) {
            int num; cin >> num;
            if (num>max) max=num;
            if (num<min) min=num;
        }
        //M[i]=max;
        //m[i]=min;
        Mm[i].first=max;
        Mm[i].second=min;
    }
    //sort(M, M+n);
    //sort(m, m+n);
    sort(Mm, Mm+n);
    long long counter=0;
    for (int i=0; i<n; i++)
    {
        int Ai=Mm[i].second; // Ai<Aj
        int pos=upper_bound(&Mm[0], &Mm[n], make_pair(Ai+1, 0))-&Mm[0];
        cout << Ai << " " << n-pos << "\n";
        int Aj=Mm[pos].first;
        counter+=n-pos;
    }
    cout << counter;
}
