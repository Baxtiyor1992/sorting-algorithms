/**
 * CocktailSort.cpp
 * 
 * Aralashtirish orqali tartiblash algoritmi
 *
 * Eng yomon xolat uchun algoritm murakkabligi: O(n^2)
 * Eng yaxshi uchun algoritm murakkabligi: O(n^2)
 *
 * Bu algoritm pufakchali tartiblash algoritmini xususiy xolatlaridan biri 
 * bo'lib tartiblash yo'nalishi ikki taraflama ekanligi bilan farq qiladi
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

// Aralashtirish orqali tartiblashni amalga oshiradigan protsedura
void cocktailSort(int array[], int size) {
	// Bu algoritmda massivni ikki chekkadan tartiblab kelamiz. Tartiblangan 
	// qismlardan yana qayta yurib o'tmaslik uchun massivni chap va o'ng 
	// chegaralarini aniqlab olamiz
	int left = 0;
	int right = size - 1;

	// Massivni sarab bo'lingan qismlari bir-birlari bilan tutashguncha 
	// saralashni davom etamiz
	while (left < right) {
		// Massivni o'ngga qarab saralaymiz. Bunda huddi pufakchali tartiblash 
		// kabi elementlar o'zlarini yonida turgan elementlar bilan taqqoslanib
		// lozim topilsa o'rinlari almashtiriladi
		for (int i = left; i < size; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
			}
		}
		// O'ng tomonga qarab saralaganimiz sabab massivning o'ng tomonida 
		// bizga kerakli element o'z o'rnini topadi. Shu sabab tartiblanadigan
		// sohani o'ng tomondan bittaga qisqartiramiz
		right--;

		// Massivni chapga qarab saralaymiz pufakchali tartiblash 
		// algoritmidagidek tartibda massivni chap tomonga qarab tartiblaymiz
		for (int i = right; i > left; i--) {
			if (array[i] < array[i - 1]) {
				swap(array[i], array[i - 1]);
			}
		}
		// Xuddi yuqorida aytilganidek massivning tartiblanadigan sohasini chap
		// tomondan bittaga qisqartiramiz
		left++;
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
	cocktailSort(array, size);

	// Tartiblangan massivni ekranga chiqaramiz
	cout << "After sorting: " << endl;
	printArray(array, size);

	return 0;
}