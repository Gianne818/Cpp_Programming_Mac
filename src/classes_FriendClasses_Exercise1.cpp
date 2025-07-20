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

class Rectangle; //forward declare Rectangle first, since we used it as a parameter in square

class Square: public OneDShapes{
private: 
    float m_side;

public:
//Implementation of this function must be done below Rectangle, so that it would know the functions under Rectangle.
    void makeSquareFromARectangle(Rectangle& r);

    Square(float Side) : OneDShapes(4), m_side(Side){}

    float calcArea(){
        return m_side * m_side;
    }

    float calcPerim(){
        return m_side * 4;
    }

    void displayShape(){
        cout << "I am a square!" << endl;
    }

    float test_side = m_side;
};

class Rectangle: public OneDShapes {
    private:
        float m_length, m_width;
    public:
        Rectangle(float length, float width) : OneDShapes(4), m_length(length), m_width(width){}

        float calcArea(){
            return m_length * m_width;
        }

        float calcPerim(){
            return (2*m_length) + (2*m_width);
        }

        //Square is a friend of Rectangle, so square member functions can have access to private and protected members of square.
        friend class Square;

        //Note that even if Rectangle has declared that Square is a friend, Square did not declare Rectangle as friend.
        //Rectangle does not have access to private or protected members of Square.
};

void Square::makeSquareFromARectangle(Rectangle& r){
        m_side = (r.m_length+r.m_width)/2;
        r.m_length = m_side;
        r.m_width = m_side;
        cout << "\nSquare from Rectangle: " << endl;
        cout << "Area: " << r.calcArea() << endl; //because square is a friend, we can access the otherwise private members of Rectangle
        cout << "Perimeter: " << r.calcPerim() << endl;
    }

int main (){
    Rectangle r1(4, 5);
    Circle c1(5);

    cout << "Rectangle:\n";
    cout << "Area: " << r1.calcArea() << endl;
    cout << "Perimeter: " << r1.calcPerim() << endl << endl;
    
    cout << "Circle:\n";
    cout << "Area: " << c1.calcArea() << endl;
    cout << "Perimeter: " << c1.calcPerim() << endl << endl;

    Square s1(5);
    cout << "Square:\n";
    cout << "Area: " << s1.calcArea() << endl;
    cout << "Circumference: " << s1.calcPerim() << endl;

    s1.makeSquareFromARectangle(r1);

    OneDShapes *o1 = new Square(5);
    cout << "\n\nPointer to base class shape: " << /*o1->displayShape();*/ "error. o1 is of type OneDShapes*, not Square";
    //note that since o1 is a OneDShapes pointer, it wont be able to access members exclusive to derived classes like square.
    //it can only use those defined in class OneDShapes.
    cout << "\nSide length: " << /*o1.m_side;*/ "error. o1 is of type OneDShapes*, not Square."; 

    //as a work around, we can do something like
    OneDShapes* o2;
    Square s2(5);
    cout << "\n\nWork Around:\n";
    cout << "Shape: ";
    s2.displayShape();

    cout << "Side length: " << s2.test_side << endl;


}