#include <iostream>
using namespace std;

struct student{
                int grade;
                int id;
                string name;
};

int compare_grade(const void*, const void*);
double median(student [], int);

int main(){

	const int N = 9;
	student student_array[N] = {
		{87, 10001, "Fred"},
		{28, 10002, "Tom"},
		{100, 10003, "Alistair"},
		{78, 10004, "Sasha"},
		{84, 10005, "Erin"},
		{98, 10006, "Belinda"},
		{75, 10007, "Leslie"},
		{70, 10008, "Candy"},
		{81, 10009, "Aretha"},
		//{68, 10010, "Veronica"}
	};
	double lower_median = 0;
	double mid_median = 0;
	double upper_median = 0;

	qsort(student_array, N, sizeof(student), compare_grade);
	for(int i = 0; i < N; i++){
		cout << student_array[i].grade << ' ';
	}
	cout << '\n';
	
	if(N % 2 == 0){
		lower_median = median(student_array, N/4 + 2);	
		mid_median = median(student_array, N);
		upper_median = median(student_array + (N * 3 / 4) - 1, N - (N * 3 / 4) + 1);
	}
	else{
		lower_median = median(student_array, N / 2);
		mid_median = median(student_array, N);
		upper_median = median(student_array + (N / 2) + 1, N / 2);
	}

        cout << "the lower quartile is: " << lower_median << '\n';
	cout << "the middle quartile is: " << mid_median << '\n';
	cout << "the upper_quartile is: " << upper_median << '\n';
        
	return 0;
}

int compare_grade(const void * va, const void * vb){
        const student * a = (student*)va;
        const student * b = (student*)vb;

        return (a -> grade - b -> grade);
}

double median(student array[], int SIZE){
        //index = SIZE
        double median = 0;

        if(SIZE %2 == 0){
                SIZE /= 2;
                median = (array[SIZE].grade + array[SIZE - 1].grade) / 2.0;
        }
        else{
                SIZE /= 2;
                median = array[SIZE].grade;
        }


        return median;
}
