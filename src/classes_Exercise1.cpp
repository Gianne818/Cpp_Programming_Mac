#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class OneDShapes {
    protected:
        int m_numSides;
    public:
        OneDShapes (int numSides){
            m_numSides = numSides;
            cout << "Number of sides: " << m_numSides << endl;
        }
        virtual float calcArea() = 0;
        virtual float calcPerim() = 0;
};

class Circle: public OneDShapes {
    private:
        float radius;

    public:
        Circle (float rad) : OneDShapes(1){
            radius = rad;
        }
        float calcArea(){
            return M_PI * (radius*radius);
        }

        float calcPerim(){
            return 2 * M_PI * radius;
        }
};

class Rectangle: public OneDShapes {
    private:
        float m_length, m_width;
    public:
        Rectangle(float length, float width) : OneDShapes(4), m_length(length), m_width(width){}

        float calcArea(){
            return (2*m_length) + (2*m_width);
        }

        float calcPerim(){
            return m_length+m_width;
        }
};



int main (){
    Rectangle r1(4, 5);
    Circle c1(5);

    cout << "Rectangle:\n";
    cout << "Area: " << r1.calcArea() << endl;
    cout << "Perimeter: " << r1.calcPerim() << endl << endl;
    
    cout << "Circle:\n";
    cout << "Area: " << c1.calcArea() << endl;
    cout << "Circumference: " << c1.calcPerim() << endl;
}