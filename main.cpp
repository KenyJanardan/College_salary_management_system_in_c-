#include <iostream>
#include<conio.h>
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;
class teaching;
class non_teaching;
class individual
{
protected:
	string name;
	double salary;
	string dept;
	int years;
public:
	void boost()
	{
		salary = salary + 0.1 * salary;
	}
	void checkboost()
	{
		if (years == 10)
		{
			boost();
			cout << name << " received a boost" << endl;
			cout << "Salary:" << salary << endl;
		}
	}
	void operator++()
	{
		years++;
		cout << "Years Incremented:" << years << endl;
		checkboost();
	}
	virtual void setdept() {}
	virtual void putdata() {}
};
vector<teaching> t;
vector<non_teaching> n;
class teaching :public individual
{
	string subject;
public:
	teaching() {};
	teaching(string a, double b, int d, string e, string c)
	{
		name = a;
		salary = b;
		dept = c;
		years = d;
		subject = e;
	}

	void modifyteach()
	{
		int ch;
		cout << endl << "Modification Menu" << endl;
		cout << "1.update name" << endl;
		cout << "2.update salary" << endl;
		cout << "3.update years" << endl;
		cout << "4.update subject" << endl;
		cout << "5.update dept" << endl;
		cout << "Enter choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter name:";
			cin >> name;
			break;
		case 2:
			cout << "Enter new salary:";
			cin >> salary;
			break;
		case 3:
			cout << "Enter years:";
			cin >> years;
			break;
		case 4:
			cout << "Enter Subject:";
			cin >> subject;
			break;
		case 5:
			setdept();
			break;

		}
	}
	void setdept()
	{
		int no, f = 0;
		cout << endl;
		cout << "1.Computer" << endl;
		cout << "2.IT" << endl;
		cout << "3.Mechanical" << endl;
		do
		{
			cout << "Enter department:";
			cin >> no;
			switch (no)
			{
			case 1:
				dept = "Comp";
				f = 1;
				break;
			case 2:
				dept = "IT";
				f = 1;
				break;
			case 3:
				dept = "Mech";
				f = 1;
				break;
			default:
				cout << "Invalid input" << endl;

			}
		} while (f != 1);
	}
	void del_teach(int i)
	{
		t.erase(t.begin() + i);
	}
	void putdata()
	{
		cout << setw(10) << name << setw(10) << salary << setw(7) << years << setw(14) << dept << setw(16) << subject << endl;
	}
	void put_name()
	{
		cout << name << endl;
	}
};

class non_teaching :public individual
{

