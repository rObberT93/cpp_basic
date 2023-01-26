

## L1-绪论 & L2-编程环境

编译链接-o，只编译不链接-c

```c++
extern int x; //变量声明，此外都是定义
```

头文件只声明函数，不定义（实现）：多个实现会报错

```c++
#pragma once	//宏定义，防止头文件被重复包含
#ifndef TASK #define TASK {body...} #endif	//同上
```

宏定义是简单替换：

```c++
#define sqr(y) (y)*(y)	//括号不可删，建议使用inline替代
```

Makefile

```makefile
main: main.cpp a.h b.h c.cpp
	g++ -std=c++11 -o main main.cpp c.cpp
```

用make指令调用的时候，其编译和链接规则为：

- 如果工程没有编译过，所有Cpp文件都要编译并被链接
- 如果某几个Cpp文件被修改，只编译被修改的Cpp文件，并链接目标程序
- 如果头文件被改变了，编译引用它们的Cpp文件，并链接目标程序
- 所有的Cpp文件都被修改时，才会执行所有任务分别编译生成.o文件的任务

自动变量： $@ $^ $< (P 44)

```makefile
$@：目标文件，$^：所有的依赖文件，$<：第一个依赖文件
```

## L3-封装与接口

函数重载：缺省值可能造成二义性，编译不通过

decltype：对变量或表达式结果的类型进行推导

```c++
struct { char name[17]; } anon_u;
decltype(anon_u) as;	//重用匿名类型
```

```c++
//自动追踪返回类型
auto func(int x, int y) -> decltype(x+y) //c++14可省略
{return x+y;}
```

内联函数：inline 修饰

- 避免将内联函数的声明和定义分开：编译时内联实现，因此多文件编译时，要将实现写在头文件中，否则无效
- 定义在类声明中的函数，默认为内联函数
- 一般构造函数、析构函数都被定义为内联函数
- 编译器“有权”拒绝不合理的请求

拓展：如何在C++中打印变量类型[。](https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c)

## L4-创建与销毁 

·构造函数：

- 无返回值类型
- 按声明顺序初始化
- 初始化列表可委派（调用其它构造函数）
- 可显式删除、显示声明
- 就地初始化仍然在构造时执行

·析构函数：无参数，自动调用（private也能访问），先析构自身、后析构成员变量

·全局对象

- 在main()函数调用之前进行初始化
- 同一编译单元中（源文件），按照定义顺序进行初始化
- 不同编译单元中，对象初始化顺序不确定
- 在main()函数执行完return之后，对象被析构

·引用：定义时初始化，不能改指向，函数返回引用时不指向临时变量

·类的运算符重载：

- ​	全局：`ClassName operator+(ClassName a, ClassName b）{}`
- ​	成员：`ClassName operator+（ClassName b）{}` （类内）

```c++
...	//类内：成员函数
A& operator+=(A& a) { data += a.data; return *this;}
A operator+(A& a) {
    A new_a(data + a.data);
    return new_a;
    }
};
//类外：全局函数
A operator+(A& a1, A& a2) {
    A new_a(a1.data + a2.data);
    return new_a;
}
```

- ​	自增自减重载：后缀时加哑元

  ```c++
  //前缀自增（先增后赋值）
  A& operator++ () {
      ++data;
      return *this;
    }
  //后缀自增
  A operator++ (int) {
      Test test(data);
      ++data;
      return test;
    }
  ```

  

- 重载输入输出流：必须加友元，只能全局重载

  ```c++
  istream& operator>>(istream& in, Test& dst );
  ostream& operator<<(ostream& out, const Test& src) {	out << src.id << endl;
  	 return out;		} 
  ```

- =,[],(),-> 只能通过成员函数来重载

