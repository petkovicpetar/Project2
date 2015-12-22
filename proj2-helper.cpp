#include <cstdlib>
#include <ctime>
#include <math.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <string>

extern float avg(float item[], int size);
extern float median(float item[], int size);
extern float stdDev(float item[], float a, int size);
extern float aad(float item[], float a, int size);

using namespace std;

int Rand_Num(int bias_Exponent){
	if(bias_Exponent==0)
		return 0;
	else{
		srand(time(NULL));
		int r[10];
		int min = -1*pow(2,bias_Exponent);
		int max = pow(2,bias_Exponent);
		for(int i=0 ; i<1 ; i++){
			r[i] = min + rand()%(max-min+1);
		}
		return r[0];		
	}
}