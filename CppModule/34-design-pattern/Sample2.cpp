//
// Created by 海盗的帽子 on 2020/6/24.
//

//工厂模式
//1。简单工厂
//把对象的创建封装在一个接口函数里
//2。工厂方法
//提供一个纯虚函数，定义派生的具体产品的工厂，
//3。抽象工厂
//有些产品具有关联关系，可放到一个工厂

//工厂模式：主要封装了对象的创建
#include <string>
#include <iostream>

using namespace std;

class Car {
public:
    Car(const string &name) : name(name) {

    }

    virtual void show() = 0;

protected:
    string name;
};

class Bmw : public Car {
public:
    Bmw(const string &name) : Car(name) {}

    void show() override {
        cout << "Bmw" << endl;
    }
};

class Audi : public Car {
public:
    Audi(const string &name) : Car(name) {}

    void show() override {
        cout << "Audi" << endl;
    }
};

enum CarType {
    BMW, AUDI
};

class SimpleFactory {
public:
    Car *createCar(CarType type) {
        switch (type) {
            case BMW:
                return new Bmw("AS");
            case AUDI:
                return new Audi("CC");
            default:
                return nullptr;
        }
    }
};

//简单工程不封闭，不符合开闭原则，一个工厂只做一种汽车

class Factory {
public:
    virtual Car* createCar(string name) = 0;

};

class BmwFactory : Factory {
public:
    Car *createCar(string name) override {
        return new Bmw(name);
    }
};

class AudiFactory : Factory {
    Car *createCar(string name) override {
        return new Audi(name);
    }
};

int main() {
    SimpleFactory* simpleFactory = new SimpleFactory();
    Car* bmw = simpleFactory->createCar(BMW);
    Car* audi = simpleFactory->createCar(AUDI);
    bmw->show();
    audi->show();

    //具体工厂类
    BmwFactory* bmwFactory = new BmwFactory();
    Car* bmw2 = bmwFactory->createCar("AA");
}




