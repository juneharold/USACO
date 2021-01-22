#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    int N;
    cin >> N;
    pair <int, pair<string, int> > record[100]={};
    for (int i=0; i<N; i++)
    {
        cin >> record[i].first >> record[i].second.first >> record[i].second.second;
    }
    // first is day, second-first is the name, second-second is difference
    sort(record, record+N);
    // now that the day is sorted, it won't matter
    pair<string, int> recs[100]={}; //this is current status
    for (int i=0; i<N; i++)
    {
        recs[i].first=record[i].second.first;
        recs[i].second=7;
    }
    // main method
    int display_count = 0;
    pair <string, int> currdis("", 0); //display cow name, num cows
    for (int j=0; j<N; j++)
    {
        string name=record[j].second.first;
        for (int k=0; k<N; k++)
        {
            if (recs[k].first==name)
            {
                recs[k].second += record[j].second.second; //this is the increment only add to first occurence of name
                break;
            }
        }
        if (record[j].second.second==0)
        {
            continue;
        }
        // display changes if cows that have max number changes OR the max person changes..
        int max_num=0; // max milk out
        //first find max num, then see how many cows have max num
        for (int p=0; p<N; p++)
        {
            if (recs[p].second>=max_num)
            {
                max_num = recs[p].second;
            }
        }
        int cow_count=0; //number of cows that have the max value
        string name_last="";
        for (int p=0; p<N; p++)
        {
            if (recs[p].second==max_num)
            {
                cow_count+=1;
                name_last=recs[p].first;
            }
        }
        if (cow_count!=currdis.second)
        {
            currdis.first = name_last;
            currdis.second = cow_count;
            display_count += 1;
        }
        else if (name_last != currdis.first)
        {
            currdis.first = name_last;
            currdis.second = cow_count;
            display_count += 1;
        }
    }
    cout << display_count << "\n";
}
