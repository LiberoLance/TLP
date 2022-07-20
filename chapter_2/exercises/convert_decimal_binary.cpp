#include <iostream>
using std::cin;
using std::cout;

int get_number();
int count_binary_digits(int);
void convert_decimal_binary(int, int);

int main(){

	int number = get_number();
	cout << "To convert " << number << " into binary\n";;
	int digits = count_binary_digits(number);
	cout << "you need: " << digits << " digits.\nThe binary string: ";
	convert_decimal_binary(number, digits);

	return 0;
}

int get_number(){
	int number = 0;
	char digit = '\0';

	cout << "Enter a number base 10, to see its binary equivalent: ";
	digit = cin.get();
	while(digit != '\n'){
		number *= 10;
		number += (digit - '0');
		digit = cin.get();	
	}

	return number;
}

int count_binary_digits(int number){
	int digit_count = 0;

	while(number != 0){
		number /= 2;
		digit_count++;
	}

	return digit_count;
}

void convert_decimal_binary(int number, int binary_index){
	int binary_positional_value = 1;

	while(binary_index != 1){
		for(int i = 1; i < binary_index; i++){
			binary_positional_value *= 2;
		}

		if((number - binary_positional_value) >= 0){
			number -= binary_positional_value;
			cout << 1;
		}
		else{
			cout << 0;
		}

		binary_index--;
		binary_positional_value = 1;
	}
	
	cout << number << '\n';
}
