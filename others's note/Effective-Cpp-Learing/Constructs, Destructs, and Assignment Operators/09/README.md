
## 09 绝不在构造和析构过程中调用 virtual 函数
```cpp
class Transaction {
public:
	Transaction();
	virtual void logTransaction() const = 0; //做出一份因类型不同而不同的日志记录
	...
};
Transaction::Transaction()
{
	...
	logTransaction();
}
class BuyTransaction:public Transaction{
public:
	virtual void logTransaction() const;
}
class SellTransaction:public Transaction{
public:
	virtual void logTransaction() const;
};
BuyTransaction b;
```
上述程序运行，基类构造会在派生类构造之前，基类构造内部 virtual 函数不会下移到派生类。
由于此时派生类未被初始化，基类构造函数内部 virtual 函数不会执行，析构函数会发生同样问题。

解决方案是将 virtual 改为 non-virtual 函数，令 derived classes 将必要的构造信息向上传递至 base class 构造函数。
```cpp
class Transaction {
public:
	explicit Transaction(const std::string& logInfo);
	void logTransaction(const std:;string& logInfo) const; //做出一份因类型不同而不同的日志记录
	...
};
Transaction::Transaction()
{
	...
	logTransaction();
}
class BuyTransaction:public Transaction{
public:
	BuyTransaction(parameters)
	: Transaction(createLogString(parameters)) { ... }
	...
private:
	static std::string createLogString(parameters); //静态函数，保证不会指向未初始化对象
}

BuyTransaction b;
```
