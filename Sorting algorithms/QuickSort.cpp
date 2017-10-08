/**
 * QuickSort.cpp
 * 
 * Tezkor tartiblash algoritmi
 *
 * Eng yomon xolat uchun algoritm murakkabligi: O(n^2)
 * Eng yaxshi uchun algoritm murakkabligi: O(n*log(n))
 *
 * Bu algoritm murakkab algoritmlardan biri bo'lib rekursiya asnossida ishlaydi.
 * Tezkor tartiblash algoritmida avvaliga asos element tanlanadi va undan katta
 * elementlar asosning o'ng tomoniga, undan kichik elementlar esa chap tomonga 
 * o'tkaziladi. Asos element sifatida massivning istalgan elementini olish 
 * mumkin. Yuqorida aytilgan almashtirishlar bajarilganidan keyin asos 
 * elementdan o'ng va chap tomondagi submassivlar uchun ushbu algoritm rekursiv
 * chaqirib yuboriladi
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

// Tezkor tartiblash protsedurasi
void quickSort(int array[], int start, int end) {
	// Rekursiv chaqiruvda doim rekursiyani tugagaini tekshiruvchi shart 
	// bo'lishi lozim. Bu holatda agar bizga berilgan massiv yoki submassiv
	// faqat bitta elementdan iborat bo'lsa yoki umuman bo'sh bo'lsa bu 
	// massiv saralangan bo'ladi. Ushbu holat uchun tekshiramiz
	if (end - start < 2) {
		return;
	}

	// Asos element sifatida istalgan tasodifiy sonni olish mumkin. Biz massivni
	// oxirgi elementini asos sifatida olamiz
	const int pivot = array[end];

	// Asos elementda kichik elementlar indeksi
	int lowerItems = start - 1;

	// Berilgan massiv bo'yicha yurib, asos elementdan kichik va teng
	// elementlarni massivning chap tomonidan joylashtirib kelamiz. Bunda sikl 
	// oxirgi elementni o'z ichiga olmaydi. Chunki oxirgi element asos elementni
	// o'zi joylashgan
	for (int i = start; i < end; i++) {
		if (array[i] <= pivot) {
			// Massiv boshiga elementni joylashtirishda kursorni surish
			lowerItems++;
			// Elementlarni almashtirish
			swap(array[lowerItems], array[i]);
		}
	}
	// Asosdan kichik va teng barcha elementlarni chap tomonga 
	// joylashtirganimizdan keyin ularni davomiga asos elementni o'zini ham 
	// joylashtiramiz
	lowerItems++;
	swap(array[lowerItems], array[end]);

	// Asos elementimiz ushbu massivda o'zini o'rnini topdi. Endi asos 
	// elementdan chap va o'ng tomonda turgan submassivlarni (asos elementni 
	// o'zini kiritmagan holda) ham rekursiv tartiblab yuboramiz

	// Chap tomonda turgan submassivni tartiblash
	quickSort(array, start, lowerItems - 1);

	// O'ng tomonda turgan submassivni tartiblash
	quickSort(array, lowerItems + 1, end);
}

int main() {
	// Testlash uchun massivni e'lon qilib olamiz
	int array[] = { 1, 3, 9, 6, 7, 8, 2, 4, 5 };

	// Massiv olgan xotiraga qarab massiv o'lchamini aniqlab olamiz
	int size = sizeof(array) / sizeof(int);

	// Tartiblashdan oldin ma'lumotlarni ekranga chiqaramiz
	cout << "Before sorting: " << endl;
	printArray(array, size);

	// Massivni tartiblaymiz. Bunda massiv o'lchami emas uning birinchi va
	// oxirgi elementlari indekslarini uzatiladi
	quickSort(array, 0, size - 1);

	// Tartiblangan massivni ekranga chiqaramiz
	cout << "After sorting: " << endl;
	printArray(array, size);

	return 0;
}