- [更多示例](https://www.runoob.com/cplusplus/cpp-overloading.html)

  ```c++
  //Test类内重载运算符()
  int operator() (int a, int b) {
      return a + b;
    }
  //调用
  Test sum;
    int s = sum(3, 4); // sum 是“函数对象”
  
  //重载数组下标运算符
  int& operator[] (const char* name) // 字符串作下标
  {
      return name[i];
  }
  ```


·运算符重载规则：

- C++  中的所有运算符都可以重载。例外：类属关系运算符  ` . `  、成员指针运算符  `  .*  `  、作用域运算符  `  ::  `  、`sizeof`运算符、三目运算符  ` ? : `  ；
- 不能创建新的运算符；
- 不能改变运算符的优先级和结合性；
- 不能改变运算符操作数的个数及语法结构。

## L5-创建与销毁

·友元：
	类内声明，与所在域为 private/public 皆可
	不是成员函数
	不对称、不传递、不继承

·静态变量/函数（static）：

​	静态变量——只在定义时进行一次初始化；全局变量内部可链接（只在声明的文件中使用）

​	静态函数——内部可链接

​	静态数据成员——类的所有对象共享（可通过类名、对象访问）

```c++
static Type static_var; //.h文件类内声明
Type ClassName::static_var = Value; //cpp文件中赋初值
```

​	静态成员函数——类的所有对象共享 `static void func();`
​				实例化前就分配内存，**不能访问非静态**成员

·常量（const）：

​	修饰变量——必须就地初始化

​	修饰引用/指针——无法通过引用/指针修改变量值

```c++
int a = 1; const int& b = a;	//不能通过b修改变量的值
const int* p = &a;	//不能通过p修改变量的值
int* const p = &a;	//不能改变p的指向
```

​	修饰函数——返回值不可变，可重载

​	修饰类的数据成员——初始化：初始化列表/就地（不能在构造函数体内）

​	修饰类的成员函数——

```c++
const Type Func(..) {..}	//返回值不变
Type Func(..) const {..}	//不修改数据成员值
```

​	修饰对象——`const ClassName a `对象中数据不变，只能调用 const					修饰的成员函数

·常量静态变量：类外定义（例外：int 和 exturn 可以就地初始化）

```c++
class A {
	static const char* cs; // 不可就地初始化
	static const int i = 3; // 可以就地初始化
	static const int j; // 也可以在类外定义
};
const char* A::cs = "string";
const int A::j = 4;
```

·不存在常量静态函数

| 数据成员 / 操作类型 | 静态  static | 常量 const | 常量静态 (除int, enum外) | 常量静态(int, enum) |
| ------------------- | :----------- | ---------- | ------------------------ | ------------------- |
| 就地初始化          |              | √          |                          | √                   |
| 初始化列表初始化    |              | √          |                          |                     |
| 构造函数体内初始化  |              |            |                          |                     |
| 类外初始化          | √            |            | √                        | √                   |
| 普通成员函数        | √√           | √          | **√**                    | **√**               |
| 静态成员函数        | √√           |            | √                        | √                   |
| 常量成员函数        | √√           | √          | √                        | √                   |

注：√ 表示仅可访问，√√ 表示可访问也可修改

·静态局部对象：

- 初始化：在程序第一次执行到该静态局部对象的代码时被初始化
- 析构：离开作用域不析构，在main()函数结束后被析构
- 第二次执行到代码时，不再初始化，直接使用上一次的对象

·参数对象的构造和析构：

​	使用 new/delete 生成对象数组：`A* p = new A[3];` 内存分配多4字节存数组大小。`delete []p;` 会释放包括4字节的所有内存

## L6-引用与复制

·引用：

- 定义时初始化，且不能改引用指向
- 函数参数引用，形参等于实参
- 函数返回值，不可返回临时变量

·常量引用：函数参数 const int& a，仅读取，没有权限修改a的值

·[拷贝构造函数](https://blog.51cto.com/u_15127506/4534259)：

```c++
ClassName(const ClassName& a);
```

- 同类对象的常量左值引用（可绑定左值、右值）；
- 位拷贝，注意隐式拷贝得到的指针成员指向相同内存，应自定义；
- 应尽量避免拷贝构造，函数参数传引用或常量引用，函数返回值设引用，并将拷贝构造函数设为 private 或 =delete 。

执行顺序：

```c++
Myclass func(Myclass c) {	//拷贝构造
	Myclass tmp;	//默认构造
	return tmp;		//拷贝构造
}	//temp析构，c析构

//编译选项，禁止编译器进行返回值优化
g++ test.cpp --std=c++11 -fno-elide-constructors –o test
```

·右值引用：int &&e = a + b; （无法绑定左值）
​	例外：

```c++
const int& a = 1； //常量引用也能绑定右值，但优先级低
```

​	`std::move`，左值强制转为右值

·移动构造函数：

```c++
ClassName(Classname&& a);
```

​	相比拷贝构造函数，新对象不占新的堆内存

·拷贝/移动赋值运算符：（类的非静态成员，不能是友元）

```c++
//拷贝赋值
ClassName& operator= (const ClassName& right) {
   if (this != &right) {// 避免自己赋值给自己
		// 将right对象中的内容拷贝到当前对象中...
	}
   return *this;
}
//移动赋值
ClassName& operator= (ClassName&& right) {
   if (this != &right) {// 避免自己赋值给自己
		// 将right对象中的内容移动到当前对象中...
	}
   return *this;
}
```

以上函数c++11编译器都会自动合成。

·自动类型转换：显式 Classname a(b); 隐式（可通过explicit禁用）

·强制类型转换

```c++
static_cast<NewType>(a)		//静态类型转换
dynamic_cast<NewType>(a)	//动态类型转换
```

​	

## L7-组合与继承

·组合

​	对象构造与析构函数的次序：

- 先完成子对象构造，再完成当前对象构造
- 子对象构造的次序 == 类中声明的次序
- 析构函数的次序与构造函数相反

​	隐式定义的拷贝构造函数：

- 递归调用所有子对象的拷贝构造函数
- 对于基础类型，采用位拷贝

·继承

- 继承方法，默认 private；
- 构造顺序：基类>派生类>函数体；
- 析构顺序：函数体>派生类>基类。

```c++
Base(int i) : data(i) {}	//基类构造函数
using Base::Base; 	//子类中继承基类构造函数
Derive(int i):Base(i){};	//效果同上
```

·重载（overload）：函数名相同，函数参数必须不同，作用域相同

·重写隐藏（redefining）：屏蔽基类所有同名函数，参数列表可不同，使用`using Base::f;`可恢复（基类该函数不是虚函数）

·多重继承：

```c++
class IOFile: public InputFile, public OutputFile{};
```

​	同名成员存在二义性。

## L8-虚函数

·向上类型转换：派生类（对象/引用/指针）转换为基类

- **凡是**接受基类对象/引用/指针的地方（如函数参数），**都**可以使用派生类对象/引用/指针（编译器会**自动**转换）；
- 仅对public继承有效，自动隐式转换；
- 对象向上转换会被切片，丢弃派生类独有的部分数据；

·捆绑：实现代码与调用的函数名绑定

- 早绑定：编译器完成
- 晚绑定：只对类中的**虚函数**通过**引用/指针**调用时起作用

·重写覆盖：override 辅助检查

- 函数名、函数参数相同
- 基类声明为虚函数（virtual）
- 成员函数仍然是虚函数，可不声明
- 只对指针和引用有效（类外）
- 构造函数不能是虚函数，析构函数常常是虚函数（否则可能内存泄漏）

·虚函数表(VTABLE)：在每个**包含虚函数的类**中，用于存储虚函数地址的表（虚函数表有唯一性，**编译期**建立）

虚函数指针(vpointer/VPTR)：在每个包含虚函数的类**对象**中，指向这个类的VTABLE，占8字节（运行时，**构造函数**中发生，指针调用虚函数时引起晚绑定）

·终止继承：final

·OOP的核心思想：

- 数据抽象：类的接口与实现分离

- 
  继承：建立相关类型的层次关系（基类与派生类）

- 
  动态绑定：统一使用基类指针，实现多态行为

## L9-多态与模板

·纯虚函数：`virtual void f()=0; `
	纯虚析构函数，也需要定义函数体 {}

·抽象类：

- 至少一个纯虚函数，不允许实例化为对象（保证只有指针/引用能向上类型转换，防切片）
- 抽象类的派生类必须重写所有纯虚函数（除析构），否则仍为抽象类

·向下类型转换：指针/引用的转换

```c++
auto obj_2 = dynamic_cast<Type/Type&>(obj_1); //安全、开销大，必须有虚函数
auto obj_2 = static_cast<Type/Type&>(obj_1); //不安全、开销小
```

·多态（概念）

- 定义：按照基类的接口定义，调用指针或引用所指对象的接口函数，函数执行过程因对象实际所属派生类的不同而呈现不同的效果（继承 && 虚函数 && (引用 || 指针)）
- 优点：提高程序的可复用性、可拓展性和可维护性
- 静多态：模板、重载
- 动多态：虚函数、继承

·模板：

```c++
template <typename/class T>  
T sum(T a, T b) { return a + b; }
//调用：实例化
cout << sum(9, 3); 		
cout << sum(2.1, 5.7);
cout << sum(9, 2.1); //编译错误
cout << sum<int>(9, 2.1); //正确，可以手动指定类型
```

​	注：必须在头文件中实现，不能分开编译

·类模板：更具通用性的类

```c++
template <typename T> class A {
	T data;	//类内成员变量
public:
	A(T _data): data(_data) {}
};
template<typename T>	//类外成员函数定义
void A<T>::print() { cout << data << endl; }
int main() {
	A<int> a(1);	//实例化
	return 0;
}
//可包含非类型参数
template <typename/class T, unsigned size> //编译时必须确定size的值
```

## L11-模板与stl初步

·命名空间：

```c++
namespace A{int x,  y;}	//定义
A::x = 3;	//使用
using A::y; y = 6;	//使用
```

​	任何情况下，都不应出现命名冲突

·STL：

- 标准模板库（Standard Template Library），是一个高效的C++软件库。
- 包含4个组件：算法、容器、函数、迭代器。
- 基于模板编写。
- 关键理念：将“在数据上执行的操作”与“要执行操作的数据”分离。

· pair: 

```c++
std::pair<int, int> t;
t.first = 4; t.second = 5;

auto t = std::make_pair(“abc”, 7.8); //创建
std::make_pair(1, 4) > std::make_pair(1, 2); //先比较 first
```

· tuple：pair 的扩展，下标在编译时确定

```c++
auto t = std::make_tuple(“abc”, 7.8, 123, ‘3’); //创建
//创建：tie函数—返回左值引用的元组
std::string x; double y; int z;
std::tie(x, y, z) = std::make_tuple(“abc”, 7.8, 123);
//get获取数据
auto v0 = std::get<0>(t); //v_0 = "abc";
```

· vector：（序列容器）

​	自动扩展容量的数组，允许下标访问（高速）

```c++
std:vector<int> x;	//创建
x.size();	//当前数组长度
x.clear();	//清空
x.push_back(1); x.pop_back();	//在末尾添加/删除（高速）
x.insert(x.begin()+1, 5);	//在中间添加（低速）
x.erase(x.begin()+1);	//在中间删除（低速）
```

​	元素被删或删除时，后续所有元素的迭代器失效；扩容时全失效

·迭代器： iterator （一种数据类型）`vector<int>::iterator iter;`

```c++
for(auto & x : vec)	//遍历vector
for(vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)	//等价于上
```

​	绝对安全准则：在修改过容器后，不使用之前的迭代器

· list：（序列容器）

- **不支持下标**等随机访问
- 支持在**任意位置插入/删除**数据（高速）
- 其访问主要依赖迭代器
- 插入和删除不会导致迭代器失效（除非指向被删除的元素）

· set：（关联容器）

​	**不重复**元素构成的**无序**集合（内部从小到大排）

· map：关联数组（关联容器）

- 元素key必须互不相同
- 可以通过**下标访问**（即使key不是整数）
- 下标访问时如果元素不存在，则**创建对应元素**
- 可使用 insert 函数进行插入
- 常用作稀疏数组或以字符串为下标的数组



·函数对象：
	需要重载 operator() ，权限为 public
	greater 模板类
	greater<int> 实例化的类
	greater<int>() 类的对象
	

## L12-STL和字符串处理

· string

​	构造：

```c++
//字符串 string 构造：
string str0;
string str1("Initial string");
string str2(str1, 1, 3);	// nit
string str3(str1, 3); 	// Ini
string str4("Another string", 10);	// Another st
string str5(5, 'x');		// xxxxx
string str6(str1.begin(), str1.begin() + 7)	// Initial
//转换
const char c = str1.c_str() //c不可修改
```

​	用法：

```c++
//常见用法，和vector类似
cout << str[1]; str[1]='a';	//访问/修改元素
str.size()	//查询长度
str.clear()	//清空
str.empty()	//查询是否为空
for(char c : str)	//迭代访问
str.push_back('a'); str.append(s2);	//向尾部增加
//不同于vector：
str.length()	//查询长度
str1 += str2; str1 += 'a';	//拼接
```

​	读入：

```c++
getline(cin, fullname);	//读一行
getline(cin, str, "#");	//到指定分割符“#”时停止读入
```

​	比较：字典序

​	转数值：

```c++
int a = stoi(str, 2); 	//读前两位
double e = stod("34.5")	  //e=34.5
```

·输入输出流

​	ostream（output stream）：STL库中所有输出流的**基类**

​	cout：STL中内建的一个 ostream **对象**

​	endl：流操纵算子，函数（输出 '/n' 再清除缓冲区）

​	scanf 的格式字符串可以在运行时确定，需要在运行期间解析

·文件输入输出流：

```c++
ifstream ifs("input.txt");	//打开文件
ifstream ifs("binary.bin", ifstream::binary);	//以二进制形式打开文件
ifs.open("file")	
//do something
ifs.close()
```

·正则表达式：

​	<regex> 库

​	原生字符串 R"(/d+)" == "//d+" == /d+

​	密码匹配：同时包含数字和字母

```bash
 ^(?=.\d+)(?=.*_+)(?=.*[A-Za-z]+)[\w]{6,16}$
```

作业：Homework6 problem_3

## L13-STL函数对象和智能指针

[ppt](L13-STL函数对象和智能指针.pptx)

函数对象
智能指针

·函数指针：
	例如 `void (*func) (int&); `
`std::function `类：
	统一函数指针和函数对象，来自`<functional>`
	

```c++
function<string()> readArr[] = { readFromScrean, readFromFile };
```

·智能指针
	shared_ptr：
		构造 

```c++
shared_ptr<int>p ( new int(1) ); 
auto p = make_shared<int>(1);
```

​		计数归零时，销毁对象
​	weak_ptr：
​		指向对象，但不计数，避免环状结构无法销毁内存
​	unique_ptr：
​		不能复制，能移动
​		可以放弃指针控制权，返回裸指针



## L14-行为型模式

·设计模式

- 行为型模式（Behavioral Patterns）
  关注对象行为功能上的抽象，旨在提升对象在行为功能上的可拓展性，以**最少的代码变动完成功能的增减**；
- 结构型模式（Structural Patterns）
  关注对象之间结构关系上的抽象，旨在提升对象结构的可维护性、代码健壮性，在**结构层面上解耦合**；
- 创建型模式（Creational Patterns）
  将对象创建与使用分离，旨在规避复杂对象创建带来的资源消耗，以**简短代码完成对象的高效创建**；

·行为型模式

- 模板方法（Template Method）模式
- 策略（Strategy）模式
- 迭代器（Iterator）模式
