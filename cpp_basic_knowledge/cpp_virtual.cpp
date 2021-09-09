#include<iostream>

using namespace std;

/******************
静态函数不能是虚函数，也不能被const和volatile修饰
静态函数不属于任何对象实例，加上virtual没有意义
虚函数是依靠虚函数表指针和虚函数表来处理的，虚函数表指针在构造函数中生成
只能用this指针访问，静态函数没有this指针，所以不能访问

构造函数除了inline/explicit之外，不能有别的关键字修饰
构造函数不可以声明为虚函数的原因：虚函数表是编译阶段就已经产生，但是虚函数表指针是在实例化对象的时候才产生
如果类含有虚函数，编译器会在构造函数中添加代码创建虚函数表指针
如果构造函数是虚函数，那么需要通过表指针访问虚函数表，可指针并未产生

之所以使用虚函数。是因为需要在信息不全的情况下进行多态运行
构造函数是用来初始化实例的，实例的类型必须是明确的
******************/
class people
{
public:
  people(){ cout<<"people constructor \n";}
  virtual void eat(){ cout<<"people eat \n";}
  virtual void sleep(int i=10){ cout<<"people sleep "<<i<<" hours \n";}
  virtual ~people(){cout<<"people destructor \n";}
};

class worker: public people
{
public:
  worker(){cout<<"worker constructor \n";}
private:
//基类虚函数声明为public，派生类为private，则虚函数可以为私有函数
  void eat(){ cout<<"worker eat \n";}
  void sleep(int i=8){ cout<<"worker sleep "<<i<<" hours \n";}
  virtual ~worker(){cout<<"worker destructor \n";}
};

int main()
{
  people *p1=new people;
  p1->sleep();//10
  delete p1;
  
  worker *w1= new worker;
  cout<<"asf \n";
  people *w2=w1;
  //虚函数是动态绑定的，默认参数是静态绑定的，默认参数需要看指针的类型，而不是对象的类型
  w2->sleep();//10
  delete w2;
  
  cout<<" virtual table "<<endl;
  return 0;
}