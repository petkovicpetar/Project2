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

extern float avg(float item[], int size);
extern float median(float item[], int size);
extern float stdDev(float item[], float a, int size);
extern float aad(float item[], float a, int size);
extern int Rand_Num(int bias_Exponent);

using namespace std;

int main(int argc, const char* argv[]){
	if(argc!=2){
		cerr << "invalid input" << endl;
		return -1;
	}

	string file_name = "proj2-input.txt";
	//open the file eceFileInput.
	ifstream eceFileInput("proj2-input.txt");

	//checks whether or not the file can be opened.
	if (! eceFileInput){
		cerr << "unable to open input file" << endl;
		return -1;
	}

	//Takes the server file and parses it into three vectors.
	//One has URI's, one has the sizes, and the last one the priorities.
	string line;
	string s;
    int rows = 0;
	vector<string> uris;
	vector<int> num1;
	vector<int> num2;
	while (getline(eceFileInput, line)) {
		char *str = new char[line.length() + 1];
		strcpy(str, line.c_str());
		char *pch;
		pch = strtok(str, " ");
		int temp_counter = 0;
		while (pch != NULL) {
			temp_counter++;
			if (temp_counter == 1) {
				uris.push_back(pch);
			}
			else if (temp_counter == 2) {
				int temp_int1 = atoi(pch);
				num1.push_back(temp_int1);
			}
			else {
				int temp_int2 = atoi(pch);
				num2.push_back(temp_int2);
				temp_counter = 0;
			}
			pch = strtok(NULL, " ");
		}
		delete[] str;
        rows++;
	}

	//Takes command line input, turns into integer, stores as bias for later use.
	int bias_Exponent;
	if(argc >= 0){
		bias_Exponent = atoi(argv[1]);
		if(bias_Exponent<0)
			return -1;
	}
	//cout << "Bias: " << bias_Exponent << endl;

	//Creates a random number.
	int Random_Number = Rand_Num(bias_Exponent);

	//Takes in user inputs, stores in vector and takes information needed.
	//vector<string> uris_Requests;
	int amount = 1000;
	string input;
	float size_data[amount];
	float delay_data[amount];
	float priority_data[amount];
	float negative;
	float speed = 1.25;
	int counter = 0;
	while(true){
		cin>>input;
		if(input=="exit")
			break;
		else
			for(int x=0 ; x<rows ; x++){
				if(input==uris.at(x)){
					size_data[counter] = num1.at(x);
					priority_data[counter] = num2.at(x);
					do{
						negative = num1[x] + Rand_Num(bias_Exponent);
					}
					while (negative<0);
					delay_data[counter] = negative/speed;
					counter++;
					break;
				}
				if (x==rows-1){
					cerr << "input not in database" << endl;
					return -1;
				}
			}
	}
    
	if(counter>0){

		cout << avg(size_data,counter) << " ";
		cout << median(size_data,counter) << " ";
		cout << stdDev(size_data,avg(size_data,counter),counter) << " ";
		cout << aad(size_data,median(size_data,counter),counter)<<endl ;

		cout << avg(priority_data,counter) << " ";
		cout << median(priority_data,counter) << " ";
		cout << stdDev(priority_data,avg(priority_data,counter),counter) << " ";
		cout << aad(priority_data,median(priority_data,counter),counter)<<endl ;
	
        cout << avg(delay_data,counter) << " ";
		cout << median(delay_data,counter) << " ";
		cout << stdDev(delay_data,avg(delay_data,counter),counter) << " ";
		cout << aad(delay_data,median(delay_data,counter),counter)<<endl ;
    }

	return 0;
}