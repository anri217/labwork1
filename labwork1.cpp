#include <fstream>
#include <iostream>

using namespace std;

const double EPS = 1e-9;

double sum(double* arr, unsigned int length)
{
	double b = 0;

	for (size_t i = 0; i < length; ++i) {
		if (arr[i] < EPS) {
			b += arr[i] * arr[i];
		}
	}

	return b;
}

double* readArray(ifstream& in, int& length)
{
	in >> length;
	double* array = new double[length];
	int i = 0;
	while (i < length) {
		in >> array[i];
		++i;
	}
	return array;
}

int main()
{
	double a = 0;
	int length = 0;
	ifstream ifs("input.txt");
	double* nums = readArray(ifs, length);

	a = sum(nums, length);

	ifs.close();

	ofstream ofs("output.txt");

	ofs << a;

	ofs.close();

	cout << "All elements of array: ";
	for (int i = 0; i < length; ++i) {
		cout << nums[i] << " ";
	}

	cout << endl << "Sum of squares of all negative elements: " << a << endl;

	delete[] nums;

	system("pause");
	return 0;
}