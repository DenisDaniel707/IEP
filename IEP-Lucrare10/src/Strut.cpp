#include <iostream>
#include "Pasare.hpp"
#include "Gaina.cpp"
using namespace std;

class Strut: public Pasare {
	private:
	    int nrOfGaini;
	    Strut(Strut const&);
	    void operator=(Strut const&);
	public:
		void decrement();

	Strut(): nrOfGaini(0) {}

	Strut * instance = nullptr;

	Strut * getInstance() {
	    if (!instance)
	        instance = new Strut;
	    return instance;
	}

	void zboara() {
	    cout << "Pot zbura\n";
	}

	void sunet() {
	    cout << "Nu pot face zgomote\n";
	}

	Strut & operator+(const Gaina &other) {
	    getInstance() -> nrOfGaini++;
	    decrement();
	    return *getInstance();
	}

	int getGaini() {
	    return nrOfGaini;
	}
};
