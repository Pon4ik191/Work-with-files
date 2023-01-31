#include "Functions.h" 

int _stateMenu;

void Menu()
{
	cout << "Select an action:" << endl;
	cout << "(0) Program exit:" << endl;
	cout << "(1) Data input:" << endl;
	cout << "(2) Data output:" << endl;
	cout << "(3) Change data:" << endl;
	cout << "(4) Delete data:" << endl;
	cout << "(5) Add data:" << endl;
	cout << "(6) Save data:" << endl;
	cout << "Your choice: " << endl;

	cin >> _stateMenu;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	DataInitialization();

	Menu();

	int _actions;
	string fileName;

	while (_stateMenu != 0)
	{
		switch(_stateMenu)
		{
		case 1:
			system("cls"); // clearing the console 

			cout << "Input manually or from a file?" << endl;
			cin >> _actions;

			system("cls"); // clearing the console 

			if (_actions == 1)
			{
				// manual entry
				DataEntry();
			}
			else
			{
				cout << "Enter file name: " << endl;
				cin >> fileName;

				DataReading(fileName);
			}

			system("pause"); // console latency 
			system("cls"); // clearing the console 
			Menu();
			break;

		case 2:
			system("cls");

			Print();

			system("pause");
			system("cls");
			Menu();
			break;

		case 3:
			system("cls");

			DataChange();

			system("pause");
			system("cls");
			Menu();
			break;

		case 4:
			system("cls");

			DeleteData();

			system("pause");
			system("cls");
			Menu();
			break;

		case 5:
			system("cls");

			AddData();

			system("pause");
			system("cls");
			Menu();
			break;

		case 6:
			system("cls");

			cout << "Enter file name: " << endl;
			cin >> fileName;

			SaveData(fileName);

			system("pause");
			system("cls");
			Menu();
			break;

		default:
			cout << "Wrong menu item selected!" << endl;
			break;
		}
		
	}

	system("cls");
	if (DataCleaning())
	{
		cout << "Data cleared!" << endl;
	}
	else
	{
		cout << "The data is NOT cleared!" << endl;
	}

	cout << "Work completed." << endl;
	system("pause");

	return 0;
}