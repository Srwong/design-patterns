#include <iostream>
#include <string>

using namespace std;

/*
TO COMPILE THIS PROGRAM YOU MUST AT LEAST USE C++ 11

command: g++ -std=c++11 prototype.cpp -o ANY

*/

class Government{
private:
    Government(){
        this->name = "Y-2023";
    }
    static Government * gov;
    string name;
public:
    string getGovernmentName() { return this->gov->name; }
    static Government * getInstance(){
        if(gov == nullptr) gov = new Government();
        return gov;
    }
    ~Government(){ delete this->gov; }
};

Government* Government:: gov = nullptr;

class State{
public:
    Government * government;
    string name;
    int habitants;
    int cities;

    State(string name, int hab, int cit){
        this->government = Government::getInstance();
        this->name = name;
        this->habitants = hab;
        this->cities = cit;
    }
};

int main(){

    State * aguascalientes = new State("Aguascalientes", 500000, 10);
    State * cdmx = new State("CDMX", 3000000, 40);
    State * yucatan = new State("Yucatan", 750000, 20);

    cout<<"Aguascalientes goverment: "<<aguascalientes->government->getGovernmentName()<<" pointer: "<<aguascalientes->government<<endl;
    cout<<"CDMX goverment: "<<cdmx->government->getGovernmentName()<<" pointer: "<<cdmx->government<<endl;
    cout<<"Yucatan goverment: "<<yucatan->government->getGovernmentName()<<" pointer: "<<yucatan->government<<endl;

    delete aguascalientes;
    delete cdmx;
    delete yucatan;
    return 0;
}

