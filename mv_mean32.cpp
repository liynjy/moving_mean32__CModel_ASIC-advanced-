// -------------------------------------------------------
// Author  : Lin Junyang
// Version : 01
// -------------------------------------------------------

/*
   --------------------- C Model ---------------------
   >>> Bit Matched
   >>> Resource Precise
   >>> Cycle Accurate 
   ---------------------------------------------------
   32 Points moving average of input data stream.
   ---------------------------------------------------
   |   Input:
   |      ptrg    - boolean            
   |      din     - ufix9              [0,511]
   |   Output:
   |      dout    - ufix14_En5         [0,511.96875]
   ---------------------------------------------------
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "mv_mean32.h"
#include ".\elements\pedge.h"
#include ".\elements\reg.h"
#include ".\elements\reg_en.h"

//#define PRINT_SE


int mv_mean32(uint16_t* din, uint16_t* mv_mean32_dout, int N)
{
   #ifdef PRINT_SE
   printf("START ---- mef_adcdat ----\n");
   #endif

   // [1].Initialization:
   /************************** Regs **************************/
   static REG<uint16_t> din_d1_reg(0);
   static REG<uint16_t> din_d2_reg(0);
   static REG<uint16_t> din_d3_reg(0);
   static REG<uint16_t> din_d4_reg(0);
   static REG<uint16_t> din_d5_reg(0);
   static REG<uint16_t> din_d6_reg(0);
   static REG<uint16_t> din_d7_reg(0);
   static REG<uint16_t> din_d8_reg(0);
   static REG<uint16_t> din_d9_reg(0);
   static REG<uint16_t> din_d10_reg(0);
   static REG<uint16_t> din_d11_reg(0);
   static REG<uint16_t> din_d12_reg(0);
   static REG<uint16_t> din_d13_reg(0);
   static REG<uint16_t> din_d14_reg(0);
   static REG<uint16_t> din_d15_reg(0);
   static REG<uint16_t> din_d16_reg(0);
   static REG<uint16_t> din_d17_reg(0);
   static REG<uint16_t> din_d18_reg(0);
   static REG<uint16_t> din_d19_reg(0);
   static REG<uint16_t> din_d20_reg(0);
   static REG<uint16_t> din_d21_reg(0);
   static REG<uint16_t> din_d22_reg(0);
   static REG<uint16_t> din_d23_reg(0);
   static REG<uint16_t> din_d24_reg(0);
   static REG<uint16_t> din_d25_reg(0);
   static REG<uint16_t> din_d26_reg(0);
   static REG<uint16_t> din_d27_reg(0);
   static REG<uint16_t> din_d28_reg(0);
   static REG<uint16_t> din_d29_reg(0);
   static REG<uint16_t> din_d30_reg(0);
   static REG<uint16_t> din_d31_reg(0);
   static REG<uint16_t> din_d32_reg(0);
   static REG<uint16_t> sum_reg(0);
   /************************** Wires **************************/
   static uint16_t sum;
   /***********************************************************/ 

   for(int i=0; i<N; i++)
   {
      // [2].Regs output update
      din_d1_reg.z1();
      din_d2_reg.z1();
      din_d3_reg.z1();
      din_d4_reg.z1();
      din_d5_reg.z1();
      din_d6_reg.z1();
      din_d7_reg.z1();
      din_d8_reg.z1();
      din_d9_reg.z1();
      din_d10_reg.z1();
      din_d11_reg.z1();
      din_d12_reg.z1();
      din_d13_reg.z1();
      din_d14_reg.z1();
      din_d15_reg.z1();
      din_d16_reg.z1();
      din_d17_reg.z1();
      din_d18_reg.z1();
      din_d19_reg.z1();
      din_d20_reg.z1();
      din_d21_reg.z1();
      din_d22_reg.z1();
      din_d23_reg.z1();
      din_d24_reg.z1();
      din_d25_reg.z1();
      din_d26_reg.z1();
      din_d27_reg.z1();
      din_d28_reg.z1();
      din_d29_reg.z1();
      din_d30_reg.z1();
      din_d31_reg.z1();
      din_d32_reg.z1();
      sum_reg.z1();
  
      // [3].Update logics
      din_d32_reg = din_d31_reg.out_val;
      din_d31_reg = din_d30_reg.out_val;
      din_d30_reg = din_d29_reg.out_val;
      din_d29_reg = din_d28_reg.out_val;
      din_d28_reg = din_d27_reg.out_val;
      din_d27_reg = din_d26_reg.out_val;
      din_d26_reg = din_d25_reg.out_val;
      din_d25_reg = din_d24_reg.out_val;
      din_d24_reg = din_d23_reg.out_val;
      din_d23_reg = din_d22_reg.out_val;
      din_d22_reg = din_d21_reg.out_val;
      din_d21_reg = din_d20_reg.out_val;
      din_d20_reg = din_d19_reg.out_val;
      din_d19_reg = din_d18_reg.out_val;
      din_d18_reg = din_d17_reg.out_val;
      din_d17_reg = din_d16_reg.out_val;
      din_d16_reg = din_d15_reg.out_val;
      din_d15_reg = din_d14_reg.out_val;
      din_d14_reg = din_d13_reg.out_val;
      din_d13_reg = din_d12_reg.out_val;
      din_d12_reg = din_d11_reg.out_val;
      din_d11_reg = din_d10_reg.out_val;
      din_d10_reg = din_d9_reg.out_val;
      din_d9_reg = din_d8_reg.out_val;
      din_d8_reg = din_d7_reg.out_val;
      din_d7_reg = din_d6_reg.out_val;
      din_d6_reg = din_d5_reg.out_val;
      din_d5_reg = din_d4_reg.out_val;
      din_d4_reg = din_d3_reg.out_val;
      din_d3_reg = din_d2_reg.out_val;
      din_d2_reg = din_d1_reg.out_val;
      din_d1_reg = din[i];

      sum = din[i] + sum_reg.out_val - din_d32_reg.out_val;
      sum_reg = sum;

      // [4].Outputs
      mv_mean32_dout[i] = sum_reg.out_val;
   }

   #ifdef PRINT_SE
   printf("END   ---- mef_adcdat ----\n");
   #endif

   return 0;
}
