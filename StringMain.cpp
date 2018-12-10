#include "MyString.h"

void main()
{
	int menu, count = 0, n = 0;
	MyString *str;
VONGLAP:
	{
		cout << "\t======================== STRING SAMPLE =========================\n";
		cout << "\n\t    1. Tao string. ( In hoa va in thuong )";
		cout << "\n\t    2. So sanh hai string bat ky.";
		cout << "\n\t    3. Thoat";
		cout << "\n\n\t================================================================\n\n";
		cout << "Chon: ";
		cin >> menu;
		count++;
		if (menu<1 || menu>7) exit(0);
	}

	system("cls");

	switch (menu)
	{
	case 1:
		cout << "Ban muon nhap bao nhieu tu? || Vi du: Toi la ABC.   Gom co 3 tu.\n";
		cin >> n;
		str = new MyString[n+1];
		for (int i = 0; i < n; i++)
		{
			cout << "String " << i + 1 << " = ";
			cin >> str[i];
		}
		cout << "\nString hoan chinh: ";
		for (int i = 0; i < n; i++)
		{
			cout << str[i] << " ";
		}
		cout << "\n\n";
		cout << "\nString in hoa: ";
		for (int i = 0; i < n; i++)
		{
			str[i].Upper();
			cout << str[i] << " ";
		}
		cout << "\n\n";
		cout << "\nString in thuong: ";
		for (int i = 0; i < n; i++)
		{
			str[i].Lower();
			cout << str[i] << " ";
		}
		cout << "\n\n";
		system("pause");
		system("cls");
		goto VONGLAP;

	case 2:
		MyString str1, str2;
		cout << "String 1: ";
		cin >> str1;
		cout << "\n\nString 2: ";
		cin >> str2;
		cout << "\nSo sanh String 1 va String 2.\n\n=> ";
		cout << ((str1 == str2) ? "String 1 = String 2" : "String 1 != String 2");
		cout << "\n\n";
		system("pause");
	}
	
}