#include<iostream>

using namespace std;

/*******************
static 关键字
静态变量：函数或者类中的变量
静态类的成员：类对象的类中的函数
*******************/

/******************
函数静态变量
变量声明为static时，空间将在程序的生命空间分配，
多次调用函数，静态变量空间也只分配一次，前一次调用值通过下一次调用传递
******************/

void staFun()
{
  static int num_i = 0;
  ++num_i;
  cout<<"num_i: "<<num_i<<"\n address: "<<&num_i<<endl;
}

/*****************
类中的静态变量
变量只被初始化一次，由所有对象共享，因此不能使用构造函数初始化
静态变量在类外使用命名空间初始化
*****************/
class staCla
{
public:
  staCla(){};
  virtual ~staCla(){};
  int get_num(){return num_i;}
  void set_num(int i){num_i=i;}
  static void isStaFun(){cout<<"I'm static fun\n";}
private:
  static int num_i;
};

int staCla::num_i = 1;
//修改类的静态变量值，所有对象的变量值都会改变
void useStaCla()
{
  staCla sC1;
  staCla sC2;
  cout<<sC1.get_num()<<"  "<<sC2.get_num()<<endl;
  sC1.set_num(11);
  cout<<sC1.get_num()<<"  "<<sC2.get_num()<<endl;
 
  //静态函数可用对象或命名空间访问，推荐使用后者
  //静态函数只能访问静态变量或其他静态函数，无法访问非静态变量或成员函数
  //因为静态变量和函数提托于类存在，非静态的提托于对象存在，没有实例化对象之前是不存在的
  sC1.isStaFun();
  staCla::isStaFun();
}

/**************
静态类对象
静态类对象的生命周期贯穿整个程序的生命周期
**************/
class nonStaObj
{
public:
  nonStaObj(int i):num_i(i){cout<<num_i<<"  consructor \n";}
  ~nonStaObj(){cout<<num_i<<"  destructor \n";}
  int num_i;  
};

void useNonStaObj()
{
  int i=1;
  if(i==1)
    static nonStaObj temp1(10);
  if(i==1)
    nonStaObj temp2(20);
  cout<<"temp2 been destroied \n";
}
int main()
{
  // //值通过函数调用传递，每次调用时，不会进行初始化
  // for(int i=0;i<5;++i)
    // staFun();// 0 1 2 3 4
  
  useStaCla();
  //useNonStaObj();
  
  cout<<"static"<<endl;
  return 0;
}