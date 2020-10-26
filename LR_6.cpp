#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>

int whithout_mistakes;

template <typename arr>
void binary_search(arr* array, int const size, std::string type);
void binary_search(std::string* array, int const size, std::string type);
template <typename arr>
void enter_the_arr(arr* array, int const size, std::string type);
void enter_the_arr(std::string* array, int const size, std::string type);
template <typename arr>
void quick_sort(arr* array, int const len);
void quick_sort(std::string* array, int const len);
template <typename arr>
void print_the_arr(arr* array, int const size, std::string type);
void print_the_arr(std::string* array, int const size, std::string type);
void enter_the_size(int& size, std::string type);

int main()
{
	system("chcp 1251");
	system("CLS");

	int size[5];
	int* i;
	char* c;
	float* f;
	double* d;
	std::string* str;	//Ленивый, поэтому string вместо char*

	enter_the_size(size[0], "int");
	i = new int[size[0]];
	enter_the_arr(i, size[0], "int");
	quick_sort(i, size[0]);
	print_the_arr(i, size[0], "int");
	binary_search(i, size[0], "int");

	enter_the_size(size[1], "char");
	c = new char[size[1]];
	enter_the_arr(c, size[1], "char");
	quick_sort(c, size[1]);
	print_the_arr(c, size[1], "char");
	binary_search(c, size[1], "char");

	enter_the_size(size[2], "float");
	f = new float[size[2]];
	enter_the_arr(f, size[2], "float");
	quick_sort(f, size[2]);
	print_the_arr(f, size[2], "float");
	binary_search(f, size[2], "float");

	enter_the_size(size[3], "double");
	d = new double[size[3]];
	enter_the_arr(d, size[3], "double");
	quick_sort(d, size[3]);
	print_the_arr(d, size[3], "double");
	binary_search(d, size[3], "double");

	enter_the_size(size[4], "char* (string)");
	str = new std::string[size[4]];
	enter_the_arr(str, size[4], "char* (string)");
	quick_sort(str, size[4]);
	print_the_arr(str, size[4], "char* (string)");
	binary_search(str, size[4], "char* (string)");

    std::cout << "\n\n\nHello World!\n";
	whithout_mistakes = getchar(); whithout_mistakes = getchar();
}

