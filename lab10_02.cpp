#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class DrawAPI {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI { 
//DrawAPI 상속
public:
    void drawCircle(int radius, int x, int y) { 
        cout << "Drawing Circle[ color: red, radius: " << radius
            << ", x: " << x << ", " << y << "]" << endl;
    }
};

class GreenCircle : public DrawAPI { 
//DrawAPI 상속
public:
    void drawCircle(int radius, int x, int y) { 
        cout << "Drawing Circle[ color: green, radius: " << radius
            << ", x: " << x << ", " << y << "]" << endl;
    }
};

class Shape {
protected:
    DrawAPI* drawAPI = NULL; 
    Shape() {}
    Shape(DrawAPI* drawAPI) {
        this->drawAPI = drawAPI;
    }

public:
    virtual void draw() = 0;
    //virtual -> 자식 클래스에서 Override
};


class Circle : public Shape { 
//Shape 상속
private:
    int x, y, radius;

public:
    Circle(int x, int y, int radius, DrawAPI* drawAPI) { 
        this->drawAPI = drawAPI;
        this->x = x;
        this->y = y;
        this->radius = radius;
    }

    void draw() { //Override
        drawAPI->drawCircle(radius, x, y);
    }
};


int main(void) {
    Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); //동적 할당
    Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle()); //동적 할당
    redCircle->draw();
    greenCircle->draw();

    return 0;
}