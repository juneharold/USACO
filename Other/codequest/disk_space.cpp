#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define f first
#define s second

bool leap(int year) {
    if (((year%4==0) && (year%100!=0)) || (year%400==0)) return true;
    return false;
}

struct file{
    int day, month, year, sz;
    bool pm;
    string name;
};

int days[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

double age_days(int day, int month, int year, bool PM) {
    double age=0;
    for (int i=year+1; i<2019; i++) {
        if (leap(i)) age+=366;
        else age+=365;
    }

    if (year==2019) {
        if (month==4) {
            age+=27-day;
        }
        else {
            age+=days[month]-day+27;
            for (int i=month+1; i<4; i++) age+=days[i];
        }
    }
    else {
        age+=days[1]+days[2]+days[3]+27;
        age+=days[month]-day;
        if (month==2 && leap(year)) age+=1;
        for (int i=month+1; i<=12; i++) {
            if (i==2 && leap(year)) age+=days[i]+1;
            else age+=days[i];
        }
    }

    if (PM) return age-0.5;
    else return age;
}

int main()
{
    int N; cin >> N;
    for (int t=0; t<N; t++) {
        //input
        int F; cin >> F;
        double C; cin >> C;
        double need=C*1e6*0.25;
        file files[101];
        for (int i=1; i<=F; i++) {
            int dummy1;
            char dummy2;
            cin >> files[i].day >> dummy2 >> files[i].month >> dummy2 >> files[i].year;
            cin >> dummy1 >> dummy2 >> dummy1;
            string s; cin >> s;
            if (s=="PM") files[i].pm=true;
            else files[i].pm=false;
            cin >> files[i].sz >> files[i].name;
        }

        // solving
        pair<double, pair<string, ll>> scores[101];
        for (int i=1; i<=F; i++) {
            double score=age_days(files[i].day, files[i].month, files[i].year, files[i].pm)*files[i].sz/1000;
            scores[i]={score, {files[i].name, files[i].sz}};
        }

        sort(&scores[1], &scores[F+1]);
        int sum=0;
        for (int i=F; i>=1; i--) {
            cout << scores[i].s.f << " ";
            printf(" %.3lf", scores[i].f);
            cout << "\n";
            sum+=scores[i].s.s;
            if (sum>=need) break;
        }
    }
}
