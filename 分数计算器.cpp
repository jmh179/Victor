#include<iostream>
using namespace std;
class Fraction
{
	friend Fraction operator+(const Fraction& frac1, const Fraction& frac2); //����+�����
	friend Fraction operator-(const Fraction& frac1, const Fraction& frac2); //����-�����
	friend Fraction operator*(const Fraction& frac1, const Fraction& frac2); //����*�����
	friend Fraction operator/(const Fraction& frac1, const Fraction& frac2); //����/�����
	friend bool operator==(Fraction frac1, Fraction frac2);                  //����==�����
	friend bool operator>(const Fraction& frac1, const Fraction& frac2);     //����>�����
	friend bool operator<(const Fraction& frac1, const Fraction& frac2);     //����<�����
	friend ostream& operator<<(ostream& out, const Fraction& frac);          //����<<�����
	friend istream& operator>>(istream& in, Fraction& frac);                 //����>>�����
	friend void sortFraction();//�Է�����������
public:
	Fraction();                      //�޲ι��캯��
	Fraction(int n, int d);          //���ι��캯��
	Fraction(const Fraction& f);     //���ƹ��캯��
	void setFraction(int n, int d);  //���÷����ķ��Ӻͷ�ĸ
	int getNumer();                  //��ȡ�����ķ���
	int getDeno();                   //��ȡ�����ķ�ĸ
	void RdcFrc();                   //��ǰ����Լ��
private:
	int numer; //����
	int deno;  //��ĸ	
};
Fraction operator+(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.deno * frac2.deno;
	b = frac1.deno * frac2.numer + frac2.deno * frac1.numer;//û��д��С���������㷨��ֱ�ӷ�ĸ��ˣ���Ϊ���ҪԼ��
	return Fraction(b, a);
}//+������
Fraction operator-(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.deno * frac2.deno;
	b = frac2.deno * frac1.numer - frac1.deno * frac2.numer;
	return Fraction(b, a);
}//-������
Fraction operator*(const Fraction& frac1, const Fraction& frac2) {
	return Fraction(frac1.numer * frac2.numer, frac1.deno * frac2.deno);
}//*������
Fraction operator/(const Fraction& frac1, const Fraction& frac2) {
	return Fraction(frac1.numer * frac2.deno, frac1.deno * frac2.numer);//�������
}// /������
bool operator==(Fraction frac1, Fraction frac2) {
	frac1.RdcFrc(); frac2.RdcFrc();
	if ((frac1.numer == frac2.numer) && (frac1.deno == frac2.deno))
		return true;
	else
		return false;
}//==�����أ��ƺ��ò�����������
bool operator>(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.numer * frac2.deno;
	b = frac2.numer * frac1.deno;//�Խ����
	if (a > b)
		return true;
	else
		return false;
}//>������
bool operator<(const Fraction& frac1, const Fraction& frac2) {
	int a, b;
	a = frac1.numer * frac2.deno;
	b = frac2.numer * frac1.deno;
	if (a < b)
		return true;
	else
		return false;
}//<������
ostream& operator<<(ostream& out, const Fraction& frac) {
	out << frac.numer << "/" << frac.deno;
	return out;
}//<<�����أ����������Ķ���
istream& operator>>(istream& in, Fraction& frac) {
	char ch = ' ';
	int m, n;
		in >> m >> ch >> n;
if(ch=='/')
		frac.setFraction(m, n);
else
frac.setFraction(0, 0);
	return in;
}//>>�����أ����������Ķ���
Fraction::Fraction()
{

}//�ƺ��ò���������������Կհ�
Fraction::Fraction(int n, int d) {
	numer = n;
	deno = d;
}//���캯��
Fraction::Fraction(const Fraction& f) {
	numer = f.numer;
	deno = f.deno;
}//���ƹ��캯��
void Fraction::setFraction(int n, int d) {
	numer = n;
	deno = d;
}//���÷��ӷ�ĸ
int Fraction::getNumer() {
	return numer;
}//���ط��ӣ���Ϊ������ֻ��ͨ����Ա�������ʣ������������.˽�г�Ա�ķ�ʽ����
int Fraction::getDeno() {
	return deno;
}//���ط�ĸ
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
}//a�������Լ����Ҳ����շת�����
void Menu() {
	cout << "��ѡ���ܣ�����1����2����3����" << endl;
	cout << "1. ��������" << endl;
	cout << "2. ��������" << endl;
	cout << "3.�˳�����������" << endl;
}//��ʼҳ��Ĳ˵�
void fenshujisuan() {
	Fraction frac1, frac2, result;
	char index;
	cin >> frac1 >> index >> frac2;//�����������ʽ
	if (frac1.getDeno() == 0 || frac2.getDeno() == 0)//��ĸΪ���������
	{
		cout << "������ʽ�������" << endl;
		cin.clear();
		cin.ignore(1000, '\n');//����cin�ĺ�������Ҫ��������������������ռ䣬ԭ����������ѭ��
	}
	else if (index == '+')
	{
		result = frac1 + frac2;
		if (result.getDeno() != 0 && result.getNumer() != 0)//���ǵ�����Ľ������0��������ʾ��ĸΪ������,���¾���ͬ
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
	else if (index == '/' && frac2.getNumer() != 0)//�������⣬���ǵ�����������Ϊ��
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
	else //�����κ����������Ϊ����
	{
		cout << "������ʽ�������" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
	}
}
void sortFraction() {
	Fraction* p = new Fraction[10000];//����ѿռ䣬������̬�Ķ�������
	Fraction x, z;
	int y = 0;
	char _ch = '0';
	bool opt = true;
	while (cin >> x >> _ch)
	{
		p[y] = x;
		y++;
		if (_ch != ',')//ĩβ���ַ����Ƕ���ʱ����ѭ��
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
		}//ð������˫��ѭ��
		for (int i = 0; i < y; i++)
		{
			if (p[i].getDeno() == 0)//���Ƿ�ĸΪ��
			{
				opt = false;
				cout << "�������" << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				break;
			}
			if (opt)
				cout << p[i] << " ";
		}
		cout << endl;//�����Ҫ����
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
	}//ð������˫��ѭ��
	for (int i = 0; i < y; i++)
	{
		if (p[i].getDeno() == 0)//���Ƿ�ĸΪ��
		{
			opt = false;
			cout << "�������" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			break;
		}
		if (opt)
			cout << p[i] << " ";
	}
	cout << endl;//�����Ҫ����
}
else
{
	cout << "�������" << endl;
	cin.clear();
	cin.ignore(1000, '\n');
}
delete[]p;//�ͷŶѿռ�
}
int main()
{
	int a;
	char ch;
	while (1) {//����ѭ��
		Menu();//���ò˵�
		cin >> a;
		system("cls");//�����Ļ
		switch (a) {
		case 1:
			while (1) {
				cout << "�������������ʽ����1/2+1/3�س���������#�ż�������һ��Ŀ" << endl;
				cout << "¼��" << endl;
				if (cin >> ch && ch == '#')
				{
					system("cls");
					break;
				}
				else
					cin.unget();//��������ǳ���Ҫ�����������Ͳ�ƥ��ʱ��ʹ֮ǰ�������ú����cin�������룬���û�иú����������޷�Ӧ
				fenshujisuan();//���÷������㺯��
			}
			break;
		case 2:
			while (1) {
				cout << "������һ��������ö��Ÿ�����������С���������÷���<��β��" << endl;
				cout << "�ɴ�С�����÷���>��β��1/2��1/4��3/5<�س���������#�ż���" << endl;
				cout << "����һ��Ŀ¼��" << endl;
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