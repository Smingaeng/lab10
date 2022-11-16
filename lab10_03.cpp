#include <iostream>
using namespace std;

class Base {

public:
    Base() {}
    virtual ~Base() {}

};

class Derived : public Base { 
// Base 상속

public:
    Derived() {}
    virtual ~Derived() {}

};

int main() {
    Base* b = new Derived();
    Derived* d = dynamic_cast<Derived*>(b); //다운 캐스팅
    if (d == nullptr) {  // dynamic cast 실패
        cout << "Runtime Error\n";
    }
    else {
        cout << "Everything is OKAY";
    }
    delete b;
    getchar();
    return 0;

}