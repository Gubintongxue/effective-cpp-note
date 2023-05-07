
## 07 为多态基类声明 virtual 析构函数
对于一个多态基类通常要将析构函数声明为 virtual。
```cpp
class TimeKeeper {
public:
	TimeKeeper();
	virtual ~TimeKeeper(); //基类的析构函数声明为虚函数
};
class AtomicClock: public TimeKeeper { ... };
class WaterClock: public TimeKeeper { ... };
class WristWatch: public TimeKeeper { ... };
TimeKeeper* ptk = getTimeKeeper();
...
delete ptk;
```
如果基类析构函数不声明为虚函数，delete 时，基类的成分通常会被销毁，而派生类的成分没被销毁，从而造成 “局部销毁”，会导致内存泄漏、败坏数据结构、调整器时间浪费。

使用 virtual 析构函数的注意事项
1. 任何 class 只要带有 virtual 函数都几乎确定应该也有一个 virtual 析构函数
2. 如果 class 不含 virtual 函数，通常表示它并不打算作为基类，如果无端地将所有的 classes 的析构函数都声明为 virtual，可能出现以下问题：
	- 实现 virtual 函数，要在运行期间决定哪个 virtual 函数被调用，vptr (virtual table poiner) 指向一个函数指针构成的数组 vtbl (virtual table)，这会使对象的占用体积增加。 
	- 带有 virtual 函数对象也不再和其他语言声明有相同结构，因此也不再可能把它传递至其他语言所写的函数，除非明确补偿 vptr，因此不再具有**移植性**。
3. 不要继承一个标准容器或任何其他 ”带有 non-virtual 析构函数“ 的 class
	```cpp
	class SpecialString: public std::string {
		...
	};
	SpecialString* pss = new SpecialString("Impending Doom");
	std::string* ps;
	...
	ps = pss;
	..
	delete ps; // SpecialString的析构未被调用，*ps的SpecialString资源会泄露
	```
4. 令抽象类带一个纯虚析构函数十分便利，但必须为这个纯虚函数提供一个定义，由于析构函数的运作方式是先调用 most derived 的析构函数，再调用每个 base class 的析构函数，层层向外。
	```cpp
	class AWOV {
	public:
		virtual ~AWOV() = 0; //声明纯虚析构
	};
	AWOV::~AWOV() { } //纯虚析构定义
	```
