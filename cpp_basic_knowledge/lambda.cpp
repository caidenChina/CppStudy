#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/********************************
[捕获列表](参数列表)mutable/exception->retType {}
mutable决定[]能够被改写  
mutable exception retType都是可选项
retType 返回类型
*********************************/

class FunctionObj {
public:
  FunctionObj(int var) : localVar(var) {}

  bool operator()(int val) {
    return val == localVar;
  }

private:
  int localVar;
};

class CaptureThis{
public:
  CaptureThis(int x, int y) : num_x(x), num_y(y) {}

  int sum() {
    // 下列 lambda 的语境是成员函数 CaptureThis::sum
    // 对于[=]或[&]的形式，lambda 表达式可以直接使用 this 指针
    return [=]() -> int {
      return this->num_x + (this)->num_y; 
    }();
  }

  int getX() {
    return [this]() {
        return this->num_x;
    }();
  }
private:
  int num_x, num_y;

};
  
int main() {

  [] {
    cout << "empty lambda" << endl;
  }();

  auto I = [] {
    cout << "empty lambda again" << endl;
  };
  I();

  cout<<endl;
  int num_i = 0;
  //此时为值捕获，注意被捕获的变量是在lambda表达式创建时拷贝  
  auto f = [num_i]()mutable {
    cout << "num_i: " << num_i << endl;
    ++num_i;
  };
  num_i = 10;
  f();    // 0
  f();    // 1
  cout << num_i << endl;

//上述lambda会被编译器展开，类似于下面的函数对象
//  class Functor {
//  public:
//    void operator()() {
//      cout << "num_i=" << num_i << endl;
//      ++num_i;
//    }
//  private:
//       int num_i;
//  };
//  Functor fun;
//  fun();

  cout<<endl;
  int num_i1 = 0;
  //此时为引用捕获，捕获值会被改变
  auto f1 = [&num_i1]() {
    cout << "num_i1=" << num_i1 << endl;
    ++num_i1;
  };
  num_i1 = 100;
  f1();    // 100
  f1();    // 101
  cout << num_i1 << endl;


  // 传参与返回
  cout<<endl;
  int num_i2 = 0;
  auto f2 = [&num_i2](int &param) {
    cout << "num_i2=" << num_i2 << endl;
    ++num_i2;
    ++param;
    cout << "param=" << param << endl;
    return num_i2;
  };
  int param = 1;
  f2(param);
  cout << "num_i2=" << num_i2 << endl;
  //还可以部分传值，其他传引用，不推荐使用，最好根据需不需要修改捕获值来确定

  //捕获this 指针
  cout<<endl;
  CaptureThis Ct(1, 2);
  cout << "sum=" << Ct.sum() << endl;   // 1+2=3
  cout << "x=" << Ct.getX() << endl;    // 1

  // lambda和函数对象的比较
  // 比较数值是否相等
  cout<<endl;
  int num_equal = 5;
  auto equalNumber = [num_equal](int val) {
      return val == num_equal;
  };
  bool b1 = equalNumber(10);
  FunctionObj Fo(num_equal);
  bool b2 = Fo(5);
  cout << b1 << " " << b2 << endl;

  //使用迭代器遍历vector
  vector<int> vec{6, 195, 27, 68, 135, 564, 10545, 28, 972};
  for_each(vec.begin(), vec.end(), [](int i) { cout << i << " "; });
  cout << endl;

  return 0;
}