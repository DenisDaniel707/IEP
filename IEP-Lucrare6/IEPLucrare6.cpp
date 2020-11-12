#include <iostream>
using namespace std;

class investment {
    private:
        int invested_money;
    public:
        investment();
        ~investment();

    investment(int sum) {
        invested_money = sum;
    }
};

investment* createInvestment();

void f() {
    
    std::auto_ptr<investment> plnv(createInvestment());
    //
    //
    //
    
}

int main() {

    f();

    return 0;
}
