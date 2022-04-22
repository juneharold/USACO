#include <iostream>
#include <algorithm>
using namespace std;

int S=0, P=0, F, M, L, ACC;

void TOP(){
    cin >> F >> M >> L;
    ACC=F;
    if (ACC==0) DOWN();
}

void DOWN() {
    ACC=M;
    ACC*=M;
    S=ACC;
    ACC=L;
    ACC*=F;
    ACC*=4;
    P=ACC;
    ACC=S;

}

int main()
{

}
