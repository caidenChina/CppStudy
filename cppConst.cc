#include<iostream>
using namespace std;

/*******************
定义：
常类型是指使用类型修饰符const说明的类型，常类型的变量或对象的值是不能被更新的。
和#define的区别：
const常量具有类型，编译器可以进行安全检查；#define宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查。
*******************/
int main()
{
  const int a=10;
  cout<<a<<endl;
  //a=20; error! 常量不能被修改
  
/********************
const 指针
  const char * a; //指向const对象的指针或者说指向常量的指针。
  char const * a; //同上
  char * const a; //指向类型对象的const指针。或者说常指针、const指针。
  const char * const a; //指向const对象的const指针。
如果const位于*的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；
如果const位于*的右侧，const就是修饰指针本身，即指针本身是常量。
********************/
  //指向常量的指针
  //const int *ptr2;
  //*ptr = 10; //error
  //ptr是一个指向int类型const对象的指针，const定义的是int类型，也就是ptr所指向的对象类型，而不是ptr本身，所以ptr可以不用赋初始值。但是不能通过ptr去修改所指对象的值。
  
  //允许把非const对象的地址赋给指向const对象的指针。
  const int *ptr;
  int val = 3;
  ptr = &val; //ok
  cout<<*ptr<<endl;
  //如果要修改指针所指向的对象值，必须通过其他方式修改，不能直接通过当前指针直接修改。
  int *ptr1 = &val;
  *ptr1=4;
  cout<<*ptr<<endl;
  
  int num=0;
  int * const ptr2=&num; //const指针必须初始化！且const指针的值不能修改
  cout<<*ptr2<<endl;
  //上述修改ptr2指针所指向的值，可以通过非const指针来修改。
  int * t = &num;
  *t = 1;
  cout<<*ptr2<<endl;
  
  const int p = 6;
  const int * const ptr4 = &p;
  cout<<*ptr4<<endl;
  //当把一个const常量的地址赋值给ptr时候, ptr必须是const指针
  
  return 0;
}

/*******************
未被const修饰的变量不需要extern显式声明！而const常量需要显式声明extern，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。

//未被const修饰的变量在不同文件的访问
// file1.cpp
int ext
// file2.cpp
extern int ext;
//const常量在不同文件的访问
//extern_file1.cpp
extern const int ext=12;
//extern_file2.cpp
extern const int ext;
*******************/

/*******************
使用const关键字进行说明的成员函数，称为常成员函数。只有常成员函数才有资格操作常量或常对象，没有使用const关键字进行说明的成员函数不能用来操作常对象。
对于类中的const成员变量必须通过初始化列表进行初始化
const对象只能访问const成员函数,而非const对象可以访问任意的成员函数,包括const成员函数
*******************/