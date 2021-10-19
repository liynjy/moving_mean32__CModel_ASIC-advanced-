#include <iostream>
#include <time.h>
#include "mv_mean32.h"

#define CLK_BY_CLK_MODE

void print_time(void);
void print_time(void)
{
    time_t  t;
    struct  tm  * lt;
    time  (&t); 
    lt =  localtime  (&t); 
    printf  (  "%d/%d/%d %d:%d:%d\n" ,lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec); 
}


/*
    Testbench Input and expected Output.
    NT: length of data / time steps.
*/
#define NT 7542
float di[NT] = {
    #include ".\tb_dat\mv_mean32_din.txt"
    };
float dout_exp[NT] = {
    #include ".\tb_dat\mv_mean32_dout_exp.txt"
    };


int main(int argc, char *argv[])
{
	print_time();
    printf("======== TEST START =========\n");

	// [1].Test Input - ufix9
    uint16_t din[NT], mv_mean32_dout[NT];
    for(int i=0; i<NT; i++)
    {
        din[i] = (uint16_t)di[i];
    }

	// [2].Run C Model
	#ifndef CLK_BY_CLK_MODE
    mv_mean32(din,mv_mean32_dout, NT); // Run model - run all clocks.
	#endif


	// [3].Check Output
	float tmp;
    for(int i=0; i<NT; i++)
    {
        #ifdef CLK_BY_CLK_MODE
		mv_mean32(din+i,mv_mean32_dout+i, 1);  // Run model - run clock by clock. 
		#endif

		tmp = dout_exp[i] * 32;
        if(mv_mean32_dout[i] != (uint16_t)tmp)
        {
            print_time();
            printf("******************************** TEST FAILED ********************************\n");
            printf("Ni=%d, mv_mean32_dout=[%d (uint16)], dout_exp=[%d (uint16)]\n", i, mv_mean32_dout[i], (uint16_t)tmp);
            printf("*****************************************************************************\n\n");
            return 1;
        }        
    }

	print_time();
    printf("======== TEST PASSED ========\n\n");
	return 0;
}

