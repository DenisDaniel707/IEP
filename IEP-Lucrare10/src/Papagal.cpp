#include <iostream>
#include "Pasare.hpp"
using namespace std;

class Papagal: public Pasare {
	private:
	    const list<string>& words;
	public:
		Papagal(const list<string>& words);

	void sunet() {
	    for (auto const& word : words) {
	        cout << word << ' ';
	    }
	    cout << '\n';
	}

	void fly() {
	    cout << "I can fly 50 meters! \n";
	}
};
