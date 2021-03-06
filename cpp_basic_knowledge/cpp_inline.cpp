#include<iostream>

using namespace std;

class A
{
public:
  //声明后,要成为内联函数，需在定义处加inline关键字
  void fun1(int i);
  //定义之后即成为隐式内联函数
  void fun2(int x, int y){};
};

/*****************
编译器对 inline 函数的处理步骤
将 inline 函数体复制到 inline 函数调用点处；
为所用 inline 函数中的局部变量分配内存空间；
将 inline 函数的的输入参数和返回值映射到调用方法的局部变量空间中；
如果 inline 函数有多个返回点，将其转变为 inline 函数代码块末尾的分支（使用 GOTO）。
****************/
inline void A::fun1(int i)
{
  cout<<"i: "<<i<<endl;
}

int main()
{
  A a1;
  a1.fun1(5);
  cout<<"inline"<<endl;
  return 0;
}

/******************
内联能提高函数效率，但并不是所有的函数都定义成内联函数！内联是以代码膨胀(复制)为代价，仅仅省去了函数调用的开销，从而提高函数的执行效率。

如果执行函数体内代码的时间相比于函数调用的开销较大，那么效率的收货会更少！

另一方面，每一处内联函数的调用都要复制代码，将使程序的总代码量增大，消耗更多的内存空间。

以下情况不宜用内联：

（1）如果函数体内的代码比较长，使得内联将导致内存消耗代价比较高。

（2）如果函数体内出现循环，那么执行函数体内代码的时间要比函数调用的开销大。
******************/

/******************
虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类，这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。
******************/