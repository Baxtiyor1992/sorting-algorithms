/**
 * SelectionSort.cpp
 * 
 * Tanlash orqali tartiblash algoritmi
 *
 * Eng yomon xolat uchun algoritm murakkabligi: O(n^2)
 * Eng yaxshi uchun algoritm murakkabligi: O(n^2)
 *
 * Bu tartiblash algoritmida massivni tartiblanmagan qismidan eng kichik 
 * elementni topib uni 
 */

#include <iostream>

using namespace std;

// Ikkita elementni qiymatlarini almashtiradigan protsedura
void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

// Massiv elementlarini ekranga chiqadigan protsedura
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

// Tanlash orqali tartiblash protsedurasi
void selectionSort(int array[], int size) {
	// Tanlash orqali tartiblashda takrorlanishlar soni N - 1 ta bo'ladi.
	// Chunki undan oldingi barcha elementlar algoritm orqali tartiblab 
	// bo'linganida oxirgi element ham o'z o'rnini topgan bo'ladi
	for (int i = 0; i < size - 1; i++) {
		// Massivni joriy o'rniga joylashtiriladigan element indeksi
		int indexToSwap = i;

		for (int j = i + 1; j < size; j++) {
			if (array[indexToSwap] > array[j]) {
				indexToSwap = j;
			}
		}

		if (indexToSwap != i) {
			swap(array[indexToSwap], array[i]);
		}
	}
}

int main() {
	// Testlash uchun massivni e'lon qilib olamiz
	int array[] = { 1, 3, 9, 6, 7, 8, 2, 4, 5 };

	// Massiv olgan xotiraga qarab massiv o'lchamini aniqlab olamiz
	int size = sizeof(array) / sizeof(int);

	// Tartiblashdan oldin ma'lumotlarni ekranga chiqaramiz
	cout << "Before sorting: " << endl;
	printArray(array, size);

	// Massivni tartiblaymiz
	selectionSort(array, size);

	// Tartiblangan massivni ekranga chiqaramiz
	cout << "After sorting: " << endl;
	printArray(array, size);

	return 0;
}
