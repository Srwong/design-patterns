#include <iostream>
#include <string>

using namespace std;

class Logistic {
public:
    virtual void generatePlan() = 0;
    virtual void addContent(string c) = 0;
};

class TruckLogistic: public Logistic{
private:
    string content;
public:
    void addContent(string c) { content = c; }
    void generatePlan() { cout<<"Will be send by land"<<endl; }
};

class SeaLogistic: public Logistic{
private:
    string content;
public:
    void addContent(string c) { content = c; }
    void generatePlan() { cout<<"Will be send by sea"<<endl; }
};

class Creator {
public:
    virtual Logistic* create() = 0;

    void generatePlan() { 
        cout<<"Starting delivery plan ..."<<endl; 
        Logistic* l = this->create();
        l->generatePlan();
        }

};

class TruckCreator : public Creator{
    Logistic* create() 
    { 
        cout<<"Creating a truck"<<endl;
        return new TruckLogistic(); 
    }
};

class BoatCreator: public Creator{
    Logistic* create() 
    {
        cout<<"Creating a boat"<<endl;
        return new SeaLogistic(); 
    }
};

int main(){

    Creator* truck = new TruckCreator();
    Creator* boat = new BoatCreator();

    // factory method
    truck->generatePlan();
    boat->generatePlan();

    //Directly use child
    truck->create()->generatePlan();

    return 0;
}

