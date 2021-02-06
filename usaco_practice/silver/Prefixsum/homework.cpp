#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int input[100005]={};
int MIN[100005]={};
int hw[100005]={}; //this is PFS

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> ans;
    int N;
    cin >> N;
    int sum=0; 
    for (int i=1; i<=N; i++)
    {
        int a;
        cin >> a;
        input[i]=a;
        sum+=a;
        hw[i]=sum;
    }
    int min=1e6;
    for (int i=N; i>=1; i--)
    {
        if (input[i]<min)
        {
            min=input[i];
        }
        MIN[i]=min;
    }
    double MAXavg=0;
    for (int i=1; i<=N-2; i++)
    {
        int SUM=hw[N]-hw[i]-MIN[i+1];
        double avg=(double)SUM/(N-i-1);
        if (avg>MAXavg)
        {
            MAXavg=avg;
            ans.clear();
            ans.push_back(i);
        }
        else if (avg==MAXavg)
        {
            ans.push_back(i);
        }
    }
    for (int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

