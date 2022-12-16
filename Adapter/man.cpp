//
// Created by alexa on 16.12.2022.
//Class realisation
#include <iostream>

using namespace std;

class Scales{
public:
    virtual float* getWeight() = 0;
    virtual void adjust() = 0;
    virtual ~Scales() {}
};

class RussianScales : public Scales {
private:
    float* currentWeight;
public:
    RussianScales(float* cw) : currentWeight(cw) {}
    ~RussianScales() override{
        delete currentWeight;
    }
    float* getWeight() override{
        return currentWeight;
    }
    void adjust() override{
        cout<<"Regulation russian weights" << endl;
    }
};

class BritishScales: public Scales{
private:
    float* currentWeight;
public:
    BritishScales(float* cw) :  currentWeight(cw){}
    ~BritishScales(){
        delete currentWeight;
    }
    float* getWeight(){
        return currentWeight;
    }
protected:
    void adjust(){
        cout<<"Regulation british weights" << endl;
    }
};

class AdapterForBritishScales : public Scales, private BritishScales{
private:
    float* cw;
public:
    AdapterForBritishScales(float* cw) : BritishScales(cw){}
    ~AdapterForBritishScales(){
        delete cw;
    }

    float* getWeight() override{
        cw = BritishScales::getWeight();
        *cw = *cw * 0.453;
        return cw;
    }
    void adjust() override{
        BritishScales::adjust();
        cout<<"in method  regulation adjust() adapter" << endl;
    }
};

int main(){
    ::setlocale(LC_ALL, "RUS");

    float kg = 55.0;
    float lb = 55.0;

    Scales* rScales = new RussianScales(&kg);
    Scales* bScales = new AdapterForBritishScales(&lb);

    cout<< *rScales->getWeight()<<endl;
    cout<< *bScales->getWeight()<<endl;

    rScales -> adjust();
    bScales -> adjust();
}
