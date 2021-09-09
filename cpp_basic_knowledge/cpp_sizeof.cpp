#include<iostream>

using namespace std;

/*****************
一个类中，虚函数本身、成员函数（包括静态与非静态）和静态数据成员都是不占用类对象的存储空间。
对于包含虚函数的类，不管有多少个虚函数，只有一个虚指针,vptr的大小。
普通继承，派生类继承了所有基类的函数与成员，要按照字节对齐来计算大小
虚函数继承，不管是单继承还是多继承，都是继承了基类的vptr。(32位操作系统4字节，64位操作系统 8字节)！
虚继承,继承基类的vptr。
******************/
class A1{};

class A2{
public:
  //char c;
  //int u;
  virtual void fun1(){};
  virtual void fun2(){};
  static int i1;
  static int i2;
};

class A3{
public:
  //double d1;
  char c;
  int i;
  double d;
};

/*****************
此时B1中的成员变量顺序
  char c;
  int i;
  double d;
  int i;
*****************/
class B1: public A3{
public:
  int i;
};

class B2{ 
  virtual void fun(){};
};

class B3: public A2, public B2 {
  virtual void fun3(){};
};

class B4:public B3{
  virtual void fun4(){};
};


int main()
{
  char c;
  short s;
  int i;
  long l;
  float f;
  double d;
  char * c_ptr;
  cout<<"char Size is "<<sizeof(c)<<endl;
  cout<<"short Size is "<<sizeof(s)<<endl;
  cout<<"int Size is "<<sizeof(i)<<endl;
  cout<<"long Size is "<<sizeof(l)<<endl;
  cout<<"float Size is "<<sizeof(f)<<endl;
  cout<<"double Size is "<<sizeof(d)<<endl;
  cout<<"point Size is "<<sizeof(c_ptr)<<endl;
  
  //空类的大小为1字节
  cout<<"A1 Size is "<<sizeof(A1)<<endl;
  
  // 静态数据成员被编译器放在程序的一个global data members中，它是类的一个数据成员，但不影响类的大小。
  // 不管这个类产生了多少个实例，还是派生了多少新的类，静态数据成员只有一个实例。静态数据成员，一旦被声明，就已经存在。
  // 虚指针表指针的大小为8字节
  cout<<"A2 Size is "<<sizeof(A2)<<endl;

  //字节对齐
  cout<<"A3 Size is "<<sizeof(A3)<<endl;
  //继承之后类的大小就是基类+派生类的大小
  cout<<"B1 Size is "<<sizeof(B1)<<endl;

  //继承多个基类，虚函数表指针也继承多个
  //如果派生类本身拥有虚函数，不会生成新的虚函数表，虚函数地址被添加到复制基类的虚函数表的最后一个位置
  //继承多类的时候，会被添加到继承顺序最先继承的基类虚函数表中
  cout<<"B2 Size is "<<sizeof(B2)<<endl;
  cout<<"B3 Size is "<<sizeof(B3)<<endl;
  cout<<"B4 Size is "<<sizeof(B4)<<endl;

  cout<<"sizeof"<<endl;
  return 0;
}