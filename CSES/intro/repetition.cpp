#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string input;
    cin >> input;
    char recent=input[0];
    int counter=0;
    long long max=0;
    for (int i=1; i<input.size(); i++)
    {
        if (recent==input[i]) 
        {
            counter++;
            if (counter>max) max=counter;
        }
        else 
        {
            counter=0;
            recent=input[i];
        }
    }
    cout << max+1;
}
