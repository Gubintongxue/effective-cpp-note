补充 [const 用法总结](https://github.com/yuedaokong/Effective-Cpp-Learing/blob/main/Accustoming%20Yourself%20to%20C%2B%2B/02/const%E7%94%A8%E6%B3%95%E6%80%BB%E7%BB%93.md) [enum 用法总结](https://blog.csdn.net/qq_39344285/article/details/115206889?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165102658816781483759880%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165102658816781483759880&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-115206889-null-null-2~all~top_click~default-2-115206889.142^v9^control,157^v4^control&utm_term=enum&spm=1018.2226.3001.4187)

### 用常量替换 #define
`#define ASPECT_RATIO 1.653` 
- 如果调用的库函数非你所写，则会不清楚 1.653 所指，追溯所指含义浪费时间
- 你所使用名称可能并未进入记号表

解决方法用常量替换 #define
```cpp
const double AspectRatio = 1.653;
```
作为一个常量，AspectRatio 一定被编译器看到，并进入记号表。

使用常量替换#define，有两种特殊情况
1. 定义常量指针，若要在头文件内定义一个常量的 char*-based 字符串，必须写两次 const，保证指针和所指对象都为常量。
```cpp
const char* const authorName = "Scott Meyers";
```
用 string 对象通常比其更好些
```cpp
const std::string authorName("Scott Meyers");
```
2. class 的专属常量，为了将常量作用域限制在类内，必须让它成为一个 static 成员，以确保此常量至多只有一份实体。
```cpp
class GamePlayer{
private:
	static const int NumTurns = 5; //常量声明式
	int scores[NumTurns];
	...
}
``` 
当需取某个 class 的专属常量地址时，需给出常量定义式，放入实现文件而非头文件。
```cpp
const int GamePlayer::NumTurns; //声明中已赋值，则无需赋值
```
### 用枚举替换 #define
唯一例外是当 class 在编译期间需要一个 class 常量值，可改用所谓的 “the enum hack” 补偿做法，一个枚举类型的数值可充当 ints 被使用。

enum hack 的行为比较类似与 #define，例如 enum 不能取址，所以别人不能通过指针或引用指向你的某个整数常量；并且 Enums 和 #defines 一样绝不会导致非必要的内存分配。
```cpp
class GamePlayer{
private:
	enum { NumTurns = 5 };
	int scores[NumTurns];
	... 
}
```
### 用 inline 函数替换 #define
`#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))` 
- 调用时很可能因为括号原因遇到错误

解决方法用 inline 函数模板替换 #define
```cpp
template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	f(a > b ? a : b);
}
```
