/**
 * CombSort.cpp
 * 
 * Taroqli tartiblsh algoritmi
 *
 * Eng yomon xolat uchun algoritm murakkabligi: O(n^2)
 * Eng yaxshi uchun algoritm murakkabligi: O(n)
 *
 * Bu algoritm pufakchali tartiblash algoritmini xususiy holatlaridan biri 
 * hisoblanadi. Bunda kiruvchi massiv uzunligida oraliq olib huddi pufakchali 
 * tartiblash kabi ikkala element taqqoslanadi va agar lozim topilsa o'rinlari
 * almashtirladi. Har bir sikl davomida oraliq maxsus koeffitsientga 
 * kamaytirilib boriladi
 */

#include <iostream>
#include <cmath>

using namespace std;

// Massiv elementlarini ekranga chiqadigan protsedura
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << ' ';
	}
	cout << endl;
}

// Taroqli tartiblash protsedurasi
void combSort(int array[], int size) {
	// Taroqli tartiblash uchun kamayish faktorini hisoblab olamiz. Ushbu faktor
	// qiymati qat'iy konstanta bo'lib 1 / (1 - e^(-phi)) formula orqali 
	// topiladi. Bu yerda e - eksponenta, phi - 'Oltin kesim' konstantasi O'z
	// navbatida Oltin kesim konstantasi (1 + sqrt(5)) / 2 formula orqali 
	// aniqlanadigan irratsional son

	// Oltin kesim konstantasi. Taqribiy qiymati ~ 1.61803
	const double phi = (1 + sqrt(5)) / 2;

	// Kamayish faktori. Taqribiy qiymati ~ 1.24733 
	const double reduceFactor = 1 / (1 - exp(-phi));

	// Taroq kengligi. Har bir yangi sikl davomida kamayish faktoriga bo'yicha 
	// kamayib boradi
	int gap = size - 1;

	// Elementlar orasida o'rin almashish bo'lganligini ko'rsatuvchi flag.
	// Agar bu o'zgaruvchini qiymati rost bo'lsa demak massiv hali to'la
	// tartiblanmagan bo'ladi
	bool swapped = true;

	// Taroq kengligi 1 ga teng bo'lib, shunda elementlar o'rni almashmagan 
	// bo'lsa demak massiv tartiblangan bo'ladi. Ungacha tartiblashni davom 
	// ettiramiz
	while (gap > 1 || swapped) {
		// Sikl boshida elementlar o'rni almashtirilmagan deb olamiz
		swapped = false;

		// Agar taroq kengligi 1 dan katta bo'lsa uni o'lchamini kamaytiramiz
		if (gap > 1) {
			// Taroq kengligini kamayish faktoriga bo'lib yuboriladi. Chiqqan
			// natijani pastga qarab yaxlitlaymiz
			gap = (int) (gap / reduceFactor);
		}

		// Ushbu "taroq" ni massiv boshiga qo'yib oxirigacha yurib chiqamiz
		for (int i = 0; i + gap < size; i++) {
			// Taroqni ikki uchidagi elementlarni taqqoslaymiz va lozim topilsa
			// ularni o'rinlarini almashtiramiz
			if (array[i] > array[i + gap]) {
				swap(array[i], array[i + gap]);
				// Elementlar o'rni almashsa, buni belgilab qo'yamiz
				swapped = true;
			}
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
	combSort(array, size);

	// Tartiblangan massivni ekranga chiqaramiz
	cout << "After sorting: " << endl;
	printArray(array, size);

	return 0;
}
