//Exemplu: copy assignment operator
//Lucrare5 cu codul din Lucrare4

#include <iostream>
using namespace std;

class elev {
    private:
		string* nume;
		int* id;
	public:
		elev();
		~elev();
        elev(const elev& e) {  //Item 12
            nume = new string;
            id = new int;

            nume = e.nume;
            id = e.id;
        }
        elev& operator=(const elev& rhs);
        elev& operator/=(const elev& rhs) {
            return *this;
        }
		void SetElev(const string nume, const int id);
		void GetElev();
};

//default constructor
elev::elev() {

	this->nume = new string;
	*(this->nume) = "Null";

	this-> id = new int;
	*(this->id) = 0;

	return;
}

//destructor
elev::~elev() {

	if(this->nume != NULL) {
		delete this->nume;
	}

	if(this->id != 0) {
		delete this->id;
	}

	return;
}

//definim operatorul copy assignment pentru a-i "pasa" atributele in mod corespunzator
elev& elev::operator=(const elev& rhs) {

	cout << "Operatorul = a fost apelat" << endl << endl;

    if(this == &rhs)     //Item 11
        return *this;

	(*this->nume) = (*rhs.nume);
	(*this->id) = (*rhs.id);

	return *this;
}

void elev::SetElev(const string nume, const int id) {

	*(this->nume) = nume;
	*(this->id) = id;

	return;
}

void elev::GetElev() {

	cout << *(this->nume) << ", id: " << *(this->id) << endl;

	return;
}

int main() {

	//Programul defineste doua obiecte, initializeaza doar pe unul, iar celalalt ii copiaza atributele prin operatorul definit de noi

	elev e1, e2;	//Item 4: Obiectele sunt initializate de constructorul default definit de noi (nume: NULL, id: 0)

	e1.SetElev("Marian", 62);

	e2 = e1;	//Am definit operatorul copy assignment deci nu mai avem eroare de compilare aici.

    e1 /= e2;   //Operatorul definit la Item 10

    e1 = e1;    //Self assignment from Item 11

    elev(e3);   //Item 12

	//ambele rezultate vor afisa acelasi lucru dar refera spre obiecte diferite.
	e1.GetElev();
	e2.GetElev();

	return 0;
}
