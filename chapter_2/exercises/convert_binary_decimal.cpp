#include <iostream>
using std::cin;
using std::cout;

void convert_binary_number();
int get_binary_place_value(int);

int main(){
	convert_binary_number();
	return 0;
}

void convert_binary_number(){
	int sum_place_values = 0;
	int binary_digits = 1;
	int binary_place_value = 1;
	char digit = '\0';	

	cout << "Enter a binary number: ";
	digit = cin.get();
	if(digit == '1'){
		sum_place_values = binary_place_value;
	}
	
	while((digit = cin.get()) != '\n'){
		binary_digits++;
		binary_place_value = get_binary_place_value(binary_digits);
		
		if(digit == '1'){
			sum_place_values += binary_place_value;
		}
		else{
			sum_place_values -= binary_place_value;
		}
		binary_place_value = 1;
	}

	//sum the decimal value equivalent by unwinding sum_place_values. 
	int decimal_number = 0;
	int reverse_binary_digits = 1;

	binary_place_value = get_binary_place_value(binary_digits);
	if(sum_place_values > 0){
		decimal_number++;
		sum_place_values -= binary_place_value;
	}
	else{
		sum_place_values += binary_place_value;
	}
	binary_digits--;
	reverse_binary_digits++;	
	binary_place_value = 1;

	while(binary_digits != 0){
		binary_place_value = get_binary_place_value(binary_digits);
		if(sum_place_values > 0){
			decimal_number += get_binary_place_value(reverse_binary_digits);
			sum_place_values -= binary_place_value;
		}
		else{
			sum_place_values += binary_place_value;
		}
		binary_digits--;
		reverse_binary_digits++;
	}
	cout << "The decimal equivalent is: " << decimal_number << '\n';
}

int get_binary_place_value(int binary_digits){
	int binary_place_value = 1;

	for(int i = 1; i < binary_digits; i++){
		binary_place_value *= 2;
	}

	return binary_place_value;
}
