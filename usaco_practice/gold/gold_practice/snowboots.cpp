#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define f first
#define s second

const int MAX=1e5+2;
int N, B, ans[MAX]={};
set<pair<int, int>> path, parts;
multiset<int> lengths;
struct query{
    int depth, step, q;
};
query boots[MAX];
bool cmp (query a, query b) { return a.depth>b.depth; }

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B;
    for (int i=1; i<=N; i++) {
        int depth; cin >> depth;
        path.insert({depth, i});
        parts.insert({i, i+1});
        lengths.insert(1);
    }
    for (int i=1; i<=B; i++) {
        cin >> boots[i].depth >> boots[i].step;
        boots[i].q=i;
    }

    sort(&boots[1], &boots[B+1], cmp);


    for (int i=1; i<=B; i++) {
        while ((*--path.end()).f>boots[i].depth) {
            auto it=path.end();
            it--;
            auto loc=parts.lower_bound({(*it).s, 0});

            int b=(*loc).s, a=(*--loc).f;

            parts.erase(parts.find({(*it).s, b})); lengths.erase(lengths.find(b-(*it).s));
            parts.erase(parts.find({a, (*it).s}));  lengths.erase(lengths.find((*it).s-a));
            parts.insert({a, b}); lengths.insert(b-a);
            path.erase(it);
        }

        auto maxlen=*--lengths.end();

        if (maxlen<=boots[i].step) ans[boots[i].q]=1;
        else ans[boots[i].q]=0;

    }

    for (int i=1; i<=B; i++) cout << ans[i] << "\n";

}
