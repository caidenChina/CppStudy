/*******************
C++特性之封装、继承、多态
单个类访问控制：
public: 在类的内部和外部都可以访问的成员。
private: 在类的内部可以访问，在类的外部不可以访问,只能通过成员函数或友元函数进行访问。
protected: 在类的内部可以访问，在类的外部不可以访问,但在派生类中可以访问。

public继承: 所有基类成员在派生类中保持原有的访问级别。
protected继承: public–protected， protected-protected，private-private。
private继承: 所有基类成员在派生类中变为private成员。

final关键字用于两个地方
第一个用在类，用于说明该类是继承体系下最后的一个类，不要其他类继承我，当继承时就会报错。
第二个用在虚函数，表示这个虚函数不能再被override了，再override就会报错。

override用于虚函数，加上override的话，表示告诉了编译器，我确实要重写，但写错了，没有重写，于是报错,
这样就能给我们对虚函数的重写做检查!
=default 目的：让编译器自动声明默认特殊成员函数函数体 =default不可以使用在普通函数上
=delete 目的：显式禁用成员函数 =delete可以使用在任何函数身上
=0只能用在virtual funciton上
*******************/

#include<iostream>

using namespace std;

class Fruit 
{
public:
  void get_fruit_public_num(){cout<<"\n fruit public num: "<<fruit_public_num_; };
  int fruit_public_num_ = 10;
private:
  void fruit_private_num();
  int fruit_private_num_ = 20;
protected:
  void fruit_protected_num();
  int fruit_protected_num_ = 30;
};

class apple :public fruit
{
public:
  void get_apple_public_num(){cout<<"\n apple public num: "<<apple_public_num_; };
  int apple_public_num_ = 10;
private:
  void apple_private_num();
  int apple_private_num_ = 20;
protected:
  void apple_protected_num();
  int apple_protected_num_ = 30;
};

int main()
{
  Fruit* fru = new Fruit;
  fru->get_fruit_public_num();
  cout<<"\n public num: "<<fru->fruit_public_num_;
  //cout<<"\n private num: "<<fru->fruit_private_num_;
  //cout<<"\n protected num: "<<fru->fruit_protected_num_;
  
  cout<<"\n hello c plus plus \n";
  return 0;
}