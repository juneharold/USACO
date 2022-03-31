#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        for (int i=0; i<s.size(); i++) {
            int num=s[i]-64;
            if (s[i]<'F') {
                num+=6;
            }
            else if (s[i]<'K') {
                num*=num;
            }
            else if (s[i]<'P') {
                int temp=num%3;
                num=temp*5+1;
            }
            else if (s[i]<'U') {
                int temp=num%10;
                num/=10;
                num=(num+temp)*8;
            }
            else {
                int temp=0;
                for (int j=num-1; j>0; j--) if (num%j==0) temp=j;
                num=temp*2;
            }
            cout << (char)(num%26+64);
        }
        cout << "\n";
    }
}
