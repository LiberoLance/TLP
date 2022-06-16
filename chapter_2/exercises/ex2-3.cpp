#include <iostream>
using std::cin;
using std::cout;

void printCharXTimes(char c, int x); 
void printShapePattern(char c, int x);
void printReversePattern(char c, int x);

int main(){
	int width = 12;

	printShapePattern(' ', width);
	printReversePattern('#', width);
	return 0;
}

void printCharXTimes(char c, int x) {
	 while(x){
        	cout << c;
        	x--;
    	}
}

void printShapePattern(char c, int x){
	int numHashes = 1;

	while(x >= 0){
		printCharXTimes(' ', numHashes);
		printCharXTimes('#', numHashes);
		printCharXTimes(c, x);
		printCharXTimes('#', numHashes);
		cout << '\n';
		x -= 4;
		numHashes++;
	}
}

void printReversePattern(char c, int x){
	int numSpaces = 4;
	int h = x - 4;
	int cs = 0;

	while(cs <= x){
		printCharXTimes(' ', numSpaces);
		printCharXTimes(c, h/2);
		printCharXTimes(' ', cs);
		printCharXTimes(c, h/2);
		printCharXTimes(' ', numSpaces);
		cout << '\n';
		numSpaces--;
		h -= 2;
		cs += 4;
	}
}
