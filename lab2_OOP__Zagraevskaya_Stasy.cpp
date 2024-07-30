#include <iostream>
#include <vector>
#include <list>
#include  <string>
#include  <algorithm>
using namespace std;
class Cosmetic
{
public:
	string name;
	int price;

	Cosmetic(string name_, int price_) {
		this->name = name_;
		this->price = price_;
	}

	friend ostream& operator<<(ostream& os, const Cosmetic& cos)
	{
		return os << cos.name << " " << cos.price;
	}

	bool operator < (const Cosmetic& cos)
	{
		if (this->price < cos.price) return true;
		return false;
	}
	bool operator != (const Cosmetic& cos)
	{
		if (this->price != cos.price) return true;
		return false;
	}

	bool operator > (const Cosmetic& cos)
	{
		if (this->price > cos.price) return true;
		return false;
	}
};

bool sort1(Cosmetic a, Cosmetic b) {
	return a > b;
}
bool sort2(Cosmetic a) {
	return a.price <= 1500;
}


int main() {
	
	//1.1
	list <int> list1 = { 2,5,6,8,5 };
	//1.2
	for (auto i : list1)cout << i << endl;
	//1.3
	list1.erase(++list1.begin(), --list1.end());// erase () используется для удаления одного элемента из вектора, она возвращает итератор и указывает на элемент, за которым следует последний удаленный элемент.
	list1.insert(++list1.begin(), 3, 4); // вставляет в строку подстроку
	//1.4
	cout << "Conteiner .1" << endl;
	for (auto iter = list1.begin();iter != list1.end();iter++) {
		cout << *iter << endl;
	}
	//1.5
	list <int> list2 = { 5,9,7,6,9 };
	//1.6
	list1.erase(next(list1.begin(), 3), list1.end());
	list1.insert(list1.end(), list2.begin(), list2.end());
	//1.7
	cout << "----------------test___________" << endl;
	for (auto i : list1)cout << i << endl;
	cout << "----------------test___________" << endl;
	for (auto i : list2)cout << i << endl;
	//2.1
	vector<Cosmetic> vector1 = { Cosmetic("tonalnic",1000),Cosmetic("bronser",1500),Cosmetic("pydra",2000),Cosmetic("rumyana",1700) };
	//2.2
	for (auto i : vector1) cout << i << endl;
	//2.3
	vector1.erase(++vector1.begin(), --vector1.end());
	vector1.insert(++vector1.begin(), 3, Cosmetic("bronser", 4444));
	//2.4
	cout << "Conteiner .1" << endl;
	for (auto iter = vector1.begin();iter != vector1.end();iter++) {
		cout << *iter << endl;
	}
	//2.5
	vector<Cosmetic> vector2 = { Cosmetic("tonalnic",777),Cosmetic("tonalnic",333),Cosmetic("tonalnic",888) };
	//2.6
	vector1.erase(next(vector1.begin(), 3), vector1.end());
	vector1.insert(vector1.end(), vector2.begin(), vector2.end());
	//2.7
	for (auto i : vector2) cout << i << endl;


	cout << "TEST" << endl;
	for (auto i : vector1) cout << i << endl;
	//3.1
	vector<Cosmetic> vectorT = { Cosmetic("tonalnic",1000),Cosmetic("bronser",1500),Cosmetic("pydra",2000),Cosmetic("rumyana",1700) };
	//3.2
	sort(vectorT.begin(), vectorT.end(), sort1);
	//3.3
	for (auto i : vectorT) cout << i << endl;
	//3.4
	auto perem1 = find_if(vectorT.begin(), vectorT.end(), sort2);
	cout << *perem1 << endl;
	//3.5
	vector<Cosmetic> vectorT1;
	copy_if(vectorT.begin(), vectorT.end(), back_inserter(vectorT1), sort2);
	//3.6
	for (auto i : vectorT1) cout << i << endl;
	//3.7
	sort(vectorT1.begin(), vectorT1.end(), sort1);
	//3.8-3.9
	vector<Cosmetic> vectorT2;
	vectorT2.insert(vectorT2.end(), vectorT1.begin(), vectorT1.end());
	vectorT2.insert(vectorT2.end(), vectorT.begin(), vectorT.end());
	//3.10-3.12
	cout << "count_if " << count_if(vectorT2.begin(), vectorT2.end(), sort2) << endl;
	int index = 0;
	for (auto i : vectorT2) {
		if (i.price == 99)index++;
	}
	if (index == 0)cout << "I dont Found" << endl;
	else cout << "I Found!" << endl;
	cout << "\n" << "TESt" << endl;
	for (auto i : vectorT2) cout << i << endl;

}
