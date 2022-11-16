#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;

class CEO {
    virtual void print()
    {
        std::cout << "I'm CEO" << endl;
    }
};

class CPO {
    virtual void print()
    {
        std::cout << "I'm CPO" << endl;
    }
};

class Manager : public CEO, public CPO {
    virtual void print()
    {
        std::cout << "I'm Manager" << endl;
    }
};

class Staff : public Manager {
    virtual void print()
    {
        std::cout << "I'm Staff" << endl;
    }
};

int main(void) {
    CPO* cpo = new Manager;  // 4-1

    Staff* staff = dynamic_cast<Staff*>(cpo); // 4-2

    Manager* manager = dynamic_cast<Manager*>(cpo); // 4-3

    CEO* ceo = dynamic_cast<CEO*>(cpo); //4-4

    assert(typeid(cpo) == typeid(Staff*)); //4-5

    delete cpo; //4-6

    return 0;

}