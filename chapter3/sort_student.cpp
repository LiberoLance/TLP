#include <iostream>
#include <cstdlib>
using namespace std;

int compare_grade(const void*, const void*);
int compare_id(const void*, const void*);

struct student{
                int grade;
                int id;
                string name;
};

int main(){

	const int SIZE = 10;
	student student_array[SIZE] = {
		{87, 10001, "Fred"},
		{28, 10002, "Tom"},
		{100, 10003, "Alistair"},
		{78, 10004, "Sasha"},
		{84, 10005, "Erin"},
		{98, 10006, "Belinda"},
		{75, 10007, "Leslie"},
		{70, 10008, "Candy"},
		{81, 10009, "Aretha"},
		{68, 10010, "veronica"}
	};

	cout << "Before sorting the array\n";
	for(int i = 0; i < SIZE; i++){
		cout << student_array[i].grade << ' ';
	}
	cout << '\n';
	qsort(student_array, SIZE, sizeof(student), compare_grade);
	cout << "After sorting by grades\n";
	for(int i = 0; i < SIZE; i++){
		cout << student_array[i].grade << ' ';
	}
	cout << "\n\n";

	cout << "Before sorting the array\n";
        for(int i = 0; i < SIZE; i++){
                cout << student_array[i].id << ' ';
        }
        cout << '\n';
        qsort(student_array, SIZE, sizeof(student), compare_id);
        cout << "After sorting by grades\n";
        for(int i = 0; i < SIZE; i++){
                cout << student_array[i].id << ' ';
        }
        cout << '\n';
}

int compare_grade(const void * va, const void * vb){
	const student * a = (student*)va;
	const student * b = (student*)vb;

	return (a -> grade - b -> grade);
}
int compare_id(const void * va, const void * vb){
	const student * a = (student*)va;
        const student * b = (student*)vb;

        return (a -> id - b -> id);
}
