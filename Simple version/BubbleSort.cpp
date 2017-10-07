/**
 * BubbleSort.cpp
 * 
 * Pufakchali tartiblash algoritmi
 *
 * Eng yomon xolat uchun algoritm murakkabligi: O(n^2)
 * Eng yaxshi uchun algoritm murakkabligi: O(n^2)
 *
 * Bu algoritmda elementlar yonma-yon turgan boshqa elementlar bilan 
 * taqqoslanadi va lozim topilsa o'rinlari almashtiriladi. Xuddi shu tarzda
 * N - 1 martagacha davom etiladi. Agar almashtirish amalga oshirilishi 
 * lozim bo'lgan elementlar qolmasa demak massiv to'la tartiblangan bo'ladi
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

// Pufakchali tartiblashni amalga oshiradigan protsedura
void bubbleSort(int array[], int size) {
	// Hali tartiblanmagan elementlar soni. Dastlab barcha elementlarni
	// tartiblanmagan deb hisoblaymiz
	int notSortedItemsCount = size;

	// Massiv elementlaridan birini joyi almashganligini ko'rsatuvchi flag
	bool swapped = true;

	// Agarda birorta element o'z joyini o'zgartirgan bo'lsa demak 
	// massiv hali to'la tartiblanmagan 
	while (swapped) {
		// Sikl boshida hech qaysi element o'rni almashmadi deb hisoblaymiz
		swapped = false;

		for (int i = 1; i < notSortedItemsCount; i++) {
			// Massivni saralanmagan elementlarini o'zidan oldingi turgan 
			// element bilan taqqoslaymiz
			if (array[i] < array[i - 1]) {
				// Agar oldingi element kattaroq bo'lsa ikkala element 
				// o'rnini almashtiramiz
				swap(array[i], array[i-1]);

				// Almashtirish bajarilganligini belgilab qo'yamiz
				swapped = true;
			}
		}

		// Har bir sikldan keyin saralanmagan elementlarning eng kattasi
		// massiv oxiriga borib o'z o'rnini topadi. Shuni uchun saralalanmagan
		// oraliqni bittaga kichraytiramiz
		notSortedItemsCount--;
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
	bubbleSort(array, size);

	// Tartiblangan massivni ekranga chiqaramiz
	cout << "After sorting: " << endl;
	printArray(array, size);

	return 0;
}