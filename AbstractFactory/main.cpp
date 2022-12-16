//
// Created by alexa on 16.12.2022.
//
#include <iostream>

using namespace std;

class IEngine{
public:
    virtual void releaseEngine() = 0;
};

class JapaneseEngine: public IEngine{
public:
    void releaseEngine() override{
        cout<<"Japanese Engine" << endl;
    }
};

class RussianEngine: public IEngine{
public:
    void releaseEngine() override{
        cout<<"Russian Engine" << endl;
    }
};

class ICar{
public:
    virtual void releaseCar(IEngine* engine) = 0;
};

class JapaneseCar : public ICar{
public:
    void releaseCar(IEngine* engine) override{
        cout<<"Build Japanese car: ";
        engine->releaseEngine();
    }
};

class RussianCar : public ICar{
public:
    void releaseCar(IEngine* engine) override{
        cout<<"Build Russian car:";
        engine->releaseEngine();
    }
};

class IFactory{
public:
    virtual IEngine* createEngine() = 0;
    virtual ICar* createCar() = 0;
};

class JapaneseFactory : public IFactory{
public:
    IEngine* createEngine() override{
        return new JapaneseEngine();
    }
    ICar* createCar() override{
        return new JapaneseCar();
    }
};

class RussianFactory : public IFactory{
public:
    IEngine* createEngine() override{
        return new RussianEngine();
    }
    ICar* createCar() override{
        return new RussianCar();
    }
};

int main(){
    ::setlocale(LC_ALL,"Russian");

    IFactory* jFactory = new JapaneseFactory();

    IEngine* jEngine = jFactory->createEngine();
    ICar* jCar = jFactory->createCar();

    jCar->releaseCar(jEngine);


    IFactory* rFactory = new RussianFactory();

    IEngine* rEngine = rFactory->createEngine();
    ICar* rCar = rFactory->createCar();

    rCar->releaseCar(rEngine);
}
