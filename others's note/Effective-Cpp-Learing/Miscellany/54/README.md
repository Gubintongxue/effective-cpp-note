## 54 让自己熟悉包括 TR1 在内的标准程序库
TR1 是 C++0x 新加入的功能模块，都放在 std::tr1 命名空间内，在 C++11后都统一放在 std 内，使用时直接 `using namespace std;` 即可。

新增14个组件分别是
- 智能指针
- [tr1:: function](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Inheritance%20and%20Object-Oriented%20Design/35) 此物得以表示任何可调用物，只要其签名符合目标。 
- [tr1:: bind](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Inheritance%20and%20Object-Oriented%20Design/35) 可做 STL 绑定器 (binders) bind1st 和 bind2nd 所做的每一件事。
- Hash Tables 用于底层实现 unordered_set/unordered_multiset/unordered_map/unordered_multimap。
- 正则表达式。
- Tuples （变量组），升级的 pair，可持有任意个数的对象。
- tr1:: array STL 化的数组，大小固定，不使用动态内存。C++11 中 initialier_list<T> 关联 array   来实现容器的列表初始化。
- tr1:: mem_fn 这个语句构造上与成员函数指针一致。
- tr1:: refernce_wrapper
- 随机数生成工具
- 数学特殊函数
- C99 兼容扩充
- [Type traits](https://github.com/yuedaokong/Effective-Cpp-Learing/tree/main/Templates%20and%20Generic%20Programming/47) 用以提供类型 (types) 的编译期信息。
- tr1:: result_of 用来推导函数调用的返回类型。
