#include<iostream>
#include<time.h>
#include<vector>
#include<algorithm>
#include<termcolor/termcolor.hpp>
using namespace std;

template <typename T>
int interpolation_search(vector<T> sorted_array, int key)
{
	int mid = 0;
	int low = 0;
	int high = sorted_array.size() - 1;
	int count_iter = 0;

	while (sorted_array[low] < key && sorted_array[high] > key)
	{
		if (sorted_array[high] == sorted_array[low])
		{
			break;
		}

		mid = low + ((key - sorted_array[low]) * (high - low)) / (sorted_array[high] - sorted_array[low]);

		if (sorted_array[mid] < key)
		{
			low = mid + 1;
		}

		else if (sorted_array[mid] > key)
		{
			high = mid - 1;
		}

		else
		{
			++count_iter;
			cout << "Count of iterations: " << count_iter << endl;
			return mid;
		}

		++count_iter;
	}

	cout << "Count of iterations: " << count_iter << endl;

	if (sorted_array[low] == key)
	{
		return low;
	}

	if (sorted_array[high] == key)
	{
		return high;
	}

	return -1;
}

template <typename T>
int sequential_search(vector<T> south, int key)
{
	int count_iter = 0;

	for (int i = 0; i < south.size(); i++)
	{
		if (south[i] == key)
		{
			cout << "Count of iterations: " << count_iter << endl;
			return i;
		}

		++count_iter;
	}

	cout << "Count of iterations: " << count_iter << endl;
	return -1;
}

int main()
{
	srand(time(NULL));
	vector<int> array_test;
	int size = 20;

	for (int i = 0; i < size; i++)
	{
		array_test.push_back(rand() % 20);
	}

	for (int i = 0; i < size; i++)
	{
		cout << array_test[i] << " ";
	}
	cout << endl;

	sort(array_test.begin(), array_test.end());

	for (int i = 0; i < size; i++)
	{
		cout << array_test[i] << " ";
	}
	cout << endl;

	int find = 0;
	int find2 = 0;
	find = interpolation_search(array_test, 18);
	if (find != -1)
	{
		cout << array_test[find] << endl;
	}

	find2 = sequential_search(array_test, 18);
	if (find2 != -1)
	{
		cout << array_test[find2] << endl;
	}

	cout << "////////////////" << endl;

	vector<int> vector1;
	vector1.push_back(200);

	for (int i = 0; i < 9999; i++)
	{
		vector1.push_back(rand() % 10000);
	}
	
	sort(vector1.begin(), vector1.end());
	find = interpolation_search(vector1, 200);
	if (find != -1)
	{
		cout << termcolor::bright_green <<"Result of alogithm:" << termcolor::bright_yellow << vector1[find] << endl;
	}

	find2 = sequential_search(vector1, 200);
	if (find2 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector1[find2] << endl;
	}

	cout << termcolor::reset << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl << endl;

	vector<int> vector2;
	// элемент в начале массива
	vector2.push_back(-45);
	int size_test = 5;
	for (int i = 0; i < size_test - 1; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	sort(vector2.begin(), vector2.end());
	int find_begin = 0;
	find_begin = interpolation_search(vector2, -45);
	if (find_begin != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector2[find_begin] << endl;
	}

	// элемент в конце массива
	vector2.clear();
	for (int i = 0; i < size_test - 1; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	vector2.push_back(7);
	sort(vector2.begin(), vector2.end());
	int find_end = 0;
	find_end = interpolation_search(vector2, 7);
	if (find_end != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector2[find_end] << endl;
	}

	// элемент в середине массива
	vector2.clear();
	for (int i = 0; i < size_test / 2 - 1; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	vector2.push_back(size_test / 2);

	for (int i = size_test / 2 + 1; i < size_test; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	sort(vector2.begin(), vector2.end());
	int find_mid = 0;
	find_mid = interpolation_search(vector2, size_test / 2);
	if (find_mid != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector2[find_mid] << endl;
	}

	// элемента нет в массиве и он меньше первого
	vector2.clear();
	for (int i = 0; i < size_test; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	sort(vector2.begin(), vector2.end());
	int find_not_less_first = 0;
	find_not_less_first = interpolation_search(vector2, vector2[0] - 100);
	if (find_not_less_first != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector2[find_not_less_first] << endl;
	}

	// элемента нет в массиве и он больше последнего
	vector2.clear();
	for (int i = 0; i < size_test; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	sort(vector2.begin(), vector2.end());
	int find_not_more_last = 0;
	find_not_more_last = interpolation_search(vector2, vector2[size_test - 1] + 1000);
	if (find_not_more_last != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector2[find_not_more_last] << endl;
	}

	// элемента нет в массиве и он должен быть где-то в середине массива
	vector2.clear();
	for (int i = 0; i < size_test; i++)
	{
		vector2.push_back(rand() % size_test);
	}

	sort(vector2.begin(), vector2.end());
	int find_not_mid = 0;
	find_not_mid = interpolation_search(vector2, size_test / 2);
	if (find_not_mid != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector2[find_not_mid] << endl;
	}

	cout << "--------------------------------------------" << endl << endl;

	// тестирование последовательного поиска
	vector<int> vector3;
	size_test = 1000000;
	// элемент в начале массива
	vector3.push_back(-777);
	for (int i = 0; i < size_test - 1; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	int find_begin1 = 0;
	find_begin1 = sequential_search(vector3, -777);
	if (find_begin1 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector3[find_begin1] << endl;
	}

	// элемент в конце массива
	vector3.clear();
	for (int i = 0; i < size_test - 1; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	vector3.push_back(1100000);
	int find_end1 = 0;
	find_end1 = sequential_search(vector3, 1100000);
	if (find_end1 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector3[find_end1] << endl;
	}

	// эдемент в середине массива
	vector3.clear();
	for (int i = 0; i < size_test / 2 - 1; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	vector3.push_back(size_test / 2);

	for (int i = size_test / 2 + 1; i < size_test; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	int find_mid1 = 0;
	find_mid1 = sequential_search(vector3, size_test / 2);
	if (find_mid1 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector3[find_mid1] << endl;
	}

	// элемента нет в массиве и он меньше первого 
	vector3.clear();
	for (int i = 0; i < size_test; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	int find_not_less_first1 = 0;
	find_not_less_first1 = sequential_search(vector3, vector3[0] * (-100));
	if (find_not_less_first1 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector3[find_not_less_first1] << endl;
	}

	// элемента нет в массиве и он больше последнего
	vector3.clear();
	for (int i = 0; i < size_test; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	int find_not_more_last1 = 0;
	find_not_more_last1 = sequential_search(vector3, vector3[size_test - 1] * 1000);
	if (find_not_more_last1 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector3[find_not_more_last1] << endl;
	}

	// элемента нет в массиве и он должен быть где-то в середине массива
	vector3.clear();
	for (int i = 0; i < size_test; i++)
	{
		vector3.push_back(rand() % size_test);
	}

	int find_not_mid1 = 0;
	find_not_mid1 = sequential_search(vector3, size_test / 2 - 4);
	if (find_not_mid1 != -1)
	{
		cout << termcolor::bright_green << "Result of alogithm:" << termcolor::bright_yellow << vector3[find_not_mid1] << endl;
	}
}