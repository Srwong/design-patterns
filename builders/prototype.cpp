#include <iostream>
#include <string>

using namespace std;
/*
TO COMPILE THIS PROGRAM YOU MUST AT LEAST USE C++ 11

command: g++ -std=c++11 prototype.cpp -o ANY

*/

class ShapePrototype{
public:
    string color;
    int sidesNumber;
    virtual ShapePrototype * clone() const = 0;
    void setColor(string color) { this->color = color; }
    void setSides(int sides) { this->sidesNumber = sides; }

};

class Square: public ShapePrototype{
public: 
    int xAxis;
    int yAxis;
    Square(){}
    Square(Square const & original){
        this->color = original.color;
        this->sidesNumber = 4;
        xAxis = original.xAxis;
        yAxis = original.yAxis;
    }

    Square * clone() const override {
        return new Square(* this);
    }

    void print(){
        cout<<"xAxis: "<<xAxis<<"\nyAxis: "<<yAxis<<"\nColor: "<<this->color<<"\nSides: "<<this->sidesNumber<<endl;
    }
};

class Circle: public ShapePrototype{
public: 
    double radius;
    Circle(){ 
        sidesNumber = 1;
     }
    Circle(Circle * original){
        this->color = original->color;
        this->sidesNumber = 1;
        this->radius = original->radius;
    }

    Circle * clone() const override{
        return new Circle(* this);
    }

    void print(){
        cout<<"radius: "<<radius<<"\n"<<this->color<<"\nSides: "<<this->sidesNumber<<endl;
    }
};

int main(){

    Square * square1 = new Square();
    square1->sidesNumber = 4;
    square1->xAxis = 10;
    square1->yAxis = 20;
    square1->color = "red";

    Square * square2 = square1->clone();
    Square * square3 = new Square(*square1);

    cout<<"Squares: "<<endl;
    square1->print();
    square2->print();
    square3->print();

    Circle * circle1 = new Circle();
    circle1->radius = 2.5;
    circle1->color = "blue";

    Circle * circle2 = circle1->clone();
    Circle * circle3 = new Circle(*circle1);

    cout<<"\nCircles: "<<endl;
    circle1->print();
    circle2->print();
    circle3->print();

    return 0;
}

