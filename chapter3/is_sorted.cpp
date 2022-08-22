#include <iostream>
using namespace std;

bool is_sorted(int[], int);

int main(){
	const int N = 5;
	char array[N] = {1, 3, 2};

	cout << is_sorted(array, N) << '\n';

	return 0;
}

bool is_sorted(int array[], int N){
	bool is_sorted = true;

	for(int i = 1; i < N; i++){
		if(array[i - 1] > array[i]){
			is_sorted = false;
			break;
		}
	}

	return is_sorted;
}
