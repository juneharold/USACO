#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define ll long long
string s, message;
ll a=0, b=0, fib[305]={}, idx=0;

int main()
{
    // input and preprocessing
    getline(cin, s);
    char type=s[0];

    vector <ll> v1;
    for (int i=2; i<=s.size(); i++) {
        if (s[i]!=32) v1.push_back(s[i]-48);
        else break;
        idx=i+2;
    }
    ll times10=1;
    for (int i=v1.size()-1; i>=0; i--) {
        a+=v1[i]*times10;
        times10*=10;
    }

    vector <ll> v2;
    for (int i=idx; i<=s.size(); i++) {
        if (s[i]!=32) v2.push_back(s[i]-48);
        else break;
        idx=i+2;
    }
    times10=1;
    for (int i=v2.size()-1; i>=0; i--) {
        b+=v2[i]*times10;
        times10*=10;
    }

    char key=s[idx];

    fib[1]=a; fib[2]=b;
    for (int i=3; i<=300; i++) {
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]%=26;
    }

    //solving.
    idx+=2;
    if (type=='E') {
        message=s.substr(idx, s.size());
        for (int i=0; i<message.size(); i++) {
            ll ascii=message[i], offset=0;
            if (i%2==0) {
                offset=key+(fib[i+1]%26);
                if (offset>122) offset-=26;
                if (offset<97) offset+=26;
            }
            else {
                offset=key-(fib[i+1]%26);
                if (offset>122) offset-=26;
                if (offset<97) offset+=26;
            }
            cout << ascii+offset*3 << " ";
        }
    }
    else {
        ll num[305]={}, j=1;
        while (idx<s.size()) {
            num[j]=(s[idx]-48)*100+(s[idx+1]-48)*10+(s[idx+2]-48);
            idx+=4;
            j++;
        }

        for (int i=1; i<j; i++) {
            ll offset=0;
            if (i%2==1) {
                offset=key+(fib[i]%26);
                if (offset>122) offset-=26;
                if (offset<97) offset+=26;
            }
            else {
                offset=key-(fib[i]%26);
                if (offset>122) offset-=26;
                if (offset<97) offset+=26;
            }
            cout << (char)(num[i]-offset*3);
        }
    }
}

/*
D 223 56 z 379 479 341 447 448 329 381 397 402 402 395 462 404 383 425 434 446 383 469 468 405 464 408 449 433 329 390 425 429 395 446 420 449 368 417 397 363 363 395 429 443 383 464 395 446 344 408 458 445 431 335 367 402 394 475 419 391

E 321 231 a This Problem is terrible. Poor explanation and wrong test cases.
D 0 1 a 375 470 399 478 332 434 429 441 452 453 401 445 365 399 445 365 482 437 435 420 396 464 402 464 346 386 395 441 465 459 332 437 453 406 438 430 476 433 437 411 402 476 326 460 410 454 347 449 468 456 410 439 365 410 431 448 482 368 420 403 406 467 409 409
*/
