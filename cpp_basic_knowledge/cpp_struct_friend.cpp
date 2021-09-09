#include<iostream>

using namespace std;

/******************
C++结构体中不仅可以定义数据，还可以定义函数。
C++结构体中可以使用访问修饰符，如：public、protected、private 。
C++结构体使用可以直接使用不带struct。
C++继承
若结构体的名字与函数名相同，可以正常运行且正常的调用！但是定义结构体变量时候要用带struct的！
******************/

/*****************
友元函数：
在类声明的任何区域中声明，而定义则在类的外部。
友元函数中通过对象名来访问该类的私有或保护成员。
友元类：
友元类的声明在该类的声明中，而实现在该类外。
friend class <友元类名>;
类B是类A的友元，那么类B可以直接访问A的私有成员
友元关系没有继承性，没有继承性
*****************/
typedef struct people
{
public:
  people(int i){age = i;}
  void get_age(){cout<<"people age is: "<<age<<endl;}
  friend void set_age(people &p, int num);
private:
  int age;
}peo;

void set_age(people &p, int num)
{
  p.age = num;
}


int main()
{
  //peo p1(24);
  //p1.get_age();
  //set_age(p1,18);
  //p1.get_age();
  
  cout<<"cpp struct"<<endl;
  return 0;
}