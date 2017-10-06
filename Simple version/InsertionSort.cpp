/**
 * InsertionSort.cpp
 * 
 * Orasiga qo'yish orqali tartiblash algoritmi
 *
 * Eng yomon xolat uchun algoritm murakkabligi: O(n^2)
 * Eng yaxshi uchun algoritm murakkabligi: O(n^2)
 *
 * Bu algoritmda dastlabki element olinadi. Keyingi element esa birinchi element
 * bilan taqqoslangan holda joylashtiriladi. Qolgan barcha elementlar ham shu 
 * tartibda o'zidan oldingi elementlar bilan taqqoslagan holda joylashtirib 
 * boriladi  
 */

#include <iostream>

using namespace std;

// Massiv elementlarini ekranga chiqadigan protsedura
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

// Orasiga qo'yish orqali tartiblash protsedurasi
void insertionSort(int array[], int size) {
	// Massivni saralash ikkinchi elementdan boshlanganligi sabab siklni 0 dan
	// emas 1 dan boshlaymiz
	for (int i = 1; i < size; i++) {
		// Element qiymatini alohida o'zgaruvchiga olamiz
		int itemValue = array[i];

		// Taqqoslab boriladigan element indeksi
		int j = i - 1;

		// Joriy elementdan katta bo'lgan elementlarni o'ngga suramiz
		while (j >= 0 && array[j] > itemValue) {
			// Elementni surish
			array[j + 1] = array[j];
			
			// Oldingi elementga o'tish
			j--;
		}

		// Barcha katta elementlar surib bo'linganidan keyin joriy elementni 
		// joylashtiramiz
		array[j + 1] = itemValue;
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
	insertionSort(array, size);

	// Tartiblangan massivni ekranga chiqaramiz
	cout << "After sorting: " << endl;
	printArray(array, size);

	return 0;
}
