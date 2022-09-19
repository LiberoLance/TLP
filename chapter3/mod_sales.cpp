#include <iostream>
using namespace std;

double median(int [], int);
int compare(const void *, const void *);

int main(){
	const int A = 3; //Agents;
	const int M = 12; //Months;
	int largest_median = 0;
	int current_median = 0;
  int N = 0; //size of array after filtering out -1s.

	int agent_sales[A][M] = {
					{1856, 498, 30924, 87478, 328, 2653, 387, 3754, 38758, 2873, 276, 32},
					{5865, 5456, 3983, 6464, 9957, 4785, 3875, 3838, 4959, 1122, 7766, 1534},
					{23, 55, 67, 99, 265, 376, 232, 223, 4546, 564, 4544, 3434}
				};

	cout << "before sorting...\n";
	for(int i = 0; i < A; i++){
		for(int j = 0; j < M; j++){
			 if(agent_sales[A][M] != -1){
          			N++;
       			 }
		}
		int current_agent[N];
		int i = 0;
		for(int j = 0; j < M; j++){
			if(agent_sales[A][M] != -1){
				current_agent[i++] = agent_sales[A][M];
			}
		}
		//wrote valid sales data into current_agent
		
  }
	cout << "\nafter...\n";
	qsort(agent_sales, 12, sizeof(int), compare);
	for(int i = 0; i < A; i++){
		for(int j = 0; j < M; j++){
			 cout << agent_sales[i][j] <<  ' ';
		}
		cout << '\n';
	}
	
	cout << '\n';

	for(int i = 0; i < A; i++){
		current_median = median(agent_sales[i], M);
		if(current_median > largest_median){
			largest_median = current_median;
		}
	}

	cout << "The largest median sale is: " << largest_median << '\n';

	return 0;
}

double median(int array[], int SIZE){
	//index = SIZE
	double median = 0;

	if(SIZE %2 == 0){
		SIZE /= 2;
		median = (array[SIZE] + array[SIZE - 1]) / 2.0;
	}
	else{
		SIZE /= 2;
		median = array[SIZE];
	}

	
	return median;
}

int compare(const void* va, const void* vb){
	int eval = 0;

	int* a = (int*) va;
	int* b = (int*) vb;
	
	if(*a > *b){
		eval = 1;
	}
	else if (*a < * b){
		eval = -1;
	}

	return eval;
}
