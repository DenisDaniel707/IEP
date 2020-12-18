#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <math.h>
using namespace std;

class Punct {
    private:
        float x, y;
    public:
        Punct(float x, float y);
        float getX() {return x;};
        float getY() {return y;};
};

class Figura {
    private:
        string figura;
	public:
        vector<Punct>& puncte;
        string getFigura() {cout << figura << endl;}

        Figura(vector<Punct>& puncte);
        virtual float perimetru() = 0;
        template<typename T>
        float distance(T& punct1, T& punct2) {

            float x1 = 0;
            float x2 = 0;
            float y1 = 0;
            float y2 = 0;
            float pow1 = 0;
            float pow2 = 0;
            float distance = 0;

            x1 = punct1.getX();
            x2 = punct2.getX();
            y1 = punct1.getY();
            y2 = punct2.getY();

            pow1 = (x1 - x2) * (x1 - x2);
            pow2 = (y1 - y2) * (y1 - y2);

            distance = sqrt(pow1 + pow2);

            return distance;
        };
};

class Triunghi: Figura {
    public:
        Triunghi(std::vector<Punct>& puncte): Figura(puncte) {};

        float perimetru(void) {
            Punct& punct1 = puncte[0];
            Punct& punct2 = puncte[1];
            Punct& punct3 = puncte[2];
            return distance(punct1, punct2) + distance(punct2, punct3) + distance(punct3, punct1);
        };
};

class Patrulater: Figura{
    public:
        float perimetru() {
            Punct& punct1 = puncte[0];
            Punct& punct2 = puncte[1];
            Punct& punct3 = puncte[2];
            Punct& punct4 = puncte[3];

            return distance(punct1, punct2) + distance(punct2, punct3) + distance(punct3, punct4) + distance(punct4, punct1);
        };
};

class Pentagon: Figura{
    public:
        float perimetru() {
            Punct& punct1 = puncte[0];
            Punct& punct2 = puncte[1];
            Punct& punct3 = puncte[2];
            Punct& punct4 = puncte[3];
            Punct& punct5 = puncte[4];

            return  distance(punct1, punct2) + distance(punct2, punct3) + distance(punct3, punct4) + distance(punct4, punct5) + distance(punct5, punct1);
        }
};

int main() {

    //Am implementat doar clasele si functia pentru calcularea perimetrului

	return 0;
}
