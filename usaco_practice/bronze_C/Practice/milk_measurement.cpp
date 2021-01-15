#include <iostream>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    int N;
    cin >> N;
    pair <pair<int, string>, int> record[100]={};
    for (int i=0; i<N; i++)
    {
        cin >> record[i].first.first >> record[i].first.second >> record[i].second;
    }
    // first-first is day, first-second is the name, second is difference
    sort(record, record+100);
    // find unique names
    string uniqname[100]={};
    for (int i=0; i<N; i++)
    {
        int indicator=0;
        string curname=record[i].first.second;
        for (int j=0; j<N; j++)
        {
            if (curname==record[j].first.second)
            {
                indicator=1;
            }
        }
        if (indicator==0)
        {
            uniqname[i]=curname;
        }
    }
    // now that the day is sorted, it won't matter
    pair<string, int> recs[100]={}; //this is current status
    for (int i=0; i<N; i++)
    {
        recs[i].first=uniqname[i];
        recs[i].second=7;
    }
    // main method
    int display_count = 0;
    pair <string, int> curr("", 0);
    for (int j=0; j<N; j++)
    {
        string name=record[j].first.second;
        for (int k=0; k<N; k++)
        {
            if (recs[k].first==name)
            {
                recs[k].second += record[j].second; //this is the increment
                if (recs[k].second<0)
                {
                    recs[k].second=0;
                }
            }
        }
        // display changes if cows that have max number changes OR the max person changes..
        int max_num=0; // max value
        //first find max num, then see how many cows have max num
        for (int p=0; p<N; p++)
        {
            if (recs[p].second>max_num)
            {
                max_num = recs[p].second;
            }
        }
        int cow_count=0; //number of cows that have the max value
        string name_last;
        for (int p=0; p<N; p++)
        {
            if (recs[p].second==max_num)
            {
                cow_count+=1;
                name_last=recs[p].first;
            }
        }
        if (cow_count!=curr.second)
        {
            curr.second = cow_count;
            curr.first = name_last;
            display_count += 1;
        }
        else if (name_last != curr.first)
        {
            curr.first = name_last;
            curr.second = cow_count;
            display_count += 1;
        }
    }
    cout << display_count << "\n";
}
