#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <ctype.h>
#include <vector>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include <cmath>

using namespace std;

//Returns the float average of items in the item[] for size entries.
float avg(float item[], int size){
	float total = 0;
	float throwback;
	for(int x=0 ; x<size ; x++){
		total += item[x];
	}
	throwback = total/size;
	return throwback;
}

//Returns the standard deviation of item[] with average a, and size values.
float stdDev(float item[], float a, int size){
	float total = 0;
	float throwback;
	for(int x=0 ; x<size ; x++){
		total += pow(item[x]-a,2);
	}
	throwback = sqrt((1.0/size)*total);
	return throwback;
}

//Returns the median of item[] which has size values in it.
float median(float item[], int size){
	float throwback;
	for(int n=0 ; n<size-1 ; n++){
		for(int k=0 ; k<size-n-1 ; k++){
			if(item[k]>item[k+1]){
				int temp = item[k+1];
				item[k+1] = item[k];
				item[k] = temp;
			}
		}
	}
	if(size%2==0)
		throwback = (item[(size/2)-1]+item[size/2])/2;
	else
		throwback = item[size/2];
	return throwback;
}

//Returns the average absolute deviation of item[] with median m, and size values.
float aad(float item[], float m, int size){
	float total = 0;
	float throwback;
	for(int x=0 ; x<size ; x++){
		total += abs(item[x]-m);
	}
	throwback = (1.0/size)*total;
	return throwback;
}