#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
#define f first
#define s second
typedef long long ll;
const int nmax=2e5+5, sqrmax=635, MOD=1e9+7;

int prime[52]={};

bool check_prime(int x) {
    for (int i=2; i<x; i++) {
        if (x%i==0) return false;
    }
    return true;
}

void find_prime() {
    int idx=0;
    for (int i=2; i<10000; i++) {
        if (check_prime(i)) {
            prime[idx]=i;
            idx++;
        }
        if (idx==52) break;
    }
}

vector<pair<int, int>> Hash[600011]={};

int main()
{
    string s1, s2; cin >> s1 >> s2;
    find_prime();
    for (int i=0; i<s1.size(); i++) {
        int hash1=1, hash2=1;
        for (int j=i; j<s1.size(); j++) {
            int cur=s1[j]-'a';
            hash1=(hash1*prime[cur])%600011;
            hash2=(hash2*prime[cur+26])%600011;
            Hash[hash1].push_back(make_pair(hash2, j-i+1));
        }
    }

    int ans=0;
    for (int i=0; i<s2.size(); i++) {
        int hash1=1, hash2=1;
        for (int j=i; j<s2.size(); j++) {
            int cur=s2[j]-'a';
            hash1=(hash1*prime[cur])%600011;
            hash2=(hash2*prime[cur+26])%600011;
            for (int k=0; k<Hash[hash1].size(); k++) {
                if (Hash[hash1][k]==make_pair(hash2, j-i+1)) ans=max(ans, j-i+1);
            }
        }
    }
    cout << ans;
}
