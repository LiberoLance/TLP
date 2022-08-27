

#include <iostream>
using std::cin;
using std::cout;

int main(){
	char cipher[26] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
	char decipher[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	char input = '\0';
  char cipher_text[100];
  int index = 0;
  
	cout << "Enter a message to be encoded, ALL CAPS: ";
	while((input = cin.get()) != '\n' && index < 100){
		if(input == ' '){
      cipher_text[index] = input;
      index++;
      cout << input;
			continue;
		}
		for(int i = 0; i < 26; i++){
			if(input == decipher[i]){
        cipher_text[index] = cipher[i];
        index++;
        cout << cipher[i];
				break;
			}
		}
	}
	cout << '\n';
  cout << "Decoding the cipher text: \n";
  for(int i = 0; i < index; i++){
      if(cipher_text[i] == ' '){
          cout << cipher_text[i];
          continue;
      }
      for(int j = 0; j < 26; j++){
          if(cipher_text[i] == cipher[j]){
              cout << decipher[j];
              break;
          }
      }
  }
  cout << '\n';

	return 0;
}
