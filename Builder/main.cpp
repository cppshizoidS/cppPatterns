//
// Created by alexa on 16.12.2022.
//
#include <iostream>
#include<string>

using namespace std;

class Phone{
    string Data;
public:
    Phone() {
        Data = "";
    }
    string aboutPhone(){
        return Data;
    }
    void appendData(string str) {
        Data += str;
    }
};

class IDeveloper{
public:
    virtual void createDisplay() = 0;
    virtual void createBox() = 0;
    virtual void systemInstall() = 0;

    virtual Phone* getPhone() = 0;
};

class AndroidDeveloper : public IDeveloper
{
    Phone* phone;
public:
    AndroidDeveloper() {
        phone = new Phone();
    }

    ~AndroidDeveloper(){
        delete phone;
    }

    void createDisplay() override{
        phone->appendData("Display Samsung is produced; ");
    }

    void createBox() override{
        phone->appendData("Box Samsung is produced; ");
    }
    void systemInstall() override{
        phone ->appendData("Android system is installed");
    }

    Phone* getPhone() override{
        return phone;
    }
};

class IPhoneDeveloper : public IDeveloper
{
    Phone* phone;
public:
    IPhoneDeveloper(){
        phone = new Phone();
    }
    ~IPhoneDeveloper(){
        delete phone;
    }

    void createDisplay() override{
        phone ->appendData("Display Apple is produced; ");
    }
    void createBox() override{
        phone ->appendData("Box Apple is produced;");
    }
    void systemInstall() override{
        phone ->appendData("iOS system is installed");
    }

    Phone* getPhone() override{
        return phone;
    }
};

class Director{
    IDeveloper* developer;
public:
    Director(IDeveloper* dev) : developer(dev){}

    void setDeveloper(IDeveloper* dev){
        developer = dev;
    }

    Phone* MountOnlyPhone(){
        developer->createBox();
        developer->createDisplay();
        return developer->getPhone();
    }

    Phone* MountFullPhone(){
        developer->createBox();
        developer->createDisplay();
        developer->systemInstall();
        return developer->getPhone();
    }
};

int main(){
    setlocale(LC_ALL, "Rus");

    IDeveloper* andrDeveloper = new AndroidDeveloper();
    Director director(andrDeveloper);

    Phone* samsung = director.MountFullPhone();
    cout<< samsung->aboutPhone()<<endl;

    IDeveloper* iphoneDeveloper = new IPhoneDeveloper();
    director.setDeveloper(iphoneDeveloper);

    Phone* iphone = director.MountOnlyPhone();
    cout<< iphone->aboutPhone()<<endl;
}
