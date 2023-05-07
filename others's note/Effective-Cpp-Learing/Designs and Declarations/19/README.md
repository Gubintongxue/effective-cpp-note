
## 19 设计 class 犹如设计 type
设计 class 需考虑的工作
- 构造函数和析构函数的编写，负责创建与销毁
- 构造函数与赋值函数的差别
- 拷贝构造函数的实现
- 进行错误检查，抛出异常
- 继承自一个基类，要考虑受到的约束 virtual 或 non-virtual 的影响；自身作为基类，考虑声明的函数，[尤其是析构函数，是否为 virtual](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/07)
- 与其他 types 之间的转换，[隐式转换的编写](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management/15)
- 类内该声明那些函数和操作符
- [不需要哪些默认函数，要声明为 private](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/06)
- 成员函数权限 (public/private/protected)，友元函数和类
- 条款29
- 范式编程模板化
- 是否可以在其他类的基础上添加，不需新建一个类
