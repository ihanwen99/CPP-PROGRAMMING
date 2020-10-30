# OJ Contest 9

训练题目内容对应书上第十章。

---

### 1. 复数类

> 定义并实现复数类`Complex`，实部和虚部都是`int`，包含`add`和`display`

```C++
class Complex {
	int real;
	int viru;
public:
	Complex(int r = 0, int v = 0) :real(r), viru(v) {};
	void add(const Complex& a, const Complex& b);
	void display();
};
```

### 2. 时间类

> 定义并实现时间类Time，能够提供和设置由时分秒组成的时间，能够增加时间（以秒数增加），能够以24小时的形式显示时间，不需要检查输入合法性。

1. 使用了初始化列表
2. 尽可能想着使用 this 指针明确表示

```c++
class Time {
	int h, m, s;
public:
	Time(int hh, int mm, int ss) :h(hh), m(mm), s(ss) {};
	void settime(int hh, int mm, int ss) { this->h = hh; this->m = mm; this->s = ss; }
	void display();
	void add(int seconds);
};
```

### 3. Circle类

> 定义圆的类Circle，包含三个属性：圆心(x,y)和半径r，成员函数见main函数。

**引用传值 ！！！**

传入的是 &x，在函数体里面使用 x=this.x

```cpp
class Circle {
	int x;
	int y;
	int r;
public:
	Circle(int xx, int yy, int rr) :x(xx), y(yy), r(rr) {};
	void getO(int& cx, int& cy) { cx = this->x; cy = this->y; }
	int getR() { return this->r; }
	void move(int mx, int my) { this->x += mx; this->y += my; }
	void setR(int rr) { this->r = rr; }
};
```

### 4. LongLongInt类

> 任意大的正整数类

```cpp
#include<deque>
#include<string>
class LongLongInt {
private:
	char* num;
public:
	LongLongInt(char* num) {
		this->num = num;
	};

	LongLongInt(const LongLongInt& lli) {
		int length = strlen(lli.num);
		this->num = new char[length + 1];
		for (int i = 0; i < length; i++) { this->num[i] = lli.num[i]; }
		this->num[length] = '\0';
	};

	void display() {
		cout << num << endl;
	};

	LongLongInt add(LongLongInt b) {
		int lengtha = strlen(this->num);
		int lengthb = strlen(b.num);
		deque<char>tmp;
		if (lengtha > lengthb) {
			tmp = addNum(this->num, lengtha, b.num, lengthb);
		}
		else { tmp = addNum(b.num, lengthb, this->num, lengtha); }

		int length = tmp.size();
		char* address = new char[length + 1];
		for (int i = 0; i < length; i++) { address[i] = tmp[i]; }
		address[length] = '\0';
		LongLongInt result(address);
		return result;
	}

	deque<char> addNum(char* a, int la, char* b, int lb) {
		deque<char> tmp;
		int carry = 0;
		int  value;
		while(lb>=1) {
			value = *(a + la - 1) + *(b + lb - 1) - '0' - '0' + carry;
			carry = value / 10;
			tmp.push_front(value % 10 + '0');
			la--; lb--;
		}
		while(la>=1){
			value = *(a + la - 1) - '0' + carry;
			carry = value / 10;
			tmp.push_front(value % 10 + '0');
			la--;
		}
		if (carry == 1) { tmp.push_front('1'); }
		return tmp;
	}
};
```

### 5. 约瑟夫环类

> 设计并实现一个解决约瑟夫环问题的类`Josephus`。
>
> 当需要解决`n`个人、**周期**为`m`的约瑟夫环问题时，可以构建一个对象`Josephus obj(n, m)`，然后调用`obj.simulate()`输出模拟删除过程。
>
> 约瑟夫环中人的编号依次是`1, 2, ..., n`。环上的报数从`2`开始，依次删除第`m`个报数的人、第`2m`个报数的人、第`3m`个报数的人， .... ，直到删除所有的人。

我的删除过程是使用 `vector`，`STL` 的使用让我在这些操作上异常省事：

因为题目中给的是 **周期** ，也就是说给定的是 **间隔** ：

- 找到的第一个元素，需要数 n 个
- 之后找到的元素，只需要再数 n-1 个（因为原地删除之后，idx 虽然没变，但是相当于已经移动了

```c++
#include<vector>
class Josephus {
	int n, m;
	vector<int> people;
public:
	Josephus(int nn, int mm) :n(nn), m(mm) {
		for (int i = 1; i <= nn; i++) { people.push_back(i); }
	}

	void simulate() {
		int pos = 0;
		pos = (pos + this->m) % people.size();
		cout << people[pos] << endl;
		people.erase(people.begin() + pos);

		while (!people.empty()) {
			pos = (pos + this->m-1) % people.size();
			cout << people[pos] << endl;
			people.erase(people.begin() + pos);
		}
	}
};
```

### 6. 动态有序整数数组类

> 实现一个动态有序整数数组类，能够加入整数，根据需要扩展容量，输出第 n（index 为 n，从 0 开始）小的数，按序输出数组中所有数据。

使用 `vector`，对于本题目中要求的排序就可以直接秒啦。

```c++
#include<vector>
#include<algorithm>
class orderArray {
private:
    vector<int> tmp;
public:
    /**
     * @param n: initial size of orderArray
     */
    orderArray(int n) {};

    /**
     * Add a number to the array.
     */
    void add(int x) {
        tmp.push_back(x);
    };

    /**
     * Return the ith smallest element.
     */
    int findnum(int i) {
        sortInClass();
        return tmp[i];
    };

    /**
     * Print all elements in ascending order.
     */
    void show() {
        sortInClass();
        int length = tmp.size();
        for (int i = 0; i < length-1; ++i) {
            cout << tmp[i] << ' ';
        }
        cout << tmp[length - 1] << endl;
    };

    void sortInClass() {
        sort(tmp.begin(), tmp.end());
    }
};

```

### 7. 账户类

> 定义账户类 SavingAccount，包含账号，存入日期，存款金额和月利率。
>
> 要求账号自动生成，第一个生成的对象账号为1，第二个生成的对象账号为2，依此类推。
>
> 所需的操作包括修改月利率，每月计算新的存款额（原金额加上本月利息）和显示账户金额。
>
> 不得使用全局变量。月利率初始值为0.05。

主要是想强调 **静态变量** 和 **保留两位小数** 的操作：

- 静态变量 - 计数！

- 保留两位小数

  `cout << fixed << showpoint << setprecision(2)<< money << endl; `

```cpp
#include<iomanip>
class SavingAccount {
	double money;
	int id;
	double rate = 0.05;
	static int count;

public:
	SavingAccount(int money) :money(money) { id = ++count; };
	void display() { cout << id << ' '  << fixed << showpoint << setprecision(2)<< money << ' ' << rate << endl; }
	void calculate() { money *= (1 + rate); }
	void changerate(double new_rate) { rate = new_rate; }
};

int SavingAccount::count = 0;
```

