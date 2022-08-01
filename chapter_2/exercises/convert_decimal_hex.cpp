#include <iostream>
using std::cin;
using std::cout;

int get_number();
int count_digits(int);
void convert_number_hex(int, int);
void print_large_hex(int);

int main(){
	int num = get_number();
	int digits = count_digits(num);
	convert_number_hex(num, digits);

	return 0;
}

int get_number(){
	int num = 0;
	
	cout << "Enter a number base 10: ";
	cin >> num;

	return num;
}

int count_digits(int num){
	int digits = 0;

	while(num != 0){
		num /= 16;
		digits++;
	}
	
	return digits;
}

void convert_number_hex(int num, int digits){
	int place_value = 1;
	int base = 16;
	int hex_digit = 0;
	cout << "0x";

	while(digits > 1){
		for(int i = 1; i < digits; i++){
			place_value *= base;
		}

		hex_digit = num / place_value;

		if(hex_digit > 1){
			place_value *= hex_digit;
		}

		if(hex_digit > 9){
			print_large_hex(hex_digit);
		}
		else{
			cout << hex_digit;
		}

		num -= place_value;

		digits--;
		place_value = 1;
	}
	
	if(num > 9)
	{
		print_large_hex(num);
	}
	else{
		cout << num;
	}
	cout << '\n';
}

void print_large_hex(int hex_digit){
	switch(hex_digit){
		case 10: cout << 'A';
		break;
		case 11: cout << 'B';
		break;
		case 12: cout << 'C';
		break;
		case 13: cout << 'D';
		break;
		case 14: cout << 'E';
		break;
		case 15: cout << 'F';
		break;
	}
}
