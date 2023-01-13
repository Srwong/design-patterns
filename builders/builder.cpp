#include <iostream>
#include <string>

using namespace std;

class Construction{
public:
    bool door;
    int windows;
    string roof;
    string garden;
    bool garage;
    virtual void describe() = 0;
};

class House: public Construction{
public:
    void describe() { cout<<"this house has: door "<<door<<", windows "<<windows<<", roof "<<roof<<", garden "<<garden<<", garage "<<garage<<endl; }

};

class Castle: public Construction{
public:
    string defenses;
    int cells;
    void describe() { cout<<"this castle has: door "<<door<<", windows "<<windows<<", roof "<<roof<<", garden "<<garden<<
        ", garage "<<garage<<", defenses "<<defenses<<", cells "<<cells<<endl; }

};

class Builder{
public:
    virtual void reset() = 0;
    virtual void buildDoor() = 0;
    virtual void buildWindows(int quantity) = 0;
    virtual void buildRoof(string form) = 0;
    virtual void buildGarden(string location) = 0;
    virtual void buildGarage() = 0;
};

class HouseBuilder: public Builder{
public:
    House * house;
    void reset() { house = new House(); }
    void buildDoor() { house->door = true; }
    void buildWindows(int quantity) { house->windows = quantity; }
    void buildRoof(string form) { house->roof = form; }
    void buildGarden(string location) { house->garden = location; }
    void buildGarage() { house->garage = true; }
    void describe() { house->describe(); }
};

class CastleBuilder: public Builder{
public:
    Castle * castle;
    void reset() { castle = new Castle(); }
    void buildDoor() { castle->door = true; }
    void buildWindows(int quantity) { castle->windows = quantity; }
    void buildRoof(string form) { castle->roof = form; }
    void buildGarden(string location) { castle->garden = location; }
    void buildGarage() { castle->garage = true; }
    void buildDefenses(string def) { castle->defenses = def; }
    void buildCells(int amount) { castle->cells = amount; }
    void describe() { castle->describe(); }
};

class Director{
public:
    CastleBuilder * cb;
    HouseBuilder * hb;

    Director() {
        cb = new CastleBuilder();
        hb = new HouseBuilder();
    }

    House * buildSimpleHouse(){
        hb->reset();
        hb->buildDoor();
        hb->buildWindows(4);
        hb->buildRoof("flat form");
        return hb->house;
    }

    House * buildLuxuryHouse(){
        hb->reset();
        hb->buildDoor();
        hb->buildWindows(20);
        hb->buildRoof("triangle form");
        hb->buildGarage();
        hb->buildGarden("front and back");
        return hb->house;
    }


    Castle * buildCastle(){
        cb->reset();
        cb->buildDoor();
        cb->buildWindows(40);
        cb->buildRoof("None");
        cb->buildGarden("center only");
        cb->buildDefenses("aligators and archers");
        cb->buildCells(8);
        return cb->castle;
    }

};

int main(){

    CastleBuilder * cb = new CastleBuilder();
    HouseBuilder * hb = new HouseBuilder();
    Director * dir = new Director();

    cout<<"Build castle:"<<endl;
    cb->reset();
    cb->buildDoor();
    cb->buildWindows(8);
    cb->buildCells(3);
    cb->buildDefenses("aligators");
    cb->buildGarden("center");
    cb->describe();


    cout<<"Build house:"<<endl;
    hb->reset();
    hb->buildDoor();
    hb->buildWindows(20);
    hb->buildRoof("triangle form");
    hb->buildGarage();
    hb->buildGarden("frontal");
    hb->describe();

    cout<<"Builds with direcctor:"<<endl;
    House * house = dir->buildSimpleHouse();
    house->describe();

    house = dir->buildLuxuryHouse();
    house->describe();

    Castle * cas = dir->buildCastle();
    cas->describe();


    return 0;
}