	string role;
public:
	non_teaching() {};
	non_teaching(string a, double b, int d, string e, string c)
	{
		name = a;
		salary = b;
		dept = c;
		years = d;
		role = e;
	}
	void modifynonteach()
	{
		int ch;
		cout << endl << "Modification Menu" << endl;
		cout << "1.update name" << endl;
		cout << "2.update salary" << endl;
		cout << "3.update years" << endl;
		cout << "4.update role" << endl;
		cout << "5.update dept" << endl;
		cout << "Enter choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Enter name:";
			cin >> name;
			break;
		case 2:
			cout << "Enter new salary:";
			cin >> salary;
			break;
		case 3:
			cout << "Enter years:";
			cin >> years;
			break;
		case 4:
			cout << "Enter Role:";
			cin >> role;
			break;
		case 5:
			setdept();
			break;

		}
	}
	void setdept()
	{

		int no, f = 0;
		cout << endl;
		cout << "1.Admin" << endl;
		cout << "2.Clean" << endl;
		cout << "3.Tech" << endl;
		do
		{
			cout << "Enter department:";
			cin >> no;
			switch (no)
			{
			case 1:
				dept = "Admin";
				f = 1;
				break;
			case 2:
				dept = "Clean";
				f = 1;
				break;
			case 3:
				dept = "Tech";
				f = 1;
				break;
			default:
				cout << "Invalid input" << endl;

			}
		} while (f != 1);

	}
	void del_nonteach(int i)
	{
		n.erase(n.begin() + i);
	}
	void putdata()
	{
		cout << setw(10) << name << setw(10) << salary << setw(7) << years << setw(14) << dept << setw(16) << role << endl;
	}
	void nonput_name()
	{
		cout << name << endl;
	}

};
void printemp()
{
	cout << "************************************************************" << endl;
	cout << setw(13) << "Name" << setw(10) << "Salary" << setw(7) << "Years" << setw(14) << "Department" << setw(16) << "Subject" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < t.size(); i++)
	{
		cout << setw(3) << i + 1;
		t[i].putdata();
	}
	cout << "************************************************************" << endl;
}
void printstaff()
{
	cout << "************************************************************" << endl;
	cout << setw(13) << "Name" << setw(10) << "Salary" << setw(7) << "Years" << setw(14) << "Department" << setw(16) << "Role" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int i = 0; i < n.size(); i++)
	{
		cout << setw(3) << i + 1;
		n[i].putdata();
	}
	cout << "************************************************************" << endl;
}
void add_teach()
{
	string name, subject;
	int years, size = t.size();
	double salary;
	cout << "Enter name:";
	cin >> name;
	cout << "Enter salary:";
	cin >> salary;
	cout << "Enter years:";
	cin >> years;
	cout << "Enter Subject:";
	cin >> subject;
	t.push_back(teaching(name, salary, years, subject, "NULL"));
	t[size].setdept();
}
void add_nonteach()
{
	string name, role;
	int years, size = n.size();
	double salary;
	cout << "Enter name:";
	cin >> name;
	cout << "Enter salary:";
	cin >> salary;
	cout << "Enter years:";
	cin >> years;
	cout << "Enter Role:";
	cin >> role;
	n.push_back(non_teaching(name, salary, years, role, "NULL"));
	n[size].setdept();
}
void teachmenu()
{
	int ch, val;
	do
	{
		cout << endl << "*********Teaching Menu*********" << endl;
		cout << "1.add employee" << endl;
		cout << "2.remove employee" << endl;
		cout << "3.modify employee" << endl;
		cout << "4.Increment years of employee" << endl;
		cout << "5.Print all employees" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			add_teach();
			ch = 3;
			break;
		case 2:
			printemp();
			cout << "Enter Number of employee to be Deleted:";
			cin >> val;
			cout << "Removed:";
			t[val - 1].put_name();
			t[val - 1].del_teach(val - 1);
			ch = 6;
			break;
		case 3:
			printemp();
			cout << "Enter Number of employee to be modified:";
			cin >> val;
			t[val - 1].modifyteach();
			ch = 6;
			break;
		case 4:
			printemp();
			cout << "Enter Number of employee to be incremented:";
			cin >> val;
			++t[val - 1];
			ch = 6;
			break;
		case 5:
			printemp();
			ch = 6;
			break;
		case 6:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (ch != 6);
	_getch();
}
void nonteachmenu()
{
	int ch, val;
	do
	{
		cout << endl << "*******Non-Teaching Menu*******" << endl;
		cout << "1.add employee" << endl;
		cout << "2.remove employee" << endl;
		cout << "3.modify employee" << endl;
		cout << "4.Increment years of employee" << endl;
		cout << "5.Print all employees" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			add_nonteach();
			ch = 3;
			break;
		case 2:
			printstaff();
			cout << "Enter Number of employee to be Deleted:";
			cin >> val;
			cout << "Removed:";
			n[val - 1].nonput_name();
			n[val - 1].del_nonteach(val - 1);
			ch = 6;
			break;
		case 3:
			printstaff();
			cout << "Enter Number of employee to be modified:";
			cin >> val;
			n[val - 1].modifynonteach();
			ch = 6;
			break;
		case 4:
			printstaff();
			cout << "Enter Number of employee to be incremented:";
			cin >> val;
			++n[val - 1];
			ch = 6;
			break;
		case 5:
			printstaff();
			ch = 6;
			break;
		case 6:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (ch != 6);
	_getch();
}
int main()
{
	ifstream fin1, fin2, fin3, fin4, fin5;
	fin1.open("nameteach.txt");
	fin2.open("Salaryt.txt");
	fin3.open("Yearst.txt");
	fin4.open("Subject.txt");
	fin5.open("deptt.txt");
	char name[10];
	double sal;
	char sub[15];
	char dept[10];
	int y;
	for (int i = 0; i < 15; i++)
	{
		fin1.getline(name, 10);
		fin2 >> sal;
		fin5.getline(dept, 10);
		fin3 >> y;
		fin4.getline(sub, 15);
		t.push_back(teaching(name, sal, y, sub, dept));
	}
	fin1.close();
	fin2.close();
	fin3.close();
	fin4.close();
	fin5.close();

	ifstream fin6, fin7, fin8, fin9, fin0;
	fin6.open("namenonteach.txt");
	fin7.open("Salaryn.txt");
	fin8.open("Yearsn.txt");
	fin9.open("Role.txt");
	fin0.open("deptn.txt");
	char name1[10];
	double sal1;
	char rol[15];
	char dept1[10];
	int y1;

	for (int i = 0; i < 15; i++)
	{
		fin6.getline(name1, 10);

		fin7 >> sal1;
		fin0.getline(dept1, 10);
		fin8 >> y1;
		fin9.getline(rol, 15);
		n.push_back(non_teaching(name1, sal1, y1, rol, dept1));
	}
	fin6.close();
	fin7.close();
	fin8.close();
	fin9.close();
	fin0.close();

	int ch;
	do
	{
		cout << endl << "************MAIN MENU**********" << endl;
		cout << "1.Teaching menu" << endl;
		cout << "2.Non teaching menu" << endl;
		cout << "3.exit" << endl;
		cout << "Enter choice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			teachmenu();

			break;
		case 2:
			nonteachmenu();
			break;
		case 3:

			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (ch != 3);

	_getch();
}