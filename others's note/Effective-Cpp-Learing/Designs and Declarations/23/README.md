## 23 宁以 non-number、non-friend 替换 member 函数
```cpp
class WebBrowser {
public:
	...
	//member函数调用clearCache,clearHistroy,removeCookies
	//void clearEverything();  
	void clearCache();
	void clearHistroy();
	void removeCookies();
};
//non-member函数调用clearCache,clearHistroy,removeCookies
void clearBrowser(WebBrowser& wb) 
{
	wb.clearCache();
	wb.clearHistory();
	wb.removeCookies();
}
```
non-member 比 member 函数好的原因

由于封装性，越多的东西被封装，越少的人可以看到它，就有越大的弹性去改变它。进而，某一块封装的数据，有越多的函数可访问它，数据的封装性就越低。因此，non-member、non-friend 比 member 函数可访问的数据量少，封装性更好。

注：
1. friend 函数对 class private  成员的访问权力和 member 函数相同，因此从封装的角度看，是在 member 和 non-member、non-friend 之间做选择。
2.  non-member 函数可以是另一个 class 的 member 函数
