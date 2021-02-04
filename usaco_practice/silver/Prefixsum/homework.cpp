#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int input[100005]={};
int hw[100005]={}; //this is PFS

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> ans;
    int N;
    cin >> N;
    for (int i=1; i<=N; i++)
    {
        cin >> input[i];
    }
    int sum=0; 
    for (int i=1; i<=N; i++)
    {
        sum+=input[i];
        hw[i]=sum;
    }
    
}

