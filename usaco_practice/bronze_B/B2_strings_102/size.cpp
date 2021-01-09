//덩치 
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int weight[50]={}, height[50]={};
    for (int i=0; i<N; i++)
    {
        cin >> weight[i] >> height[i];
    }
    // double loop?
    int rank[50]={};
    for (int a=0; a<N; a++)
    {
        int smaller_than=0;
        for (int b=0; b<N; b++)
        {
            if (weight[b]>weight[a] && height[b]>height[a] && b!=a)
            {
                smaller_than += 1;
            }
        }
        rank[a] = smaller_than;
    }
    // going over rank
    for (int k=0; k<N; k++)
    {
        cout << rank[k]+1 << " ";
    }
}
