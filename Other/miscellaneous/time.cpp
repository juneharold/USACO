#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

int main()
{
    auto start = high_resolution_clock::now();
    for (int i=1; i<=1000000; i++) {
        cout << i << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << (double)duration.count()/1000000.0;
    return 0;
}
