#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int t; cin >> t;
  for (int c=1; c<=t; c++)
  {
    int N, K; cin >> N >> K;
    int minutes[100005]={};
    for (int i=0; i<N; i++) cin >> minutes[i];
    int diff[100005]={};
    for (int i=0; i<N-1; i++)
    {
      diff[i]=minutes[i+1]-minutes[i];
    }
    sort(diff, diff+(N-1));
    int max=diff[N-2];
    int index=N-1;
    for (int i=0; i<K; i++)
    {
      if (max%2==0)
      {
        diff[index-1]=max/2;
        diff[index]=max/2;
      }
      else
      {
        diff[index-1]=max/2;
        diff[index]=max/2+1;
      }
      sort(diff, diff+(index+1));
      index++;
    }
    cout << "Case #" << c << ": " << diff[index-1] << "\n";
  }
}
