/**
 * List.cpp
 * 
 * Ro'yhat ma'lumot strukturasi
 *
 * Ma'lumotni o'qish: O(n)
 * Ma'lumotni yozish: O(1)
 *
 * Bu ma'lumot strukturasi istalgan indeksga ma'lumotni yozish va o'chirish 
 * imkonini beradi. Kamchiligi kerakli indeksdagi elementni o'qish massivlarga
 * nisbatan sekin
 */

#include <iostream>
#include "Exceptions.cpp"

using namespace std;

// List elementi uchun struktura. Har bir list elementi o'ziga berilgan qiymat
// va o'zidan keladigan elementga ko'rsatkich saqlaydi
struct ListItem {
public:
	int data;
	ListItem* next;

	// List elementini initsializatsiya qilish uchun konstruktor
	ListItem(int data) {
		this->data = data;
	}
};

// List klasi
class List {
private:
	// Listni birinchi elementiga ko'rsatkich. Birinchi element orqali 
	// boshqalarini topib olish mumkin
	ListItem* firstItem;
	
	// List elementlari soni
	int listSize;

	// List elementiga murojaat bo'lganda so'ralgan indeksni tekshiruvchi 
	// funksiya
	void checkIndex(int index) {
		// Index manfiy son bo'lishi mumkin emas
		if (index < 0) {
			throw new IllegalArgumentException("Index must not be negative");
		}
		// Indeks list elementlari soni ga teng yoki katta bo'lishi mumkin emas
		if (index >= listSize) {
			throw new IndexOutOfRangeException(index);
		}
	}

public:
	List() {
		// Dastlab listda elementlar yo'q deb e'lon qilamiz
		firstItem = NULL;
		listSize = 0;
	}

	// Listdan indeks bo'yicha elementning qiymatini qaytaradigan metod
	int get(int index) {
		// Berilgan indeksni tekshiramiz
		checkIndex(index);

		// Elementlarning o'zidan keyingi elementga ko'rsatkichidan foydalanib 
		// kerakli elementni topamiz
		ListItem *item = firstItem;

		int i = 0;
		while (i < index) {
			item = item->next;
			i++;
		}

		// Element o'zida saqlab turgan qiymatni qaytaramiz
		return item->data;
	}

	// Listga ma'lumot qo'shadigan metod
	void add(int data) {
		// Agar dastlabki element bo'lmasa uni yaratamiz
		if (firstItem == NULL) {
			firstItem = new ListItem(data);
			firstItem->next = NULL;
		} else {
			// Agar dastlabki element bor bo'lsa listni oxirgi elementini 
			// topamiz
			ListItem* lastItem = firstItem;
			while (lastItem->next != NULL) {
				lastItem = lastItem->next;
			}

			// Yangi elementni yasab uni oxirgi elementga 'ulab' qo'yamiz
			ListItem* newItem = new ListItem(data);
			newItem->next = NULL;
			lastItem->next = newItem;
		}
		// Yangi element qo'shilgani uchun list elementlari sonini bittaga 
		// oshirib qo'yamiz
		listSize++;
	}

	// Listga indeks bo'yicha ma'lumot qo'shadigan funksiya
	void add(int index, int data) {
		// Indeksni tekshiramiz
		checkIndex(index);

		if (index == 0) {
			// Agar list boshiga kiritilayotgan bo'lsa yangi element yasaymiz.
			// Agar bizda dastlabki element mavjud bo'lmasa yangi yasalgan 
			// elementni dastlabki element sifatida olamiz
			if (firstItem == NULL) {
				firstItem = new ListItem(data);
				firstItem->next = NULL;
			} else {
				// Aks holda yangi elementni yasab dastlabki elementni undan
				// keyingi qilib ko'rsatamiz va yangi elementni dastlabki deb 
				// olamiz
				ListItem* newItem = new ListItem(data);
				newItem->next = firstItem;
				firstItem = newItem;
			}
		} else {
			// Agar listda davomiga kiritilayotgan bo'lsa indeks bo'yicha bitta 
			// oldinda turgan elementni topib olamiz
			int i = 1;
			ListItem* insertAfterItem = firstItem;
			while (i < index) {
				insertAfterItem = insertAfterItem->next;
				i++;
			}

			// Yangi elemen yasab uni oldinda turgan elementga ulab qo'yamiz
			ListItem* newItem = new ListItem(data);
			newItem->next = insertAfterItem->next;
			insertAfterItem->next = newItem;
		}
		listSize++;
	}

	// Ko'rsatilgan indeks bo'yicha list elementini o'chirib tashlaydigan metod
	void remove(int index) {
		// Indeksni tekshiramiz
		checkIndex(index);

		// Agar listni birinchi elementi o'chirilayotgan bo'lsa undan keyingi 
		// elementni dastlabki element sifatida olamiz
		if (index == 0) {
			ListItem* itemToRemove = firstItem;
			firstItem = itemToRemove->next;
			delete itemToRemove;
		} else {		
			// Agar boshqa element o'chirilayotgan bo'lsa bitta oldingi elemetni 
			// topib olamiz
			int i = 1;
			ListItem* removeAfterItem = firstItem;
			while (i < index) {
				removeAfterItem = removeAfterItem->next;
				i++;
			}
			// Undan o'chirilayotgan elementdan keyingi elementni oldingi 
			// elementga ulab, elementni o'chiramiz
			ListItem* itemToRemove = removeAfterItem->next;
			removeAfterItem->next = itemToRemove->next;
			delete itemToRemove;
		}

		// Element o'chirilgani sabab list elementlari sonini bittaga 
		// kamaytiramiz
		listSize--;
	}

	// Barcha list elementlarini o'chirib yuboradigan metod
	void clear() {
		// List elementlari sonini nolga tenglaymiz
		listSize = 0;

		// List elementlarini o'chiramiz
		while (firstItem != NULL) {
			ListItem* itemToRemove = firstItem;
			firstItem = firstItem->next;

			delete itemToRemove;
		}
	}

	// List o'lchamini qaytaradigan metod
	int size() {
		return listSize;
	}

	// List bo'sh yoki bo'sh emasligini qaytaradigan metod
	bool isEmpty() {
		return listSize == 0;
	}

	// Listni barcha elementlarini ekranga chiqaradigan metod
	void printAll() {
		cout << "Printing list contents:" << endl;
		if (isEmpty()) {
			cout << "List is empty";
		}

		ListItem* item = firstItem;
		while (item != NULL) {
			cout << item->data << ' ';
			item = item->next;
		}
		cout << endl;
	}
};

int main() {
	// Listni yaratamiz va uni bo'shiligini tekshiramiz
	List myList;
	myList.printAll();

	// Listga elementlar qo'shib tekshiramiz
	myList.add(1);
	myList.add(3);
	myList.add(3);
	myList.add(5);
	myList.printAll();

	// List elementlari orasiga elementlarni qo'yib tekshiramiz
	myList.add(1, 2);
	myList.add(4, 4);
	myList.printAll();

	// Elementini o'chirib tekshiramiz
	myList.remove(2);
	myList.printAll();

	// Listni barcha elementlarini o'chirib tekshirib ko'ramiz
	myList.clear();
	myList.printAll();

	return 0;
}