## 17 以独立语句将 newed 对象置入智能指针
```cpp
int priority();
void processWidget(std::tr1::shared_ptr<Widget> pw, int priority);
//tr1::shared_ptr的构造函数是explicit构造函数，无法进行隐式转换
//processWidget(new Widget, priority()); 
//显式转换
proccessWidget(std::tr1::shared_ptr<Widget>(new Widget), priority());
```
上诉形式可能造成资源泄露，如果执行 new Widget 后，执行 priority()的调用出现异常，则不会调用 tr1::shared_ptr 的构造函数，new Widget 的指针就不会调用 tr1::shared_ptr 的析构进行销毁。

要避免这种问题出现，只需将语句分离。
```cpp
std::tr1::shared_ptr<Widget> pw(new Widget); //智能指针存储newed对象
proccessWidget(pw, priority()); //在调用函数，就不会发生泄露
```
