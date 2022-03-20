#include <iostream>
using namespace std;

int main()
{
    int p_list[4]={2, 3, 5, 7};
    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            for (int k=0; k<4; k++)
            {
                for (int p=0; p<4; p++)
                {
                    for (int q=0; q<4; q++)
                    {
                        int A=p_list[i]*100+p_list[j]*10+p_list[k], B=p_list[p]*10+p_list[q];
                        int result=A*B;
                        int a, b, c, d, e;
                        a=result%10;
                        result = result/10;
                        b=result%10;
                        result = result/10;
                        c=result%10;
                        result = result/10;
                        d=result%10;
                        result = result/10;
                        e=result%10;
                        int counter = 0; // this has to be 5
                        for (int w=0; w<4; w++)
                        {
                            if (a==p_list[w])
                            {
                                counter += 1;
                            }
                            if (b==p_list[w])
                            {
                                counter += 1;
                            }
                            if (c==p_list[w])
                            {
                                counter += 1;
                            }
                            if (d==p_list[w])
                            {
                                counter += 1;
                            }
                            if (e==p_list[w])
                            {
                                counter += 1;
                            }
                        }
                        if (counter==5)
                        {
                            cout << i << j << k << "\n";
                            cout << p << q << "\n";
                            cout << a << b << c << d << e << "\n";
                            cout << "done" << "\n";
                        }
                    }
                }
            }
        }
    }
}
