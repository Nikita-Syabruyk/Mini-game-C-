#include <iostream>
#include <ctime>
#define tab "\t" 
using namespace std;
void mas(int* arr, const int n) {
	for (int i = 0; i <= n; i++) {
		arr[i] = rand() % 2 + 1;
		cout <<"дверь "<<i<<"  ";
	}
	cout << endl;
}
int mons(int monstr) {
	monstr = rand() % 95 + 5;
	return monstr;
}
int orus(int oru) {
	oru = rand() % 70 + 10;
	return oru;
}
int dveri(int &a,int &monster,int &hero,int oru,int *arr,int k,int *aw,int const size) {
	cout << endl << "выберите дверь";
	cin >> a;
	if (aw[a] != 10) {
		if (arr[a] == 1) {
			monster += mons(monster);
			if (hero < monster) {
				cout << endl << "ТЫ ПРОИГРАЛ СИЛА МОНСТРА РАВНА" << monster;
				return false;
			}
			else
				cout << endl << "ТЫ ПОБЕДИЛ МОНСТРА ЕГО СИЛА РАВНА" << monster;
		}
		if (arr[a] == 2) {
			hero += orus(oru);
			cout << endl << "ВЫ НАШЛИ ОРУЖИЕ СИЛА ГЕРОЯ РАВНА " << hero;
		}
		if (k == 9) {
			return true;
		}
			aw[a] = 10;
	
		k++;
	}
	else {
		cout << endl << endl << "ВЫ ВЫБИРАЛИ ЭТУ ДВЕРЬ!!! ";
	}
		return dveri(a,monster,hero,oru,arr,k,aw,size);
}

int main() {
	int const size = 9;
	int* aw = new int[size];
	for (int i = 0; i < size; i++) {
		aw[i] = 0;
	}
	int k = 0;
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int hero = 25;
	cout << "СИЛА ГЕРОЯ РАВНА " << hero << endl << endl;
	int const n = 9;
	int* arr = new int[n];
	int monster = 1;
	int oru = 2;
	mas(arr, n);
	int a;
	cout << endl << "НУМЕРАЦИЯ ДВЕРЕЙ НАЧИНАЕТСЯ С 0 ДО 9";
	cout << endl;
	if (dveri(a, monster, hero, oru, arr, k, aw, size)) {
		cout << "ТЫ ПОБЕДИЛ ГЕРОЙ ПРОШЕЛ ВСЕ ДВЕРИ";
		return 0;
	}
	else {
		return 0;
	}
	delete[]arr;
	delete []aw;
}