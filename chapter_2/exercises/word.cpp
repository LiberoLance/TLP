#include <iostream>

using std::cin;
using std::cout;

void prompt();
void read_input();
char id_char(char);

int main(){
	
	prompt();
	read_input();

	return 0;
}

void prompt(){
	cout << "Enter a sentence to find out the number of words, the largest word, and the greatest number of vowels and consonants in a word.\n";
}

void read_input(){
	char character = '\0';
	char gate = '\0';
	int character_count = 0;
	int largest_char = 0;
	int vowel_count = 0;
	int largest_vowel;
	int word_count = 0;

	cout << "Enter a sentence: ";
	character = cin.get();
	while(character != '\n'){
		gate = id_char(character);
	
		if(gate == 'c'){
			character_count++;
		}
		else if(gate == 'v'){
			vowel_count++;
		}
		else if(gate == 'w'){
			word_count++;
			if(largest_char < (character_count + vowel_count)){
				largest_char = character_count + vowel_count;
			}
			if(largest_vowel < vowel_count){
				largest_vowel = vowel_count;
			}
			character_count = 0;
			vowel_count = 0;
		}
		character = cin.get();
	}

	gate = id_char(character);

        if(gate == 'w'){
                word_count++;
	}
        if(largest_char < (character_count + vowel_count)){
        	largest_char = character_count + vowel_count;
        }
        if(largest_vowel < vowel_count){
                largest_vowel = vowel_count;
        }
         
	cout 	<< "number of words: "<< word_count
		<< "\nThe largest amount of vowels: " << largest_vowel
		<< "\nThe largest amount of characters in a single word: " << largest_char << '\n'; 
}

char id_char(char character){
	char type = '\0';
	
	switch(character){
		case 'b': type = 'c';
		break;
		case 'c': type = 'c';
                break;
		case 'd': type = 'c';
                break;
		case 'f': type = 'c';
                break;
		case 'g': type = 'c';
                break;
		case 'h': type = 'c';
                break;
		case 'j': type = 'c';
                break;
		case 'k': type = 'c';
                break;
		case 'l': type = 'c';
                break;
		case 'm': type = 'c';
                break;
		case 'n': type = 'c';
                break;
		case 'p': type = 'c';
                break;
		case 'q': type = 'c';
                break;
		case 'r': type = 'c';
                break;
		case 's': type = 'c';
                break;
		case 't': type = 'c';
                break;
		case 'v': type = 'c';
                break;
		case 'w': type = 'c';
                break;
		case 'x': type = 'c';
                break;
		case 'y': type = 'c';
                break;
		case 'z': type = 'c';
                break;
		case 'a': type = 'v';
                break;
		case 'e': type = 'v';
                break;
		case 'i': type = 'v';
                break;
		case 'o': type = 'v';
                break;
		case 'u': type = 'v';
                break;
		case ' ': type = 'w';
                break;
		case '\n': type = 'w';
		break;
	}
	
	return type;
}
