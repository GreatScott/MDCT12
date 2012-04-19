#include <avr/pgmspace.h>
#include "mdct12.h"
#include "fix16.h"
#include <Arduino.h>


int* MDCT12(int* outframe, int* dataframe, bool spec){
	fix16_t y0 = fix16_mul(fix16_from_int(-1),fix16_from_int(dataframe[9]));
	fix16_t y1 = fix16_mul(fix16_from_int(-1),fix16_from_int(dataframe[10]));
	fix16_t y2 = fix16_mul(fix16_from_int(-1),fix16_from_int(dataframe[11]));
	fix16_t y3 = fix16_from_int(dataframe[0]);
	fix16_t y4 = fix16_from_int(dataframe[1]);
	fix16_t y5 = fix16_from_int(dataframe[2]);
	fix16_t y6 = fix16_from_int(dataframe[3]);
	fix16_t y7 = fix16_from_int(dataframe[4]);
	fix16_t y8 = fix16_from_int(dataframe[5]);
	fix16_t y9 = fix16_from_int(dataframe[6]);
	fix16_t y10 = fix16_from_int(dataframe[7]);
	fix16_t y11 = fix16_from_int(dataframe[8]);

	fix16_t TwoRootTwo = fix16_mul(fix16_from_int(2),fix16_sqrt(fix16_from_int(2)));
	fix16_t SqrtTwo = fix16_sqrt(fix16_from_int(2));
	
	
	fix16_t w0 = fix16_mul(fix16_sub(y0,y11),fix16_div(fix16_from_int(1),fix16_mul(TwoRootTwo,fix16_cos(fix16_div(fix16_pi,fix16_from_int(24))))));
	fix16_t w1 = fix16_mul(fix16_sub(y1,y10),fix16_div(fix16_from_int(1),fix16_mul(TwoRootTwo,fix16_cos(fix16_div(fix16_add(fix16_mul(fix16_pi,fix16_from_int(2)),fix16_pi),fix16_from_int(24))))));
	fix16_t w2 = fix16_mul(fix16_sub(y2,y9),fix16_div(fix16_from_int(1),fix16_mul(TwoRootTwo,fix16_cos(fix16_div(fix16_add(fix16_mul(fix16_pi,fix16_from_int(4)),fix16_pi),fix16_from_int(24))))));
	fix16_t w3 = fix16_mul(fix16_sub(y3,y8),fix16_div(fix16_from_int(1),fix16_mul(TwoRootTwo,fix16_cos(fix16_div(fix16_add(fix16_mul(fix16_pi,fix16_from_int(6)),fix16_pi),fix16_from_int(24))))));
	fix16_t w4 = fix16_mul(fix16_sub(y4,y7),fix16_div(fix16_from_int(1),fix16_mul(TwoRootTwo,fix16_cos(fix16_div(fix16_add(fix16_mul(fix16_pi,fix16_from_int(8)),fix16_pi),fix16_from_int(24))))));
	fix16_t w5 = fix16_mul(fix16_sub(y5,y6),fix16_div(fix16_from_int(1),fix16_mul(TwoRootTwo,fix16_cos(fix16_div(fix16_add(fix16_mul(fix16_pi,fix16_from_int(10)),fix16_pi),fix16_from_int(24))))));

	fix16_t d0 = SqrtTwo;
	fix16_t d2 = fix16_mul(SqrtTwo,fix16_cos(fix16_div(fix16_pi,fix16_from_int(6))));
	fix16_t d4 = fix16_mul(SqrtTwo,fix16_cos(fix16_div(fix16_pi,fix16_from_int(3))));
	fix16_t d5 = fix16_mul(SqrtTwo,fix16_cos(fix16_div(fix16_mul(fix16_from_int(5),fix16_pi),fix16_from_int(12))));
	
	fix16_t a0 = fix16_add(w0,w5);
	fix16_t a1 = fix16_add(w1,w4);
	fix16_t a2 = fix16_add(w2,w3);
	fix16_t a3 = fix16_sub(w2,w3);
	fix16_t a4 = fix16_sub(w1,w4);
	fix16_t a5 = fix16_sub(w0,w5);
	
	fix16_t z1 = fix16_add(a0,a2);
	fix16_t z2 = fix16_mul(d5,fix16_add(a3,a5));
	
	if(spec){
		outframe[0] = abs(fix16_to_int(fix16_mul(d0,fix16_add(z1,a1))));
		outframe[1] = abs(fix16_to_int(fix16_add(z2,fix16_add(a4,a5))));
		outframe[2] = abs(fix16_to_int(fix16_mul(d2,fix16_sub(a0,a2))));
		outframe[3] = abs(fix16_to_int(fix16_sub(a5,fix16_add(a4,a3))));
		outframe[4] = abs(fix16_to_int(fix16_mul(d4,fix16_sub(z1,fix16_add(a1,a1)))));
		outframe[5] = abs(fix16_to_int(fix16_sub(fix16_add(z2,a3),a4)));	
	}
	else{
		outframe[0] = fix16_to_int(fix16_mul(d0,fix16_add(z1,a1)));
		outframe[1] = fix16_to_int(fix16_add(z2,fix16_add(a4,a5)));
		outframe[2] = fix16_to_int(fix16_mul(d2,fix16_sub(a0,a2)));
		outframe[3] = fix16_to_int(fix16_sub(a5,fix16_add(a4,a3)));
		outframe[4] = fix16_to_int(fix16_mul(d4,fix16_sub(z1,fix16_add(a1,a1))));
		outframe[5] = fix16_to_int(fix16_sub(fix16_add(z2,a3),a4));
	}

	return outframe;
}