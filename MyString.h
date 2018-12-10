#pragma once

#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include<iostream>

using namespace std;

class MyString
{
private:
	char* String;
	int Size;
	
public:
	//Hàm tạo / hủy
	MyString()
	{
		String = new char[0];
		Size = 0;
	}

	~MyString()
	{
		delete[] String;
	}

	MyString(char* s)
	{
		if (s)
		{
			int n = 0;
			while (s[n] != NULL)
			{
				n++;
				Size = n;
				String = new char[n];
				for (int i = 0; i < n; i++)
				{
					String[i] = s[i];
				}
			}
		}
	}

	//Tính độ dài
	int Length()
	{
		return Size;
	}

	//Hàm sao chép
	MyString(MyString& str)
	{
		Size = str.Length();
		String = new char[Size];
		for (int i = 0; i < Size; i++)
			String[i] = str.String[i];
	}

	//Truy cập string
	char operator[](int i);

	//Hàm nhập xuất
	friend ostream& operator<<(ostream& os, MyString& s);  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	friend istream& operator>>(istream& is, MyString& s);

	MyString& operator=(MyString& str);

	//Hàm nối
	MyString& operator+=(MyString& s);
	friend MyString operator+(MyString& str1, MyString& str2);

	//Hàm so sánh
	friend bool operator==(MyString& str1, MyString& str2);
	friend bool operator!=(MyString& str1, MyString& str2);

	//In hoa, in thường
	void Upper();
	void Lower();
};

#endif