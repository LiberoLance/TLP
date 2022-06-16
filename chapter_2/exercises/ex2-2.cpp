#include <iostream>
using std::cin;
using std::cout;

void printCharXTimes(char c, int x); 
void printShapePattern(char c, int x);
void printReversePattern(char c, int x);

int main(){
	int width = 8;

	printReversePattern('#', width);
	printShapePattern('#', width);

	return 0;
}

void printCharXTimes(char c, int x) {
	 while(x){
        	cout << c;
        	x--;
    	}
	cout << "\n";
}

void printShapePattern(char c, int x){
	int numSpaces = 0;
	int i = numSpaces;

	while(x){
		while(i){
			cout << ' ';
			i--;
		}
		printCharXTimes(c, x);
		x -= 2;
		numSpaces++;
		i = numSpaces;
	}
}

void printReversePattern(char c, int x){
	int numSpaces = (x-2) / 2;
	int i = numSpaces;
	int j = 2;

	while(j <= x){
		while(i){
			cout << ' ';
			i--;
		}
		printCharXTimes(c, j);
		j += 2;
		numSpaces--;
		i = numSpaces;
	}
}
