#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define f first
#define s second

double round3(double var) {
    double value=round(var*1000.0)/1000.0;
    return value;
}

pair<double, double> f(pair<double, double> z, pair<double, double> start) {
    double na=z.f*z.f-z.s*z.s+start.f;
    na=round3(na);
    double nb=2*z.f*z.s+start.s;
    nb=round3(nb);
    return make_pair(na, nb);
}

double absolute(pair<double, double> z) {
    double res=sqrt(z.f*z.f+z.s*z.s);
    res=round3(res);
    return res;
}

int fib[21]={};
bool check_fib(int x) {
    bool ret=false;
    for (int i=1; i<=20; i++) if (x==fib[i]) ret=true;
    return ret;
}

int main()
{
    double x1, y1, x2, y2, inc;
    cin >> x1 >> y1 >> x2 >> y2 >> inc;

    fib[1]=1; fib[2]=1;
    for (int i=3; i<=20; i++) fib[i]=fib[i-1]+fib[i-2];

    int ans=0;
    for (double i=x1; i<=x2+0.0000001; i+=inc) {
        for (double j=y1; j<=y2+0.0000001; j+=inc) {
            i=round3(i); j=round3(j);

            vector<pair<double, double>> path;
            pair<double, double> cur={0, 0};
            path.push_back(cur);
            bool stop=false;
            while (true) {
                cur=f(cur, {i, j});
                if (absolute(cur)>4) break;

                // cycle?
                for (int k=0; k<path.size(); k++) {
                    if (cur==path[k]) {
                        int sz=path.size()-k+1;
                        if (check_fib(sz)) ans++;
                        stop=true;
                        break;
                    }
                }

                path.push_back(cur);
                if (stop) break;
            }
        }
    }

    cout << ans;
}
