## 26 尽可能延后变量定义式的出现时间
```cpp
//这个函数过早的定义变量”encrypted“
void encrypt(std::string& s); //在其中的适当位置对s加密
std::string encryptPassword(const std::string& password)
{
	using namespace std;
	string encrypted;
	if (password.length() < MinimumPasswordLength) {
		throw logic_error("Password is too short");
	}
	...
	return encrypted;
}
```
如果抛出 logic_error，则 encrypted 完全未被使用，还需付出构造和析构的成本。所以最好延后 encrypted 的定义式，直到确实需要它。
```cpp
void encrypt(std::string& s); //在其中的适当位置对s加密
std::string encryptPassword(const std::string& password)
{
	...
	//std::string encrypted; 
	//encrypted = password;
	//更好的方式是跳过default构造的过程，使用copy构造函数定义并初始化
	std::string encrypted(password);
	encrypt(encrypted);
	return encrypted;
}
```
面对循环时的方式
- A：定义于循环外
	```cpp
	Widget W;
	for (int i = 0; i < n; ++i) {
		w = 取决于i的某个值;
		...
	}
	```
	1次构造 + 1次析构 + n次赋值
- B：定义于循环内
	```cpp
	for (int i = 0; i < n; ++i) {
		Widget w(取决于i的某个值);
		...
	}
	```
	n次构造 + n次析构

做法A造成名称 w 的作用域比做法 B 更大，会对程序的可理解性和易维护性造成冲突，
因此除非明确知道赋值成本比构造 + 析构成本低或此部分代码对效率要求很高，否则建议使用做法 B。
