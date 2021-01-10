#include <iostream>
using namespace std;
    int fRate,sRate,t_i_h,t_i_m,t_o_h,t_o_m,tt_h,tt_m,t_h_t,s_m_t,e_tt_h,nt_c,tt_c;
    char rCode;
void check();
int main(){
    /*
    t_i_h = time in hours
    t_i_m = time in minutes
    t_o_h = time out hours
    t_o_m = time out minutes
    tt_h = total hours
    tt_m = total minutes
    t_h_t = twelve hour time
    s_m_t = sixty minute time
    e_tt_h = exceeding total hour
    nt_c = normal time charge
    tt_c = total time charge

    */

    printf("Enter Room Code:");
    scanf("%c", &rCode);

    if (rCode == 'x'){
        fRate = 500;
        sRate = 600;
        check();
        nt_c = fRate * 3;
        if (tt_h>3)
        {
            e_tt_h = tt_h - 3;
            sRate = sRate * e_tt_h;
        }
        tt_c = nt_c + sRate;
        
        printf("Total Charge:%d",tt_c);

    }else if (rCode == 'y'){
        fRate = 650;
        sRate = 750;
        check();
        nt_c = fRate * 2;
        if (tt_h>3)
        {
            e_tt_h = tt_h - 2;
            sRate = sRate * e_tt_h;
        }
        tt_c = nt_c + sRate;
        
        printf("Total Charge:%d",tt_c);

    }else if (rCode == 'z'){
        fRate = 850;
        sRate = 950;
        check();
        nt_c = fRate;
        if (tt_h>3)
        {
            e_tt_h = tt_h - 1;
            sRate = sRate * e_tt_h;
        }
        tt_c = nt_c + sRate;
        
        printf("Total Charge:%d",tt_c);
    }


    return 0;
}


void check(){
        printf("Please Input Time In\n");
        scanf("%d%d",&t_i_h,&t_i_m);
        printf("Please Input Time Out\n");
        scanf("%d%d",&t_o_h,&t_o_m);
        if (t_i_h > t_o_h)
        {
            t_h_t = 12 - t_i_h;
            tt_h = t_h_t + t_o_h;
            s_m_t = 60 - t_i_m;
            tt_m = s_m_t + t_o_m;
            if (t_i_m > t_o_m)
            {
                tt_h -= 1;
            }
            else
            {
                tt_m -= 60;
            }
        }
        else
        {
            t_h_t = t_o_h - t_i_h;
            tt_h = t_h_t;
            s_m_t = 60 - t_i_m;
            tt_m = s_m_t + t_o_m;
            if (t_i_m > t_o_m)
            {
                tt_h -= 1;
            }
            else
            {
                tt_m -= 60;
            }
        }
        printf("Time in: %d:%d\n",t_i_h,t_i_m);
        printf("Time out: %d:%d\n",t_o_h,t_o_m);
        printf("------------------------------\n");
        printf("Hour: %d Minutes: %d\n",tt_h,tt_m);
        printf("------------------------------\n");
        if (tt_m>30)
        {
            tt_h += 1;
        }
    }