template <typename arr>
void binary_search(arr *array, int const size, std::string type) {

	int left = 0, right = size;
	int search = -1;
	arr key;

	std::cout << "Введите элемент " << type <<" массива, "
		<<"который надо найти: ";
	while (!(std::cin >> key)) {
		std::cout << "\nОшибка! Повторите: ";
		std::cin.clear();
		rewind(stdin);
	} std::cin.clear(); rewind(stdin);

	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == array[mid]) {
			search = mid;
			break;
		}
		if (key < array[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (search == -1)
		std::cout << "\n\nЭлемент не найден!\n\n";
	else
		std::cout << "\n\nЭлемент найден!\nКлюч: " << key
		<< "\tНайденный элемент arr[" << search << "]: " << array[search];
	std::cout << "\n\n";
	system("pause"); std::cout << "\n\n";
}


void binary_search(std::string* array, int const size, std::string type) {

	int left = 0, right = size;
	int search = -1;
	std::string key;

	std::cout << "Введите элемент " << type << " массива, "
		<< "который надо найти: ";
	while (!(std::cin >> key)) {
		std::cout << "\nОшибка! Повторите: ";
		std::cin.clear();
		rewind(stdin);
	} std::cin.clear(); rewind(stdin);

	while (left <= right) {
		int mid = (left + right) / 2;
		if (key == array[mid]) {
			search = mid;
			break;
		}
		if (key < array[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (search == -1)
		std::cout << "\n\nЭлемент не найден!\n\n";
	else
		std::cout << "\n\nЭлемент найден!\nКлюч: " << key
		<< "\tНайденный элемент arr[" << search << "]: " << array[search];
	std::cout << "\n\n";
	system("pause"); std::cout << "\n\n";
}

template <typename arr>
void quick_sort(arr* array, int const len) {		//Шаблон №2
	
	int const lenD = len;
	int ind = lenD / 2;
	int i, j = 0, k = 0;
	arr pivot;

	if (lenD > 1) {
		arr *L = new arr[lenD];
		arr *R = new arr[lenD];
		pivot = array[ind];
		for (i = 0; i < lenD; i++) {
			if (i != ind) {
				if (array[i] < pivot) {
					L[j] = array[i];
					j++;
				}
				else {
					R[k] = array[i];
					k++;
				}
			}
		}
		quick_sort(L, j);
		quick_sort(R, k);
		for (int cnt = 0; cnt < lenD; cnt++) {
			if (cnt < j) {
				array[cnt] = L[cnt];
			}
			else if (cnt == j) {
				array[cnt] = pivot;
			}
			else {
				array[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}


void quick_sort(std::string* array, int const len) {		//Перегрузка шаблона №2

	int const lenD = len;
	int ind = lenD / 2;
	int i, j = 0, k = 0;
	std::string pivot;

	if (lenD > 1) {
		std::string *L = new std::string[lenD];
		std::string *R = new std::string[lenD];
		pivot = array[ind];
		for (i = 0; i < lenD; i++) {
			if (i != ind) {
				if (array[i] < pivot) {
					L[j] = array[i];
					j++;
				}
				else {
					R[k] = array[i];
					k++;
				}
			}
		}
		quick_sort(L, j);
		quick_sort(R, k);
		for (int cnt = 0; cnt < lenD; cnt++) {
			if (cnt < j) {
				array[cnt] = L[cnt];
			}
			else if (cnt == j) {
				array[cnt] = pivot;
			}
			else {
				array[cnt] = R[cnt - (j + 1)];
			}
		}
	}
}

template <typename arr>
void enter_the_arr(arr *array, int const size, std::string type) {  //Шаблон №3

	arr temp;

	for (int i = 0; i < size; i++) {
		std::cout << "Введите " << (i + 1) << " элемент " << type <<" массива: ";
		while (!(std::cin >> temp)) {
			std::cout << "Ошибка! Повторите: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);
		array[i] = temp;
	}
}


void enter_the_arr(std::string* array, int const size, std::string type) {  //Перегрузка шаблона №3

	std::string temp;

	for (int i = 0; i < size; i++) {
		std::cout << "Введите " << (i + 1) << " элемент " << type << " массива: ";
		while (!(std::cin >> temp)) {
			std::cout << "Ошибка! Повторите: ";
			std::cin.clear();
			rewind(stdin);
		} std::cin.clear(); rewind(stdin);
		array[i] = temp;
	}
}

template <typename arr>
void print_the_arr(arr* array, int const size, std::string type) {
	std::cout << "\n\nОтсортированный " << type << " массив: ";
	for (int i = 0; i < size; i++)
		std::cout << array[i] << "  ";
	std::cout << "\n\n";
}

void print_the_arr(std::string* array, int const size, std::string type) {
	std::cout << "\n\nОтсортированный " << type << " массив: ";
	for (int i = 0; i < size; i++)
		std::cout << array[i] << "  ";
	std::cout << "\n\n";
}

void enter_the_size(int& size, std::string type) {

	std::cout << "Введите размер массива " << type << ": ";
	while (!(std::cin >> size) || std::cin.fail() || (size < 0 && size>50)) {
		std::cout << "\nОшибка! Повторите: ";
		std::cin.clear();
		rewind(stdin);
	} std::cin.clear(); rewind(stdin); std::cout << "\n\n";
}


//----------------------------------------------------------------------- Функции безошибочного ввода (не использую) --------------------------------------------------------//

void fun_bezumniy_vvod_int(int& perem, std::string type) {		//Функция игнорирующая символы при вводе (только для Интов)
	
	char check[64], check_temp[64];
	int temp, j = 0;
	
	std::cout << "Введите размер массива " << type << ": ";
	for (int i = 0; i < 64; i++) {
		if (check[i] > '0' && check[i] < '9') {
			check_temp[j] = check[i];
			j++;
		}
	} temp = j;
	for (int i = 0; i < temp; i++) {
		perem += (check_temp[i] - '0') * pow(10, (j - 1));
		j--;
	}
}

void fun_bezumniy_vvod_float(float& perem, std::string type) {

	char check[64], check_temp[64];
	int temp, k = 0, j = 0, g = 0, point = -1;

	std::cout << "Введите размер массива " << type << ": ";
	for (int i = 0; i < 64; i++) {
		//if ((check[i] > '0' && check[i] < '9') || 
		//	(check[i] == '.' && point == -1)) {
			if ((check[i] > '0' && check[i] < '9') && point == -1) {
				check_temp[k] = check[i];
				j++; k++;
			}
			if (check[i] == '.' && point == -1) {
				check_temp[k] = check[i];
				k++;
			}
			if ((check[i] > '0' && check[i] < '9') && point == 1) {
				check_temp[k] = check[i];
				g++; k++;
			}
		//}
	} temp = j;
	//while (check_temp[g++] != '.') point = 1;
	for (int i = 0; i < temp; i++) {
		perem += (check_temp[i] - '0') * pow(10, (j - 1));
		j--;
	} temp = k;
	for (int i = temp - g, l = 1; i < temp, l<=g; i++, l++) {
		perem += (check_temp[i] - '0') * pow(10, (-l));
	}
}
