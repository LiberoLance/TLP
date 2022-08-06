#include <iostream>
using std::cin;
using std::cout;

void intro();
char read_input();
void outro();
void call_conversions(char, char);


//f() for binary to decimal
int convert_binary_number();
int get_binary_place_value(int);

//f() for decimal to binary
int count_binary_digits(int);
void convert_decimal_binary(int, int);

//f() for decimal to hex
int count_digits(int);
void convert_number_hex(int, int);
void print_large_hex(int);

//f() for decimal
int get_number();

//f() hex to decimal
int convert_hex_decimal();
int get_input_num(char);

int main(){
	char choice_in = '\0';
	char choice_out = '\0';

	intro();
	choice_in = read_input();
	outro();
	choice_out = read_input();
	call_conversions(choice_in, choice_out);

	

	return 0;
}

void intro(){
	cout 	<< "Welcome to the binary, decimal and hexidecimal converter!"
		<< "\nEnter b to convert a binary number"
		<< "\nEnter d to convert a decimal number"
		<< "\nEnter h to convert a hexidecimal number"
		<< "\n: ";
}

char read_input(){
	char input = '\0';

	input = cin.get();
	while(cin.get() != '\n'){ //flush the input stream.
		continue;
	}
	
	return input;
}

void outro(){
	cout	<< "\nTo output the number as binary enter b\n"
		<< "for deciaml enter d\n"
		<< "for hexideciaml enter h"
		<< "\n: "; 
}

void call_conversions(char choice_in, char choice_out){
	int num_10 = 0;	

	//binary calls
	if(choice_in == 'b' && choice_out =='d'){
		num_10 = convert_binary_number();
		cout << "The decimal equivalent is: "<< num_10 << '\n';
	}
	else if(choice_in == 'b' && choice_out == 'b'){
		num_10 = convert_binary_number();
		convert_decimal_binary(num_10, count_binary_digits(num_10));
	}
	else if(choice_in == 'b' && choice_out == 'h'){
		num_10 = convert_binary_number();
		convert_number_hex(num_10, count_digits(num_10));
	}

	//decimal calls
	if(choice_in == 'd' && choice_out == 'b'){
		num_10 = get_number();
		convert_decimal_binary(num_10, count_binary_digits(num_10));
	}
	else if(choice_in == 'd' && choice_out == 'd'){
		num_10 = get_number();
		cout << "The decimal equivalent is: " << num_10 << " obviously...\n";
	}
	else if(choice_in == 'd' && choice_out == 'h'){
		num_10 = get_number();
		convert_number_hex(num_10, count_digits(num_10));
	}

	//hexidecimal calls
	if(choice_in == 'h' && choice_out == 'b'){
		num_10 = convert_hex_decimal();
		convert_decimal_binary(num_10,  count_binary_digits(num_10));
	}
	else if(choice_in == 'h' && choice_out == 'd'){
		num_10 = convert_hex_decimal();
		cout << "The decimal equivalent is: " << num_10 <<'\n';
	}
	else if(choice_in == 'h' && choice_out == 'h'){
		num_10 = convert_hex_decimal();
		convert_number_hex(num_10, count_digits(num_10));
	}
}

//binary-decimal functions start
int convert_binary_number(){
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

	return decimal_number;
}

int get_binary_place_value(int binary_digits){
        int binary_place_value = 1;

        for(int i = 1; i < binary_digits; i++){
                binary_place_value *= 2;
        }

        return binary_place_value;
}
//binary-decimal f() end

//decimal-binary f() start
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

	cout << "The binary equivalent: ";
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
//decimal-binary f() end

//decimal-hex f() start
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
//decimal-hex f() end

//f() for decimal start
int get_number(){
        int num = 0;

        cout << "Enter a number base 10: ";
        cin >> num;

        return num;
}
//f() for decimal end

//f() hex to decimal start
int convert_hex_decimal(){
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

        return decimal_num;
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
//f() hex to decimal end
