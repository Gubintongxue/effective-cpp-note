
# const 用法总结
const 是一个变量，其值不能改变，换言之，将变量限定为一个常量。
- const 对象一旦创建就不能改变，所以必须进行初始化

```cpp
const int i = 42; //编译时初始化
```

```cpp
const int j = get.size(); //运行时初始化
```

```cpp
int i = 42;
const int ci = i; //拷贝初始化
```

- 默认情况下，const 对象被设定为仅在文件内有效。要在多个文件中使用同一个 const，要在一个文件中定义，其他多个文件中声明，且为声明和定义都加上 extern 关键字。

```cpp
extern const int bufSize = fcn(); //定义并初始化，在file1.cpp中
extern const int bufSize; //在file1.h中声明 
```

- const 的引用，将引用绑定到 const 对象上，称为常量引用(reference to const)。
引用类型必须与其所引用对象的类型一致，但有两个例外。
1. 允许为一个常量引用绑定非常量的对象、字面值，甚至是一个表达式
```cpp
int i = 42;
const int &r1 = i;
const int &r2 = 42;
const int &r3 = r1 * 2;
```
2. 允许类型隐式转化
```cpp
double dval = 3.14;
const int &ri = dval;
```

- const 和指针
常量指针所指对象为常量，指针常量其指针为常量。
```cpp
int i = 0;
const double *p1 = &i; //常量指针
double const *p1 = &i; //常量指针
double *const p2 = &i; //指针常量
const double *const p3 = &i; //p3为一个指向常量对象的常量指针
```

- 顶层 const，表示指针本身是个常量；底层 const，表示指针所指的对象是一个常量。更一般的，顶层 const 可以表示任意的对象是常量；底层 const 则与指针和引用等复合类型的基本类型部分有关。
```cpp
int i = 0;
const double *p1 = &i; //常量指针，底层
double const *p1 = &i; //常量指针，底层
double *const p2 = &i; //指针常量，顶层
const double *const p3 = &i; //p3为一个指向常量对象的常量指针，第一个为底层，第二个为顶层
const int ci = 42; //ci值不变，底层
const int &r = ci; //用于声明引用的const都是底层
```

执行拷贝操作时，顶层 const 不受影响，但底层 const 会受到限制。
```cpp
int *p = p3; //错误，p3包含底层const含义，而p没有
p1 = p3; //正确，两者皆为底层
p1 = &i; //正确，int*可转化为const int*
int &r = ci; //错误，普通int&不能绑定到int常量上
const int &r2 = i; //正确，const int&可以绑定到一个普通int上
```

- const 形参和实参
当用实参初始化形参时会忽略掉顶层 const，所以，当形参有顶层 const 时，传给它常量对象或者非常量对象都是可以的。
```cpp
const int ci = 42;
int i = ci; //忽略了顶层const

void fun(const int i){} //既可传入const int也可以传入int
void fun(int i){} //错误，重复定义了fun()
```
尽量使用常量引用，因为常量引用可以把 const 对象、字面值或者需要类型转换的对象传递给普通的引用形参。

- 函数中的 const

函数前面加 const 表示函数返回值为一个常量

函数后面加 const 表示函数不可以修改 class 成员

我们定义的类的成员函数 中，常常有一些成员函数不改变类的数据成员，也就是说，这些函数是**只读**函数，而有一些函数要修改类数据成员的值。如果把不改变数据成员的函数都加上const关键字进行标识，显然，可提高程序的可读性。其实，它还能提高程序的可靠性，已定义成const的成员函数，一旦企图修改数据成员的值，则编译器按错误处理。 const成员函数和const对象 实际上，const成员函数还有另外一项作用，即常量对象相关。对于内置的数据类型，我们可以定义它们的常量，用户自定义的类也一样，可以定义它们的常量对象。
　　
1. 非静态成员函数后面加const（加到非成员函数或静态成员后面会产生编译错误）
2. 表示成员函数隐含传入的this指针为const指针，决定了在该成员函数中，
任意修改它所在的类的成员的操作都是不允许的（因为隐含了对this指针的const引用）；
3. 唯一的例外是对于mutable修饰的成员。

加了const的成员函数可以被非const对象和const对象调用

但不加const的成员函数只能被非const对象调用
