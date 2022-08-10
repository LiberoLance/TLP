#include <iostream>
using std::cin;
using std::cout;

void prompt();
int get_input_base();
int get_output_base();
int read_input(int);
int decode(int, int, int);
int count_digits(int, int);
void print_number(int, int, int);

int main(){
	int in_base = 0;
	int out_base = 0;
	int input = 0;
	int digits = 0;

	prompt();
	in_base = get_input_base();
	out_base = get_output_base();
	input = read_input(in_base);
	digits = count_digits(input, out_base);
	print_number(input, digits, out_base);



	return 0;
}

void prompt(){
	cout 	<< "This program converts a number from one base to another.\n"
		<< "choose between base 2 to base 16\n";
}

int get_input_base(){
	int base = 0;
	char digit = '\0';

	cout << "Enter the base for the input: ";
	while((digit = cin.get()) != '\n'){
		base *= 10; 
		base += (digit - '0');
	}
	
	return base;
}

int get_output_base(){
	int base = 0;
	char digit = '\0';

	cout << "Enter the base for the output: ";
	while((digit = cin.get()) != '\n'){
                base *= 10;
		base += (digit - '0');
        }
	
	return base;
}

int read_input(int base){
	char digit = '\0';
	int digits = 0;
	int in_sum = 0;
	int out_sum = 0;
	int place_value = 1;

	cout <<"Enter the number base " << base <<": ";
	digit = cin.get();
	in_sum += (digit - '0');
	digits++;

	while((digit = cin.get()) != '\n'){
		digits++;
		for(int i = 1; i < digits; i++){
			place_value *= base;
		}
		in_sum += place_value * (digit -'0');
		place_value = 1;
	}
	out_sum = decode(in_sum, digits, base);
	
	return out_sum;
}

int decode(int in_sum, int digits, int base){
	int place_value = 1;
	int out_sum = 0;
	int digit = 0;
	int index = 0;

	while(digits != 1){
		for(int i = 1; i < digits; i++){
			place_value *= base;
		}
		digit = in_sum / place_value;
		in_sum -= digit * place_value;

		place_value = 1;
		for(int i = 0; i < index; i++){
			place_value *= base;
		}
		out_sum += digit * place_value;
		index++;
		place_value = 1;
		digits--;
	}
	digit = in_sum;
	for(int i = 0; i < index; i++){
		place_value *= base;
	}
	out_sum += digit * place_value;

	return out_sum;
}

int count_digits(int out_sum, int out_base){
	int digits = 0;
	
	while(out_sum != 0){
		out_sum /= out_base;
		digits++;
	}
	
	return digits;
}

void print_number(int out_sum, int digits, int out_base){
	int place_value = 1;
	
	cout << "The number in base "  << out_base << " is: ";
	while(digits != 0){
		for(int i = 1; i < digits; i++){
			place_value *= out_base;
		}
	
		cout << (out_sum / place_value);
		out_sum -= (out_sum / place_value) * place_value;
		place_value = 1;
		digits--;
	}
	cout << '\n';	
}
