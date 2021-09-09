#include<iostream>

using namespace std;

/*****************
1.纯虚函数与抽象类
C++中的纯虚函数(或抽象函数)是我们没有实现的虚函数！我们只需声明它!通过声明中赋值0来声明纯虚函数！
纯虚函数：没有函数体的虚函数
抽象类：包含纯虚函数的类
抽象类只能作为基类来派生新类使用，不能创建抽象类的对象,抽象类的指针和引用->由抽象类派生出来的类的对象！
*****************/
//接口类至少包含一个纯虚函数
class people
{
public:
  //接口类可以有构造函数
  people(int i){age = i;}
  virtual void eat() = 0;
  //成员函数可以调用纯虚函数，构造函数/析构函数不能调用
  void dinner(){ this->eat(); }
  void getAge(){cout<<"people age is "<<age<<endl;}
private:
  int age;
};

//从接口类派生出来的类想要实例化必须实现接口类的所有纯虚函数，否则也会成为纯虚类；
class worker: public people
{
public:
  worker(int i):people(i){};
  void eat(){ cout<<"worker eat \n";}
};

int main()
{
  //people p1;  //error 抽象类不能创建对象
  people *p2 = new worker(24);//可以，抽象类可以有指针
  p2->dinner();
  p2->getAge();
  
  cout<<"pule virtual"<<endl;
  return 0;
}