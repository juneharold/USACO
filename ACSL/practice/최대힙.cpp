#include <iostream>
using namespace std;

int heap[100005]={}, idx=1;

void Add(int cur) {
    int nx;
    if (cur%2==1) nx=(cur-1)/2;
    else nx=cur/2;
    if (nx!=0 && heap[nx]<heap[cur]) {
        swap(heap[nx], heap[cur]);
        Add(nx);
    }
}

void Delete(int cur) {
    int nx1=cur*2, nx2=cur*2+1;
    if (nx2<=idx) {
        if (heap[nx1]>heap[nx2] && heap[nx1]>heap[cur]) {
            swap(heap[cur], heap[nx1]);
            Delete(nx1);
        }
        else if (heap[nx2]>heap[cur]){
            swap(heap[cur], heap[nx2]);
            Delete(nx2);
        }
    }
    else if (nx1<=idx && nx2>idx) {
        if (heap[nx1]>heap[cur]) {
            swap(heap[cur], heap[nx1]);
            Delete(nx1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    while (N--) {
        int x; cin >> x;
        if (x==0 && idx==1) cout << 0 << "\n";
        else if (x==0) {
            cout << heap[1] << "\n";
            idx--;
            heap[1]=heap[idx];
            heap[idx]=0;
            Delete(1);
        }
        else {
            heap[idx]=x;
            Add(idx);
            idx++;
        }
    }
}
