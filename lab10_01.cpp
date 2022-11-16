#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class RoundedRectangle : public Shape {
public:
    void draw() override {
        cout << "Inside RoundedRectangle::draw() method." << endl;
    }
};

class RoundedSquare : public Shape {
public:
    void draw() override {
        cout << "Inside RoundedSquare::draw() method." << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Inside Rectangle::draw() method." << endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        cout << "Inside Square::draw() method." << endl;
    }
};

class AbstractFactory {
private:
    Shape* shape = NULL;
public:
    virtual Shape* getShape(string shapeType) = 0;
};

class ShapeFactory : public AbstractFactory {
public:
    Shape* getShape(string shapeType) override {
        if (0 == _stricmp(const_cast<char*>(shapeType.c_str()), "RECTANGLE")) {
            return new Rectangle();
        }
        else if (0 == _stricmp(const_cast<char*>(shapeType.c_str()), "SQUARE")) {
            return new Square();
        }
        return NULL;
    }
};

class RoundedShapeFactory : public AbstractFactory {
public:
    Shape* getShape(string shapeType) override {
        if (0 == _stricmp(const_cast<char*>(shapeType.c_str()), "RECTANGLE")) {
            return new RoundedRectangle();
        }
        else if (0 == _stricmp(const_cast<char*>(shapeType.c_str()), "SQUARE")) {
            return new RoundedSquare();
        }
        return NULL;
    }
};

class FactoryProducer {
public:
    static AbstractFactory* getFactory(bool rounded) {
        if (rounded) {
            return new RoundedShapeFactory();
        }
        else {
            return new ShapeFactory();
        }
    }
};

int main(void) {
    FactoryProducer fp;

    AbstractFactory* shapeFactory = fp.getFactory(false);

    Shape* shape1 = (*shapeFactory).getShape("RECTANGLE");

    shape1->draw();

    Shape* shape2 = (*shapeFactory).getShape("SQUARE");

    shape2->draw();

    AbstractFactory* shapeFactory1 = fp.getFactory(true);

    Shape* shape3 = (*shapeFactory1).getShape("RECTANGLE");

    shape3->draw();

    Shape* shape4 = (*shapeFactory1).getShape("SQUARE");

    shape4->draw();

    return 0;
}