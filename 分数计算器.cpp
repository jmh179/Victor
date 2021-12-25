#include<iostream>
using namespace std;
class Fraction
{
	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //重载+运算符
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //重载-运算符
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //重载*运算符
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //重载/运算符
	friend bool operator==(Fraction frac1, Fraction frac2);                  //重载==运算符
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //重载>运算符
	friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //重载<运算符
	friend ostream& operator<<(ostream& out, const Fraction& frac);          //重载<<运算符
	friend istream& operator>>(istream& in, Fraction& frac);                 //重载>>运算符
	friend void sortFraction();//对分数数组排序
public:
	Fraction();                      //无参构造函数
	Fraction(int n, int d);          //带参构造函数
	Fraction(const Fraction& f);     //复制构造函数
	void setFraction(int n, int d);  //设置分数的分子和分母
	int getNumer();                  //获取分数的分子
	int getDeno();                   //获取分数的分母
	void RdcFrc();                   //当前分数约分
private:
	int numer; //分子
	int deno;  //分母	
};
Fraction operator+(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.deno * frac2.deno;
	b = frac1.deno * frac2.numer + frac2.deno * frac1.numer;//没有写最小公倍数的算法，直接分母相乘，因为最后都要约分
	return Fraction(b, a);
}//+的重载
Fraction operator-(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.deno * frac2.deno;
	b = frac2.deno * frac1.numer - frac1.deno * frac2.numer;
	return Fraction(b, a);
}//-的重载
Fraction operator*(const Fraction& frac1, const Fraction& frac2) {
	return Fraction(frac1.numer * frac2.numer, frac1.deno * frac2.deno);
}//*的重载
Fraction operator/(const Fraction& frac1, const Fraction& frac2) {
	return Fraction(frac1.numer * frac2.deno, frac1.deno * frac2.numer);//倒序相乘
}// /的重载
bool operator==(Fraction frac1, Fraction frac2) {
	frac1.RdcFrc(); frac2.RdcFrc();
	if ((frac1.numer == frac2.numer) && (frac1.deno == frac2.deno))
		return true;
	else
		return false;
}//==的重载，似乎用不到这个运算符
bool operator>(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.numer * frac2.deno;
	b = frac2.numer * frac1.deno;//对角相乘
	if (a > b)
		return true;
	else
		return false;
}//>的重载
bool operator<(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.numer * frac2.deno;
	b = frac2.numer * frac1.deno;
	if (a < b)
		return true;
	else
		return false;
}//<的重载
ostream& operator<<(ostream& out, const Fraction& frac) {
	out << frac.numer << "/" << frac.deno;
	return out;
}//<<的重载，输出分数类的对象
istream& operator>>(istream& in, Fraction& frac) {
	char ch = ' ';
	int m, n;
		in >> m >> ch >> n;
if(ch=='/')
		frac.setFraction(m, n);
else
frac.setFraction(0, 0);
	return in;
}//>>的重载，输入分数类的对象
Fraction::Fraction()
{

}//似乎用不到这个函数，所以空白
Fraction::Fraction(int n, int d) {
	numer = n;
	deno = d;
}//构造函数
Fraction::Fraction(const Fraction& f) {
	numer = f.numer;
	deno = f.deno;
}//复制构造函数
void Fraction::setFraction(int n, int d) {
	numer = n;
	deno = d;
}//设置分子分母
int Fraction::getNumer() {
	return numer;
}//返回分子，因为在类外只能通过成员函数访问，不能以类对象.私有成员的方式访问
int Fraction::getDeno() {
	return deno;
}//返回分母
void Fraction::RdcFrc() {
	int a;
	a = (numer < deno) ? numer : deno;
	while (a > 1)
	{
		if (numer % a == 0 && deno % a == 0)break;
		a--;
	}
	numer /= a;
	deno /= a;
}//a就是最大公约数，也可用辗转相除法
void Menu() {
	cout << "请选择功能（键入1或者2或者3）：" << endl;
	cout << "1. 分数计算" << endl;
	cout << "2. 分数排序" << endl;
	cout << "3.退出分数计算器" << endl;
}//初始页面的菜单
void fenshujisuan() {
	Fraction frac1, frac2, result;
	char index;
	cin >> frac1 >> index >> frac2;//输入分数计算式
	if (frac1.getDeno() == 0 || frac2.getDeno() == 0)//分母为零输出错误
	{
		cout << "分数算式输入错误！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');//两个cin的函数很重要，如果不用它们清除缓存空间，原函数将无限循环
	}
	else if (index == '+')
	{
		result = frac1 + frac2;
		if (result.getDeno() != 0 && result.getNumer() != 0)//考虑到输出的结果出现0，但是显示分母为零的情况,以下均相同
		{
			result.RdcFrc();
			cout << result << endl;
		}
		else
			cout << 0 << endl;
	}
	else if (index == '-')
	{
		result = frac1 - frac2;
		if (result.getDeno() != 0 && result.getNumer() != 0)
		{
			result.RdcFrc();
			cout << result << endl;
		}
		else
			cout << 0 << endl;
	}
	else if (index == '*')
	{
		result = frac1 * frac2;
		if (result.getDeno() != 0 && result.getNumer() != 0)
		{
			result.RdcFrc();
			cout << result << endl;
		}
		else
			cout << 0 << endl;
	}
	else if (index == '/' && frac2.getNumer() != 0)//除法特殊，考虑到被除数不能为零
	{
		result = frac1 / frac2;
		if (result.getDeno() != 0 && result.getNumer() != 0)
		{
			result.RdcFrc();
			cout << result << endl;
		}
		else
			cout << 0 << endl;
	}
	else //其余任何情况均被视为错误
	{
		cout << "分数算式输入错误！" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
}
void sortFraction() {
	Fraction* p = new Fraction[10000];//申请堆空间，创建动态的对象数组
	Fraction x, z;
	int y = 0;
	char _ch = '0';
	bool opt = true;
	while (cin >> x >> _ch)
	{
		p[y] = x;
		y++;
		if (_ch != ',')//末尾的字符不是逗号时跳出循环
			break;
		else
			continue;
	}
	if (_ch == '<')
	{
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < y - 1; j++)
			{
				if (p[j] > p[j + 1])
				{
					z = p[j];
					p[j] = p[j + 1];
					p[j + 1] = z;
				}
			}
		}//冒泡排序，双层循环
		for (int i = 0; i < y; i++)
		{
			if (p[i].getDeno() == 0)//考虑分母为零
			{
				opt = false;
				cout << "输入错误！" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
			if (opt)
				cout << p[i] << " ";
		}
		cout << endl;//最后需要换行
	}
 else if (_ch == '>')
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < y - 1; j++)
		{
			if (p[j] < p[j + 1])
			{
				z = p[j];
				p[j] = p[j + 1];
				p[j + 1] = z;
			}
		}
	}//冒泡排序，双层循环
	for (int i = 0; i < y; i++)
	{
		if (p[i].getDeno() == 0)//考虑分母为零
		{
			opt = false;
			cout << "输入错误！" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			break;
		}
		if (opt)
			cout << p[i] << " ";
	}
	cout << endl;//最后需要换行
}
else
{
	cout << "输入错误！" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}
delete[]p;//释放堆空间
}
int main()
{
	int a;
	char ch;
	while (1) {//外层的循环
		Menu();//调用菜单
		cin >> a;
		system("cls");//清除屏幕
		switch (a) {
		case 1:
			while (1) {
				cout << "请输入分数计算式（如1/2+1/3回车），输入#号键返回上一层目" << endl;
				cout << "录：" << endl;
				if (cin >> ch && ch == '#')
				{
					system("cls");
					break;
				}
				else
					cin.unget();//这个函数非常重要，当输入类型不匹配时，使之前的输入用后面的cin继续输入，如果没有该函数，程序无反应
				fenshujisuan();//调用分数计算函数
			}
			break;
		case 2:
			while (1) {
				cout << "请输入一组分数，用逗号隔开，如需由小到大排序用符号<结尾，" << endl;
				cout << "由大到小排序用符号>结尾（1/2，1/4，3/5<回车），输入#号键返" << endl;
				cout << "回上一层目录：" << endl;
				if (cin >> ch && ch == '#')
				{
					system("cls");
					break;
				}
				else
					cin.unget();
				sortFraction();
			}
			break;
		case 3:
			return 0;
		}
	}
	return 0;
}