#include <iostream>
#include "Pasare.hpp"
using namespace std;

class Gaina: public Pasare {
    private:
        static int numberOfInstances;
        Gaina();

    void sunet() {
        cout << "*gaina noise*\n";
    }

    void zboara() {
        cout << "I can fly les than 10 meters\n";
    }

    Gaina* create() {
        if (numberOfInstances < 30) {
            numberOfInstances++;
            return new Gaina();
        } else {
            return nullptr;
        }
    }

    ~Gaina() {
        decrement();
    }

    void decrement() {
        numberOfInstances--;
    }
};
