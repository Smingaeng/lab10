#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class DrawAPI {
public:
    virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI { 
//DrawAPI ���
public:
    void drawCircle(int radius, int x, int y) { 
        cout << "Drawing Circle[ color: red, radius: " << radius
            << ", x: " << x << ", " << y << "]" << endl;
    }
};

class GreenCircle : public DrawAPI { 
//DrawAPI ���
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
    //virtual -> �ڽ� Ŭ�������� Override
};


class Circle : public Shape { 
//Shape ���
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
    Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); //���� �Ҵ�
    Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle()); //���� �Ҵ�
    redCircle->draw();
    greenCircle->draw();

    return 0;
}