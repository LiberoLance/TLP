#include <iostream>
using std::cin;
using std::cout;

void printCharXTimes(char c, int x); 
void printShapePattern(char c, int n);

int main(){
	int width = 8;

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
		printCharXTimes(c,x);
		x -= 2;
		numSpaces++;
		i = numSpaces;
	}
}
