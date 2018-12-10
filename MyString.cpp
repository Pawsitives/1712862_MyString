#include "MyString.h"

char MyString::operator[](int i)
{
	if (Size <= i) throw 1;
	return String[i];
}

ostream& operator<<(ostream& os, MyString& str)
{
	if (str.Length() > 0)
	{
		for (int i = 0; i < str.Length(); i++)
			os << str[i];
	}
	else
		os << "";
	return os;
}

istream& operator>>(istream& is, MyString& str)
{
	char* s = new char[500];
	is >> s;
	str = MyString(s);
	delete[] s;
	return is;
}

MyString& MyString::operator=(MyString& str)
{
	if (this == &str) 
		return *this;
	delete[] String;
	Size = str.Length();
	String = new char[Size];
	for (int i = 0; i < Size; i++)
		String[i] = str[i];
	return *this;
}

MyString& MyString::operator+=(MyString& str)
{
	int Length = Size + str.Length();
	char* s = new char[Length];

	for (int i = 0; i < Size; i++)
		s[i]= String[i];

	for (int j = 0; j < str.Length(); j++)
		s[Size + j] = s[j];
	delete String;
	Size = Length;
	String = s;
	return *this;
}

MyString operator+(MyString& str1, MyString& str2)
{
	return str1 += str2;
}

bool operator==(MyString& str1, MyString& str2)
{
	if (str1.Length() != str2.Length()) 
		return false;
	int c = str1.Length();
	int n = 0;
	while ((n < c) && (str1[n] == str2[n])) 
		n++;
	return (n == c);
}

bool operator!= (MyString& str1, MyString& str2)
{
	return !(str1 == str2);
}

void MyString::Upper()
{
	for (int i = 0; i < String[i]; i++)
	if ('a' <= String[i] && String[i] <= 'z')
		String[i] -= 32;
}

void MyString::Lower()
{
	for (int i = 0; i < String[i]; i++)
	if ('A' <= String[i] && String[i] <= 'Z')
		String[i] += 32;
}

