//
// Created by 海盗的帽子 on 2020/6/1.
//

class Person {
public:
    int age;
};

class Student : public Person {

};

int main() {
    double num = 0.2;
    int num1 = static_cast<int>(num);//静态转换，常用于基本数据类型

    const Person *person = new Person();
//    person->age = 12;不能修改
    Person *p1 = const_cast<Person *>(person);//常量指针的转换
    p1->age = 10;


    //除了字符类，各种类型的转换，long -> 对象指针，用到reinterpret_cast
    //
    Student* student = reinterpret_cast<Student*>(p1);


    //和 static_cast类型，但是更安全
    Person* p2 = dynamic_cast<Person*>(p1);



    //1.用于基本数据类型的转换
    //2.把类型转换成另一种类型
    //3.
}