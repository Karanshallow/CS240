#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;



	
bool countBlank(int & blanks, string str);
// input: 1 integer value, 1 string value
// output: returns nothing but increments counter if line is blank

void countWords(double& words, double& lines,double& letters, string str);
// input: 1 string, 2 integer values
// output: returns nothing 
//side effects: updates the number of words in lines, passes words to countLetters

void countLetters(double& num_1,string str);
// input: 2 integer values and a string value
// output: returns nothing but updates letters in word

void average(double num1,double num2, double& temp);
//input: 3 integer values
//output: the average based on these two numbers

void display(double blanks, double words, double letters);
//input: 3 integer variables
//output: none
//side effects: displays all required information

string getFileName();
//input: none
//output: String of user’s input


int main ( ) {
	int blanks = 0;
	double numLine = 0;
	double numWord = 0;
	double numLetter = 0;
	double averageWord = 0;
	double averageLetter = 0;
	string userInput;
	userInput = getFileName();
	ifstream myfile(userInput);
	string line;
	if(myfile.is_open()){
		while(getline(myfile,line)){
			if (countBlank(blanks,line)){
				countWords(numWord,numLine,numLetter, line);
			}
			average(numWord,numLine,averageWord);
			average(numLetter, numWord, averageLetter);
		}
			display(blanks,averageWord,averageLetter);
	}
			
			
	
//**** add code here ****
 return 0;
}

//**** define the 4 functions whose prototypes appear above ****
bool countBlank(int & blanks, string str){
	if (str.size()==0){
		blanks++;
		return false;
	}else{
		return true;
	}
}

void countWords(double& words, double& lines,double& letters, string str){
	istringstream iss(str);
	do
    {
        string subs;
        iss >> subs;
        words++;
        countLetters(letters,subs);
        }while (iss);
    lines++;
}
	

void countLetters(double& num_1,string str){
	for(int i =0;i<str.length();i++){
		if(isalpha(str.at(i))){
			num_1++;
		}
	}
}
void average(double num1,double num2, double& temp){
	temp = num1/num2;
}

void display(double blanks, double words, double letters){
	cout<<"There are "<<blanks<<" blank lines"<<endl;
	cout<<"There are an average of "<<words<<" words per line."<<endl;
	cout<<"There are an average of "<<letters<<" letters per word."<<endl;
}

string getFileName(){
	cout<<"Enter file name: "<<endl;
	string test;
	getline(cin,test);
	return test;
}

