#include <iostream>
using std::cin;
using std::cout;

int main(){
	char cipher[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
	char decipher[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char input = '\0';

	cout << "Enter a message to be encoded, ALL CAPS: ";
	while((input = cin.get()) != '\n'){
		if(input == ' '){
			cout << input;
			continue;
		}
		for(int i = 0; i < 26; i++){
			if(input == decipher[i]){
				cout << cipher[i];
				break;
			}
		}
	}
	cout << '\n';	

	return 0;
}
