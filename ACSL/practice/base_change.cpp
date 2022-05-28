#include <iostream>
using namespace std;

void decToOctal(int n)
{
    int octalNum[100], i = 0;
    while (n != 0) {
        octalNum[i] = n % 8;
        n = n / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) cout << octalNum[j];
}

void decToHexa(int n)
{
    char hexaDeciNum[100];
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) cout << hexaDeciNum[j];
}

int arr[105]={};
void fib() {
    arr[1]=0; arr[2]=1;
    for (int i=3; i<=100; i++) {
        arr[i]=arr[i-1]+arr[i-2];
    }

    for (int i=1; i<=20; i++) {
        decToHexa(arr[i]);
        cout << "\n";
    }
}

int main()
{
    fib();
    decToHexa(144);
}
