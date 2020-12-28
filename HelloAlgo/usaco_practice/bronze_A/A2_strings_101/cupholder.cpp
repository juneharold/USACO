// 컵홀더 
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int per;
    cin >> per;
    string seats;
    cin >> seats;
    int cupholder = 1;
    int i = 0;
    while (i<seats.size()){
        if (seats[i]=='S'){
            cupholder += 1;
            i += 1;
        }
        else if (seats[i]=='L' and seats[i+1]=='L'){
            cupholder += 1;
            i += 2;
        }
    }
    if (cupholder>per){
        printf("%d", per);
    }
    else{
        printf("%d", cupholder);
    }
}
