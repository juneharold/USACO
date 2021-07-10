#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N=1005;
int n;
struct Cow {
    int x, y, id;
    char dir;
};

bool sortX(Cow A, Cow B){
	return A.x < B.x;
}
bool sortY(Cow A, Cow B){
	return A.y < B.y;
}

int main()
{
    cin >> n;
    vector<Cow> north;
    vector<Cow> east;
    for (int i=1; i<=n; i++) {
        char d; int a, b;
        cin >> d >> a >> b;
        if (d=='N') {
            Cow temp;
            temp.x=a, temp.y=b, temp.id=i, temp.dir=d;
            north.push_back(temp);
        }
        if (d=='E') {
            Cow temp;
            temp.x=a, temp.y=b, temp.id=i, temp.dir=d;
            east.push_back(temp);
        }
    }

    sort(north.begin(), north.end(), sortX);
    sort(east.begin(), east.end(), sortY);

    int blame[MAX_N]={};
    int stop[MAX_N]={};

    for (auto i: east) {
        for (auto j:north) {
            if(!stop[i.id] && !stop[j.id] && i.y >= j.y && i.x <= j.x){
				int xlen=j.x-i.x;
				int ylen=i.y-j.y;

				if(ylen < xlen){
					stop[i.id]=1;
					blame[j.id]+=1+blame[i.id];
				}
				else if(ylen > xlen){
					stop[j.id]=1;
					blame[i.id]+=1+blame[j.id];
				}
			}
        }
    }

    for (int i=1; i<=n; i++) cout << blame[i] << "\n";
}
