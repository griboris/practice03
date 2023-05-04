/*Практическая 3(Динамические связные списки)
*Реализовать динамический связный список, информационная часть которого представляет собой структуру Record,
разработанную при выполнении практической работы 1.
Создание списка (инициализацию значений элементов структуры) выполнить на основе данных массива Table,
последовательно сохранив все элементы массива в списке 2 раза.
*/
/*Однонаправ-ленный
*Целочисленноезначение
*Найти элементы списка, у которых совпадает целочисленное значение поля, со значением,
введенным с клавиатуры, и добавить новый элемент списка,
введя его с клавиатуры ПОСЛЕ каждого найденного элемента списка.*/

#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

struct Date {
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
};

struct Record {
	char name[20];
	char type;
	float cost;
	int mini;
	struct Date data;
};

struct node {
	Record info;
	node* next;
};

struct node* head;
int count = 0;

node* get(int k) {
	node* current;
	current = head;
	for (int i = 0;
			i < k && current != NULL;
				i++, current = current->next);
	return current;
}

void add(Record rec) {
	node* a = new node();
	a->info = rec;
	if (count == 0) {
		a->next = NULL;
	}
	else
	{
		a->next = head;
	}
	head = a;
	count++;
}

void insert(int index, Record rec) {
	if (not (index >= 0 and index <= countItem and countItem >= 0))
		return;
	if (index == 0) add(rec);
	else {
		node* a = new node();
		a->info = rec;
		node* current = head;
		for (int i = 0; i < index - 1; i++)
			current = current->next;
		a->next = current->next;
		current->next = a;
		count++;
	}
}

void deleteItem(int index) {
	if (index >= 0 and index < countItem and countItem>0) {
		node* current = head;
		node* old;
		if (index == 0) {
			old = head;
			head = current->next;
			delete old;
			count--;
		}
		else {
			for (int i = 0; i < index - 1)
				current = current->next;
					old = current->next->next;
					delete current->next;
					current->next = old;
					count--;
					break;
			}
	}
}

void editItem(int index, Record data) {
	if (index >= 0 and index < count and count > 0) {
		struct node* current = head;
		for (int i = 0; i < index; i++)
			current = current->next;
		current->info = data;
	}
	else {
		cout << endl << "Ошибка индекс не в диапазоне";
	}
}

void printDate(unsigned short int day, unsigned short int month, unsigned short int year) {
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
}

void MyCentr(const char* s, int wLine) {
	int w = strlen(s);
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta); cout << " ";
}

void out(struct Record* l) {
	cout << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << "|" << endl;
	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Прайс-лист"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');

	cout << "|"; MyCentr("Наименование товара", 21);
	cout << "|"; MyCentr("Тип товара", 12);
	cout << "|"; MyCentr("Цена за 1 шт (грн)", 20);
	cout << "|"; MyCentr("Минимальное количество в партии", 33);
	cout << "|"; MyCentr("Дата", 10);
	cout << "|" << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << right; cout << "|" << endl;
	cout.fill(' ');

	for (int i = 0; i < 3; i++){
		cout << left;
		cout << '|'; cout.width(21); cout << l[i].name;
		cout << '|'; cout.width(12); cout << l[i].type;
		cout.precision(2);  cout << '|'; cout.width(20); cout << l[i].cost;
		cout << '|'; cout.width(33); cout << l[i].mini;
		cout << '|'; printDate(l[i].data.day, l[i].data.month, l[i].data.year);
		cout << "|" << endl;
		cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
		cout.fill(' ');
	}

	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Примечание: К – канцтовары, О - оргтехника"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');
}

void printMyList() {
	struct node* current = head;
	cout << endl;
	while (current) {
		cout << " " << current->info.mini;
		current = current->next;
	}
}

void DrawWithList() {
	cout << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << "|" << endl;
	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Прайс-лист"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');

	cout << "|"; MyCentr("Наименование товара", 21);
	cout << "|"; MyCentr("Тип товара", 12);
	cout << "|"; MyCentr("Цена за 1 шт (грн)", 20);
	cout << "|"; MyCentr("Минимальное количество в партии", 33);
	cout << "|"; MyCentr("Дата", 10);
	cout << "|" << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << right; cout << "|" << endl;
	cout.fill(' ');

	struct node* current = head;
	while (current) {
		cout << left;
		cout << '|'; cout.width(21); cout << current->info.name;
		cout << '|'; cout.width(12); cout << current->info.type;
		cout.precision(2);  cout << '|'; cout.width(20); cout << current->info.cost;
		cout << '|'; cout.width(33); cout << current->info.mini;
		cout << '|'; printDate(current->info.data.day, current->info.data.month, current->info.data.year);
		cout << "|" << endl;
		cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
		cout.fill(' ');
		current = current->next;
	}
	
	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Примечание: К – канцтовары, О - оргтехника"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[3];

	records[0] = { "Папка", 'К', 4.75000, 4, {03,07,2022} };
	records[1] = { "Бумага", 'К', 13.9, 10000, {03,04,2021} };
	records[2] = { "Калькулятор", 'О', 411.000, 1, {04,03,2022} };

	cout << "Практика 3 Динамический список" <<endl;
	add(records[0]);
	add(records[1]);
	add(records[2]);
	DrawWithList();
	struct Record newRecord = { "Русаков", 'A', 712.50, 1984, {01,02,2023} };
	insert(1, newRecord);
	DrawWithList();
	deleteItem(3);
	DrawWithList();
	struct Record editRecord = { "Мерсов", 'A', 2000.75, 1962, {01,02,2023}};
	editItem(1, editRecord);
	DrawWithList();

}
