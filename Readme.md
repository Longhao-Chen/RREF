# RREF
将矩阵化简为简化阶梯型，并使用`Latex`输出化简过程。此程序的目的是练习`C++`和项目维护。

* 目前只实现整数运算

# 编译和运行
* 编译器需要支持c++20标准
* 需要依赖`libunwind-dev`
* 目前只支持`X86_64`

直接在源代码目录下执行
```
make
```
会自动编译并运行程序，编译出来的可执行文件为`app`

## 清理中间文件
```
make clean
```

## 测试例子
输入:
```
4 5
2 3 -1 -5 -2
1 2 -1 1 -2
1 1 1 1 5
3 1 2 3 4
```

输出:
```
\left[\begin{matrix}2 & 3 & -1 & -5 & -2 \\ 1 & 2 & -1 & 1 & -2 \\ 1 & 1 & 1 & 1 & 5 \\ 3 & 1 & 2 & 3 & 4 \end{matrix}\right]\\
\underset{\longrightarrow}{ 1\leftrightarrow 2}
\left[\begin{matrix}1 & 2 & -1 & 1 & -2 \\ 2 & 3 & -1 & -5 & -2 \\ 1 & 1 & 1 & 1 & 5 \\ 3 & 1 & 2 & 3 & 4 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{2} -2 r_{1}}
\left[\begin{matrix}1 & 2 & -1 & 1 & -2 \\ 0 & -1 & 1 & -7 & 2 \\ 1 & 1 & 1 & 1 & 5 \\ 3 & 1 & 2 & 3 & 4 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{3} - r_{1}}
\left[\begin{matrix}1 & 2 & -1 & 1 & -2 \\ 0 & -1 & 1 & -7 & 2 \\ 0 & -1 & 2 & 0 & 7 \\ 3 & 1 & 2 & 3 & 4 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{4} -3 r_{1}}
\left[\begin{matrix}1 & 2 & -1 & 1 & -2 \\ 0 & -1 & 1 & -7 & 2 \\ 0 & -1 & 2 & 0 & 7 \\ 0 & -5 & 5 & 0 & 10 \end{matrix}\right]\\
\underset{\longrightarrow}{ - r_{2}}
\left[\begin{matrix}1 & 2 & -1 & 1 & -2 \\ 0 & 1 & -1 & 7 & -2 \\ 0 & -1 & 2 & 0 & 7 \\ 0 & -5 & 5 & 0 & 10 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{1} -2 r_{2}}
\left[\begin{matrix}1 & 0 & 1 & -13 & 2 \\ 0 & 1 & -1 & 7 & -2 \\ 0 & -1 & 2 & 0 & 7 \\ 0 & -5 & 5 & 0 & 10 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{3}+ r_{2}}
\left[\begin{matrix}1 & 0 & 1 & -13 & 2 \\ 0 & 1 & -1 & 7 & -2 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & -5 & 5 & 0 & 10 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{4}+ 5 r_{2}}
\left[\begin{matrix}1 & 0 & 1 & -13 & 2 \\ 0 & 1 & -1 & 7 & -2 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & 0 & 0 & 35 & 0 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{1} - r_{3}}
\left[\begin{matrix}1 & 0 & 0 & -20 & -3 \\ 0 & 1 & -1 & 7 & -2 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & 0 & 0 & 35 & 0 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{2}+ r_{3}}
\left[\begin{matrix}1 & 0 & 0 & -20 & -3 \\ 0 & 1 & 0 & 14 & 3 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & 0 & 0 & 35 & 0 \end{matrix}\right]\\
\underset{\longrightarrow}{ \frac{1}{35} r_{4}}
\left[\begin{matrix}1 & 0 & 0 & -20 & -3 \\ 0 & 1 & 0 & 14 & 3 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & 0 & 0 & 1 & 0 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{1}+ 20 r_{4}}
\left[\begin{matrix}1 & 0 & 0 & 0 & -3 \\ 0 & 1 & 0 & 14 & 3 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & 0 & 0 & 1 & 0 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{2} -14 r_{4}}
\left[\begin{matrix}1 & 0 & 0 & 0 & -3 \\ 0 & 1 & 0 & 0 & 3 \\ 0 & 0 & 1 & 7 & 5 \\ 0 & 0 & 0 & 1 & 0 \end{matrix}\right]\\
\underset{\longrightarrow}{ r_{3} -7 r_{4}}
\left[\begin{matrix}1 & 0 & 0 & 0 & -3 \\ 0 & 1 & 0 & 0 & 3 \\ 0 & 0 & 1 & 0 & 5 \\ 0 & 0 & 0 & 1 & 0 \end{matrix}\right]\\
```
# 设计文档
## 项目架构
目前，该项目自底而上分为三层：基本数据结构层、矩阵数据结构层、算法层。
每两层之间通过一系列接口来进行通信和调用，这些接口一般情况下将保持稳定。
### 基本数据结构层
目前已实现的类型有：整数
该层提供的接口有：
```
// 构造函数：
dataType::T()
dataType::T(具体数据类型)

// 具体方法
int T.get_k(T1) // 返回T整除T1的值
std::string T.toString() // 将该类型转换为可显示字符
T T.get_abs() // 返回T的绝对值

// 下面的是两个数据之间的运算
T operator+(T)
T operator-(T)
T operator*(int)
T operator*(T)
T operator/(T)
T operator/(int)
T operator%(T)

T operator-() // 取负

void operator=(T) // 赋值
bool operator==(T) // 判断是否相等
bool operator==(int)
bool operator>(T) //判断是否大于
bool operator>(int)

// 数据的输入输出
std::istream &operator>>(std::istream &in, T);
std::ostream &operator<<(std::ostream &out, T);
```

### 矩阵数据结构层
该层提供的接口有：

* 注意：矩阵下标从0开始
```
// 构造函数
dataType::Matrix(行, 列)

void Matrix.set(T t, int r, int c) // 将rc元素赋值为t
T Matrix.get(int r, int c) // 返回rc元素

// 获取矩阵的行或列
int Matrix.getRow()
int Matrix.getCol()

// 下面是对行的操作
latexOutput::swap swap(int r1, int r2); // 交换r1 r2

latexOutput::rowSum rowSum(int k, int r1, int r2); // r1加上r2乘k
latexOutput::rowSum rowSum(T k, int r1, int r2);

latexOutput::rowMul rowMul(int k, int r); // r乘k
latexOutput::rowMul rowMul(T k, int r);

latexOutput::rowDiv rowDiv(int k, int r); // r除以k
latexOutput::rowDiv rowDiv(T k, int r);

// 数据的输入输出
std::istream &operator>>(std::istream &in, dataType::Matrix<T> &t);
std::ostream &operator<<(std::ostream &out, const dataType::Matrix<T> &t);
latexOutput::log &operator<<(latexOutput::log &out, const dataType::Matrix<T> &t);
```

### 算法层
目前提供的接口有：
```
// 将data化简到简化阶梯型
latexOutput::log RREF(dataType::Matrix<T> &data)
```

## 对于模板的处理
因为模板需要在编译时展开，由此无法像一般的`C++`代码那样对每一个文件单独编译再链接。但我有不想把声明和定义写在一起，所以在本项目中采取了如下方案：
先将声明写在头文件中，定义写在另外的文件中，然后再在头文件中使用`include`包含写定义的那个文件。这样既可以使用模板，又不会出现声明和定义写在一个文件而看上去不爽。
