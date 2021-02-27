// Promotion counting

#include <iostream>
using namespace std;

int main()
{
    int brnz_bef, brnz_aft;
    int silv_bef, silv_aft;
    int gold_bef, gold_aft;
    int plat_bef, plat_aft;
    cin >> brnz_bef >> brnz_aft >> silv_bef >> silv_aft >> gold_bef >> gold_aft >> plat_bef >> plat_aft;
    // increments
    int plat_inc=plat_aft-plat_bef;
    int gold_inc=gold_aft-gold_bef;
    int silv_inc=silv_aft-silv_bef;
    int brnz_inc=brnz_aft-brnz_bef;
    // promotions
    int plat_prom=0, gold_prom=0, silver_prom=0;
    // people who got to platinum
    plat_prom+=plat_inc;
    gold_prom+=plat_inc;
    silver_prom+=plat_inc;
    // people who got to gold
    gold_prom+=gold_inc;
    silver_prom+=gold_inc;
    // people who got to silver
    silver_prom+=silv_inc;
    // results
    cout << silver_prom << endl;
    cout << gold_prom << endl;
    cout << plat_prom << endl;
}
