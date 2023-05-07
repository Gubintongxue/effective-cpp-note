## 08 别让异常逃离析构函数
在两个异常同时存在的情况下（两个异常对于 C++ 来说太多了），程序若不是结束执行就是导致不明确行为。

如果析构函数必须执行一个动作，而动作可能会在失败时，抛出异常，该怎么办？
```cpp
class DBconnection {
public:
	...
	static DBConnection create();
	void close();
};
//创建一个DBConn类管理DBConnection的资源，防止用户忘记调用close
class DBConn {
public:
	...
	~DBConn()
	{
		db.close();
	}
};
//通过DBConn接口调用DBConnection对象，并销毁
{
	DBConn dbc(DBConnection::create());
	...
}
```
以上程序，如果在调用出现异常的情况下，DBConn 析构函数会传播该异常，离开这个析构，导致没有完全销毁。

比较好的处理办法就是重新设计 DBConn 接口，使其用户有机会对可能出现的问题作出反应，并且在析构函数中结束程序或吞下异常（有时候吞下异常也比负担 “草率结束程序” 或 “不明确行为带来的风险” 好），提供双保险。
```cpp
class DBConn {
public:
	...
	void close(){                           //用户可选择是否调用close
		db.close();
		closed = true;
	}
	~DBConn(){
		if (!closed){
			try {
				db.close();
			}catch (...){           //如果关闭动作失败
				...             //记录下来并结束程序或吞下异常
				std::abort();   //abort强制中止当前程序
			}
		}
	}
private:
	DBConnection db;
	bool closed;
};
```
