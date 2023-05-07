
## 04 确定对象被使用前已先被初始化
读取未初始化的值会导致不明确的行为，最佳处理办法就是在使用对象前都进行初始化。
- 内置类型，手动进行初始化
	```cpp
	int x = 0;
	const char* text = "A C-style string";
	
	double d;
	stf::cin >> d;
	```
	
- 内置类型以外的，在构造函数进行初始化，注意赋值和初始化是不同的，初始化发生在赋值之前。
	```cpp
	ABEntry::ABEntry(const std::string& name, const std::string& address,
			  const std::list<PhoneNumber>& phones)
			 :theName(name),
			  theAddress(address),
			  thePhones(phones),
			  numTimeconsulted(0) //初始化列表 
			  { }
	```
	注：
  1. 总是在初始化列表中列出所有成员变量，以免还得记住哪些成员变量可以无需初始化。
  2. 如果成员变量是 const 或 references，一定要初始化，不能被赋值。
  3. 在类中有多个构造函数，且有大量重复初始化操作时，将一些赋值表现和初始化一样好的成员变量，抽象到一个函数内（通常 private），供所有构造函数调用。
  4. 成员初始化顺序固定与声明顺序相同，故最好初始化列表最好与声明顺序一致，也要尽量避免使用某些成员初始化其他成员。
    ```cpp
    class X {
      int i;
      int j;
    public:
      X(int val) : j(val), i(j) { } //会按照 i,j 顺序初始化，i 会用为定义的 j 进行初始化
    };
    ```
- 为免除 “ 跨编译单元的初始化顺序” 问题，以 local static 对象替换 non-local-static 对象。

  这里的 static 指从构造出来直到程序结束为止的量，例如 global 对象、定义于 namespace 作用域的对象、在 classes 内、在函数内、以及在 file 作用域内被声明为 static 的对象。
  函数内的 static 对象称为 local static 对象，其他 static 对象称为 non-local static 对象。
	```cpp
	class FileSystem { 
	public:
		...
		std::size_t numDisks() const;
		... 
	};
	//extern FileSystem tfs; //non-local-static
	FileSystem& tfs() //以 local static 对象替换 non-local-static 对象
	{
		static FileSystem fs;
		return fs;
	}
	class Directory {
	public:
		Directory(params);
		...
	};
	Directory::Directory(params)
	{
		...
		std::size_t disks = tfs.numDisks();
		...
	}
	Directory& tempDir() //以 local static 对象替换 non-local-static 对象
	{
		static Directory td;
		return td; 
	}
	Directory tempDir(params); //
	```
	C++ 保证，函数内的 local static 对象会在函数调用期间，首次遇上该对象之定义式时被初始化；
	
	返回一个 reference 指向 local static 对象，可以保证获得一个历经初始化的对象；
	
	在未调用 non-local-static 对象的 local static 函数时，不会发生构造和析构成本。
	
	注：
  
	任何一种 non-const static 对象，不论 local 或 non-local，在多线程环境下 “等待某事发生” 都会有麻烦发生，此方法在单线程程序中可提供良好的服务。
