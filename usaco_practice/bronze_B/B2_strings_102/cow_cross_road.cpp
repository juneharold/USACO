// Why Did the Cow Cross the Road II (Bronze)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    // divide by 2 in the end...
    string position;
    cin >> position; // length 52
    int counter = 0;
    for (int i=0; i<52; i++)
    {
        char pos1=position[i]; //pos1 is character
        int index1A=position.find(pos1);
        int index1B=position.find_last_of(pos1); // this finds the last index of the argument string
        // we found indexes of the first cow.
        for (int k=0; k<52 && k!=index1A && k!=index1B; k++)
        {
            char pos2=position[k];
            int index2A = position.find(pos2);
            int index2B = position.find_last_of(pos2);
            if (index1A < index2A && index1B < index2B && index2A < index1B)
            {
                counter += 1;
            }
            else if (index2A < index1A && index2B < index1B && index1A < index2B)
            {
                counter += 1;
            }
        }
    }
    cout << counter/2;
}
