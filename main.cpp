#include <iostream>
#include <vector>
using namespace std;



vector<int> vector_int;
void fill_vector_int() {
	vector_int.push_back(11);
	vector_int.push_back(11);
	vector_int.push_back(18);
	vector_int.push_back(28);
	vector_int.push_back(7);
	vector_int.push_back(3);
	vector_int.push_back(4);
	vector_int.push_back(12);
	vector_int.push_back(2);
	vector_int.push_back(2);
	vector_int.push_back(28);
	vector_int.push_back(61);
	vector_int.push_back(2);
	vector_int.push_back(77);
	vector_int.push_back(11);
	vector_int.push_back(11);
}

void print_vector_int() {
	cout << "{ ";
	for (int item : vector_int) {
		cout << item << " ";
	}
	cout << "}";

}

void remove_odd_1() {
	int next = 1;
	int vector_size = vector_int.size();
	int final_size = 0;
	for (int i = 0; i < vector_size - 1, next < vector_size; i++) {
		if (vector_int[i] % 2 != 0) {
			for (next; next < vector_size; next++) {
				if (vector_int[next] % 2 == 0) {
					final_size++;
					swap(vector_int[i], vector_int[next]);
					break;
				}
			}
		}
		else {
			final_size++;
		}
		next++;
	}
	vector_int.resize(final_size);
}

void remove_odd_2() {
	for (int i = vector_int.size() - 1; i >= 0; i--) {
		if (vector_int[i] % 2 != 0) {
			vector_int.erase(next(vector_int.begin(), i), next(vector_int.begin(), i + 1));
		}
	}
}

void remove_duplicates_1() {
	int vector_size = vector_int.size();
	for (int i = 0; i < vector_size; i++) {
		int count = 0;
		for (int g = i + 1; g < vector_size; g++) {
			if (vector_int[i] == vector_int[g]) {
				count++;
			}
			else {
				if (count > 0) {
					vector_int[g - count] = vector_int[g];
				}
			}
		}
		vector_size -= count;
		vector_int.resize(vector_size);
	}
}

void remove_duplicates_2() {
	int vector_size = vector_int.size();
	for (int i = 0; i < vector_size; i++) {
		for (int g = vector_size - 1; g >= i + 1; g--) {
			if (vector_int[i] == vector_int[g]) {
				vector_int.erase(next(vector_int.begin(), g), next(vector_int.begin(), g + 1));
				vector_size--;

			}
		}
		vector_int.resize(vector_size);
	}
}


int main() {
	fill_vector_int();
	cout << "Vector: ";
	print_vector_int();
	cout << endl;

	remove_duplicates_1();
	//remove_duplicates_2();
	cout << "Removed duplicates: ";
	print_vector_int();
	cout << endl;

	remove_odd_1();
	//remove_odd_2();
	cout << "Removed odd numbers: ";
	print_vector_int();

	return 0;
}