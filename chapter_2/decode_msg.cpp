#include <iostream>
using std::cin;
using std::cout;

enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};

void decode();
modeType printDeChar(modeType, int);

int main(){
        decode();
        return 0;
}

void decode(){
        modeType mode = UPPERCASE;
        char current_char;
        int num;

        cout << "Enter the message: ";
        current_char = cin.get();
        num = current_char - '0';
        do{

                while((current_char = cin.get()) != ',' && current_char != '\n'){
                        num = num * 10 + (current_char - '0');
                }

                mode = printDeChar(mode, num);
                num = 0;
        }while(current_char != '\n');
        cout << '\n';
}

modeType printDeChar(modeType mode, int num){
        char output;
        modeType update_mode = mode;
        switch(mode){
                case UPPERCASE:
                        if(num % 27 == 0){
                                output = (num % 27) + 'A' - 1;
                                update_mode = LOWERCASE;
                        }
                        else{
                                output = (num % 27) + 'A' - 1;
                                cout << output;
                        }
                break;
                case LOWERCASE:
                        if(num % 27 == 0){
                                output = (num % 27) + 'a' - 1;
                                update_mode = PUNCTUATION;
                        }
                        else{
                                output = (num % 27) + 'a' - 1;
                                cout << output;
                        }
                break;
                case PUNCTUATION:
                        switch(num % 9){
                                case 0: update_mode = UPPERCASE; break;
                                case 1: cout << '!'; break;
                                case 2: cout << '?'; break;
                                case 3: cout << ','; break;
                                case 4: cout << '.'; break;
                                case 5: cout << ' '; break;
                                case 6: cout << ';'; break;
                                case 7: cout << '"'; break;
                                case 8: cout << '\''; break;
                        }
                        break;
        }
        return update_mode;
}
