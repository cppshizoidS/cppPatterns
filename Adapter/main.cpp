#include<iostream> //object realisation
using namespace std;

class Scales{
public:
    virtual float* getWeight() = 0;
    virtual ~Scales() {}
};

class RussianScales: public Scales{
private:
    float* currentWeight;
public:
    RussianScales(float *cw) :currentWeight(cw){}
    float* getWeight() override{
        return currentWeight;
    }
    ~RussianScales() override{
        delete currentWeight;
    }
};

class BritishScales{
private:
    float* currentWeight;
public:
    BritishScales(float* cw) :currentWeight(cw) {}
    ~BritishScales(){ delete currentWeight; }
    float* getWeight(){
        return currentWeight;
    }
};

class AdapterForBritishScales: public Scales{
private:
    BritishScales* britishScales;
    float* cw;
public:
    AdapterForBritishScales(BritishScales* bs) :britishScales(bs), cw(0){

    }
    ~AdapterForBritishScales(){
        delete britishScales;
        delete cw;
    }
    float* getWeight() override{
        cw = britishScales->getWeight();
        *cw = *cw * 0.453;
        return cw;
    }
};

int main(){
    float kg = 55.0; //килограммы
    float lb = 55.0; //фунты

    Scales* rScales = new RussianScales(&kg);
    Scales* bScales = new AdapterForBritishScales(new BritishScales(&lb));

    cout<< *rScales->getWeight() << endl;
    cout<< *bScales->getWeight() << endl;
}