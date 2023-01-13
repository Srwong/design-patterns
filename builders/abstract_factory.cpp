#include <iostream>

using namespace std;

class Table{
public:
    virtual void describe() = 0;
};

class ModernTable: public Table{
public:
    void describe() { cout<<"I am a modern Table"<<endl; }
};

class ClassicTable: public Table{
public:
    void describe() { cout<<"I am a classic Table"<<endl; }
}; 

class Chair{
public:
    virtual void sit() = 0;
};

class ModernChair: public Chair{
public:
    void sit() { cout<<"sitting on a modern chair"<<endl; }
};

class ClassicChair: public Chair{
public:
    void sit() { cout<<"sitting on a classic chair"<<endl; }
};

class FactoryInterface{
public: 
    virtual Chair* createChair() = 0;
    virtual Table* createTable() = 0;
};

class ModernFactory: public FactoryInterface{
public:
    Chair* createChair() { return new ModernChair(); }
    Table* createTable() { return new ModernTable(); }
};

class ClassicFactory: public FactoryInterface{
public:
    Chair* createChair() { return new ClassicChair(); }
    Table* createTable() { return new ClassicTable(); }
};

class App{
public:
    App();
    App(string t) 
    {
        try{
            type = t; 
            if(type == "modern") factory = new ModernFactory();
            else if(type == "classic") factory = new ClassicFactory();
            else throw "Unknown factory type";
            
        } catch (const char* msg){
            cerr << msg << endl;
        }
    
    };
    FactoryInterface * factory;
private:
    string type;
};

int main(int argc, char **argv){

    try{
        if(argc < 2) throw "Give a factory name to use. \nExample: ./main classic";

    } catch( const char* msg){ cerr << msg << endl; }


    App * app = new App(argv[1]);
    Chair * c = app->factory->createChair();
    Table * t = app->factory->createTable();

    c->sit();
    t->describe();

    return 0;
}

