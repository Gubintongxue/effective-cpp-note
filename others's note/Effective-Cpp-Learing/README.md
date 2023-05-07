# Effective  C++
## 改善程序与设计的55个具体做法
1. [让自己习惯 C++](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Accustoming%20Yourself%20to%20C%2B%2B)
- 01 [视 C++ 为一个语言联邦](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Accustoming%20Yourself%20to%20C%2B%2B/01)
- 02 [尽量以 const , enum, inline 替换 #define](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Accustoming%20Yourself%20to%20C%2B%2B/02)
- 03 [尽可能使用 const](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Accustoming%20Yourself%20to%20C%2B%2B/03)
- 04 [确定对象被使用前已先被初始化](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Accustoming%20Yourself%20to%20C%2B%2B/04)

2. [构造，析构，赋值运算](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs%2C%20Destructs%2C%20and%20Assignment%20Operators)
- 05 [了解 C++ 默默编写并调用哪些函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/05)
- 06 [若不想使用编译器自动生成的函数，就该明确拒绝](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/06)
- 07 [为多态基类声明 virtual 析构函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/07)
- 08 [别让异常逃离析构函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/08)
- 09 [绝不在构造和析构过程中调用 virtual 函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/09)
- 10 [令 operator= 返回一个 *reference to* ***this**](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/10)
- 11 [在 operator= 中处理 “自我赋值”](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/11)
- 12 [复制对象时勿忘其每个成分](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Constructs,%20Destructs,%20and%20Assignment%20Operators/12)

3. [资源管理](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management)
- 13 [以对象管理资源](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management/13)
- 14 [在资源管理类中小心 *copying* 行为](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management/14)
- 15 [在资源管理类中提供对原始资源的访问](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management/15)
- 16 [成对使用 new 和 delete 时要采用相同形式](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management/16)
- 17 [以独立语句将 newed 对象置入智能指针](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Resource%20Management/17)

4. [设计与声明](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations)
- 18 [让接口容易被正确使用，不易被误用](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/18)
- 19 [设计 class 犹如设计 type](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/19)
- 20 [宁以 pass-by-reference-to-const 替换 pass-by-value](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/20)
- 21 [必须返回对象时，别妄想返回其 reference](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/21)
- 22 [将成员变量声明为 private](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/22)
- 23 [宁以 non-number、non-friend 替换 member 函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/23)
- 24 [若所有参数皆需类型转换，请以此采用 non-member 函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/24)
- 25 [考虑写出一个不抛出异常的 swap 函数](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Designs%20and%20Declarations/25)

5. [实现](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations)
- 26 [尽可能延后变量定义式的出现时间](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations/26)
- 27 [尽量少做转型动作](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations/27)
- 28 [避免返回 handles 指向对象内部成分](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations/28)
- 29 [为 “异常安全” 而努力是值得的](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations/29)
- 30 [透彻了解 inlining 的里里外外](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations/30)
- 31 [将文件间的编译依存关系降到最低](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Implementations/31)

6. [继承与面向对象设计]
- 32 [确定你的 public 继承塑模出 **is-a** 关系]
- 33 [避免遮掩继承而来的名称]
- 34 [区分接口继承和实现继承]
- 35 [考虑 virtual 函数以外的其他选择]
- 36 [绝不重新定义继承而来的 non-virtual 函数]
- 37 [绝不重新定义继承而来的缺省参数值]
- 38 [通过复合塑模出 **has-a** 或 “根据某物实现出”]
- 39 [明智而审慎地使用 private 继承]
- 40 [明智而审慎地使用多继承]

7. [模板与泛型编程]
- 41 [了解隐式接口和编译期多态]
- 42 [了解 typename 的双重意义]
- 43 [学习处理模板化基类内的名称]
- 44 [将与参数无关的代码抽离 templates]
- 45 [运用成员函数模板接受所有兼容类型]
- 46 [需要类型转换时请为模板定义非成员函数]
- 47 [请使用 traits classes 表现信息]
- 48 [认识 template 元编程]

8. [定制 new 和 delete]
- 49 [了解 new-handler 的行为]
- 50 [了解 new 和 delete 的合理替换时机]
- 51 [编写 new 和 delete 时需固守常规]
- 52 [写了 *placement* new 也要写 *placement* delete]

9. [杂项讨论](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Miscellany)      
- 53 [不要轻忽编译器的警告](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Miscellany/53)
- 54 [让自己熟悉包括 TR1 在内的标准程序库](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Miscellany/54)
- 55 [让自己熟悉 Boost](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Miscellany/55)
