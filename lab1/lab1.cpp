#include <iostream>
using namespace std;

/* Program to demonstrate use of functional decomposition,
   program organization and style standards required for
   all programs written for CS240C.  Program prompts user
   for 2 integers, doubles the larger and displays the average.
*/      

int getNumber();
// output: returns an integer value
// side effects: prompts user to enter an integer
        
void doubleLarger(int & num_1, int & num_2);

// input: 2 integer values
// output: the larger of num_1 and num_2 has been doubled

double findAverage(int num_1, int num_2);
// input: 2 integer values
// output: returns the average of num_1 and num_2

void display(double average);
// input: a double value
// output: none
// side effects: displays average on the screen

int main ( ) {
	int num;
	int num2;
	num = getNumber();
	num2 = getNumber();
	doubleLarger(num,num2);
	double ans;
	ans = findAverage(num,num2);
	display(ans);

	

//**** add code here ****
 
}

//**** define the 4 functions whose prototypes appear above ****
int getNumber(){
	cout<< "Enter an integer value:"<<endl;
	int num;
	cin >> num;
	return num;
}
void doubleLarger(int & num_1, int & num_2){
	if(num_1>num_2){
		num_1 = num_1*2;
	}
	else{
		num_2 = num_2*2;
	}
	return;
}
double findAverage(int num_1, int num_2){
	return (((double)num_1+num_2)/2);
}
void display(double average){
	cout << average<<endl;
}
