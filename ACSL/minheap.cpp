/* 문자열을 입력하면 min heap을 그려주는 툴. */
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int heap[100005]={}, idx=1;

void Add(int cur) {
    int nx;
    if (cur%2==1) nx=(cur-1)/2;
    else nx=cur/2;
    if (nx!=0 && heap[nx]>heap[cur]) {
        swap(heap[nx], heap[cur]);
        Add(nx);
    }
}

char ans[7][100005];
void Print(int cur, int d, int start, int end) {
    int i=(start+end)/2;
    ans[d][i]=(heap[cur]+'A'-1);
    int nx1=cur*2, nx2=cur*2+1;
    if (heap[nx1]!=0) Print(nx1, d+1, start, i);
    if (heap[nx2]!=0) Print(nx2, d+1, i, end);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s; cin >> s;
    for (char x: s) {
        int num=x-'A'+1;
        heap[idx]=num;
        Add(idx);
        idx++;
    }
    fill(&ans[0][0], &ans[6][100000], ' ');

    Print(1, 1, 0, idx);
    for (int i=1; i<=4; i++) {
        for (int j=0; j<=idx+10; j++) cout << '-';
        cout << "\n";
        cout << "Depth " << i-1 << ": ";
        for (int j=0; j<=idx; j++) cout << ans[i][j];
        cout << "\n";
    }
    for (int j=0; j<=idx+10; j++) cout << '-';
}

//ICECREAMSUNDAE
