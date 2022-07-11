#include <iostream>
using std::cin;
using std::cout;

/*
How The ISBN Check Digit Is Calculated:
1. Take the first 12 digits of the 13 digit ISBN
2. Multiply each number in turn, from left to right alternating by 1 and 3. The first digit is multiplied by 1, the second by 3, stop at the 12th digit.
3. Sum the products of the digits.
4. Do a mod 10 on the result from step 2.
5. Compare step 4 result with the last digit of the ISBN.

e.g: 978-1-59327-424-5
 9 x 1 = 9
 7 x 3 = 21
 8 x 1 = 8
 1 x 3 = 3
 5 x 1 = 5
 9 x 3 = 27
 3 x 1 = 3
 2 x 3 = 6
 7 x 1 = 7
 4 x 3 = 12
 2 x 1 = 2
 4 x 3 = 12
  sum  = 115
115%10 = 5 
*/

void check_ISBN();

int main(){
	check_ISBN();
	return 0;
}

void check_ISBN(){
	char current_digit = 0;
	int digit_pointer = 0;
	int sum = 0;

	cout << "Enter the ISBN number: ";
	
	while((current_digit = cin.get()) != '\n' && digit_pointer != 12){
		if(digit_pointer % 2 == 0){
			sum += (current_digit - '0');
		}
		else{
			sum += 3 * (current_digit - '0');
		}
		digit_pointer++;
	}
	if(current_digit - '0' == sum % 10){
		cout << current_digit  << " = " << sum % 10 << " ISBN is valid\n";
	}
	else{
		cout << "ISBN is invalid check digit does not match." << '\n' << current_digit << " does not equal " << sum % 10 << '\n';
	}
}
