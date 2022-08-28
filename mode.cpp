#include <iostream>
using std::cin;
using std::cout;

int main(){
	int const N = 10;
	int set[N] = {1, 22, 12, 14, 7, 4, 5, 3, 4, 10};
	int mode = 0;
	int current_num = 0;
	int this_num_count = 0;
	int last_num_count = 0;

	for(int i = 0; i < N; i++){
		current_num = set[i];
		this_num_count++;
		for(int j = i + 1; j < N; j++){
			if(current_num == set[j]){
				this_num_count++;
			}
		}
		if(last_num_count < this_num_count){
			mode = current_num;
			last_num_count = this_num_count;
		}
		this_num_count  = 0;
	}

	cout << "The mode is " << mode << '\n'; 
	return 0;
}
