#include <iostream>
using std::cin;
using std::cout;

void convert_hex_decimal();
int get_input_num(char);

int main(){
	convert_hex_decimal();

	return 0;
}

void convert_hex_decimal(){
	int coded_hex_num = 0;
	int hex_digit = 0;
	int digits = 0;
	int base = 16;
	int hex_place_value = 1;
	char input = '\0';

	cout << "Enter a hexidecimal number: 0x";
	input = cin.get();
	digits++;
	coded_hex_num += get_input_num(input);

	while((input = cin.get()) != '\n'){
		digits++;
		for(int i = 1; i < digits; i++){
			hex_place_value *= base;
		}
		hex_digit = get_input_num(input);
		coded_hex_num += (hex_digit * hex_place_value);
		hex_place_value = 1;
	}

	int decimal_num = 0;
	int last_index = digits;

	for(int i = 1; i < digits; i++){
                        hex_place_value *= base;
        }
	hex_digit  = coded_hex_num / hex_place_value;
	decimal_num = hex_digit;
	hex_place_value *= hex_digit;
	coded_hex_num -= hex_place_value;
	digits--;
	hex_place_value = 1;	

	while(digits != 1){
		for(int i = 1; i < digits; i++){
			hex_place_value *= base;
		}
		hex_digit = coded_hex_num / hex_place_value;
		decimal_num += (hex_digit * hex_place_value);
		hex_place_value *= hex_digit;
                coded_hex_num -= hex_place_value;
		digits--;
		hex_place_value = 1;
	}

	for(int i = 1; i < last_index; i++){
                        hex_place_value *= base;
        }
	decimal_num += (coded_hex_num * hex_place_value);
	
	cout << decimal_num << '\n';
}

int get_input_num(char input){
	int value = 0;

	switch(input){
		case '0': value = 0;
		break;
		case '1': value = 1;
		break;
		case '2': value = 2;
		break;
		case '3': value = 3;
		break;
		case '4': value = 4;
		break;
		case '5': value = 5;
		break;
		case '6': value = 6;
		break;
		case '7': value = 7;
		break;
		case '8': value = 8;
		break;
		case '9': value = 9;
		break;
		case 'A': value = 10;
		break;
		case 'B': value = 11;
		break;
		case 'C': value = 12;
		break;
		case 'D': value = 13;
		break;
		case 'E': value = 14;
		break;
		case 'F': value = 15;
		break;
	}

	return value;
}
