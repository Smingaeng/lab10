#include <iostream>
using namespace std;

class Base {

public:
    Base() {}
    virtual ~Base() {}

};

class Derived : public Base { 
// Base ���

public:
    Derived() {}
    virtual ~Derived() {}

};

int main() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b); //�ٿ� ĳ����
    if (d == nullptr) {  // dynamic cast ����
        cout << "Runtime Error\n";
    }
    else {
        cout << "Everything is OKAY";
    }
    delete b;
    getchar();
    return 0;

}