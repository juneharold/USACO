#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

int main()
{
    int N, num[105]={}; string S;
    cin >> N >> S;

    for (int i=65; i<65+N; i++) cin >> num[i];

    stack<double> st;
    for (int i=0; i<S.size(); i++) {
        if (65<=S[i] && S[i]<=90) {
            st.push(num[S[i]]);
        }
        else if (S[i]=='+'){
            double a=st.top();
            st.pop();
            double b=st.top();
            st.pop();
            st.push(a+b);
        }
        else if (S[i]=='-'){
            double a=st.top();
            st.pop();
            double b=st.top();
            st.pop();
            st.push(b-a);
        }
        else if (S[i]=='*'){
            double a=st.top();
            st.pop();
            double b=st.top();
            st.pop();
            st.push(a*b);
        }
        else if (S[i]=='/'){
            double a=st.top();
            st.pop();
            double b=st.top();
            st.pop();
            st.push(b/a);
        }

    }

    cout << fixed << setprecision(2);
    cout << st.top();
}
