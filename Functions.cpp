#include "Functions.h"

void DataInitialization()
{
	// Let's create a temporary file that will store the actual information. Let's create a buffer

	ofstream _buf("Buffer.txt");

	if(!_buf)
	{
		cout << "Error creating spool file!" << endl;
	}

	_buf.close(); 
}

void DataEntry()
{
	// manual data entry

	// temporary variables
	string _surname;
	int _phoneNum;
	string _city;
	int n;

	cout << "Enter the amount of data: " << endl;
	cin >> n;

	// open buffer file and write data to it
	ofstream record("Buffer.txt", ios::app);

	if (record)
	{
		record << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Enter data ¹1 (Last name): " << endl;
			cin >> _surname;

			cout << "Enter data ¹2 (Phone number):" << endl;
			cin >> _phoneNum;

			cout << "Enter data ¹3 (City):" << endl;
			cin >> _city;

			record << _surname << endl;
			record << _phoneNum << endl;

			if (i < n - 1)
			{
				record << _city << endl;
			}
			else
			{
				record << _city;
			}

			cout << "___________________________" << endl;
		}
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	record.close();
}

void DataReading(string fileName)
{
	// reading data from a file

	ifstream reading(fileName);
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				reading >> _phoneNum;
				reading >> _city;

				record << _surname << endl;
				record << _phoneNum << endl;

				if (i < n - 1)
				{
					record << _city << endl;
				}
				else
				{
					record << _city;
				}

			}

			cout << "Data read!" << endl;
			
		}
		else
		{
			cout << "Buffer opening error!" << endl;
		}
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	// closing a file
	reading.close();
	record.close();
}

void Print()
{
	ifstream reading("Buffer.txt");

	if (reading)
	{
		string _surname;
		int _phoneNum;
		string _city;
		int n;

		reading >> n;
		cout << "Number of data: " << n << endl;

		for (int i = 0; i < n; i++)
		{
			cout << "Data on ¹" << i + 1 << endl;

			reading >> _surname;
			cout << "Data ¹1 (Last name): " << _surname << endl;

			reading >> _phoneNum;
			cout << "Data ¹2 (Phone number): " << _phoneNum << endl;

			reading >> _city;
			cout << "Data ¹3 (City): " << _city << endl;

			cout << "_____________________________________________________" << endl;
		}
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	reading.close();
}

void DataChange()
{
	// data change

	// save the data again
	// clear the buffer and start writing data to it again
	// get to the required and change its data

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			reading >> n;

			cout << "Select the number of the element to change (from 1 to " << n << "): " << endl;
			cin >> _n;
			_n--;

			system("cls");
			
			record << n << endl;

			if (_n >= 0 && _n < n)
			{
				for(int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
						{
							record << _city << endl;
						}
						else
						{
							record << _city;
						}
					}
					else
					{
						cout << "Enter data ¹1 (Last name): " << endl;
						cin >> _surname;

						cout << "Enter data ¹2 (Phone number):" << endl;
						cin >> _phoneNum;

						cout << "Enter data ¹3 (City):" << endl;
						cin >> _city;

						record << _surname << endl;
						record << _phoneNum << endl;

						if (i < n - 1)
						{
							record << _city << endl;
						}
						else
						{
							record << _city;
						}

						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}

				cout << "Data has been changed!" << endl;
			}
			else
			{
				cout << "The number entered is incorrect!" << endl;
			}
		}
		else
		{
			cout << "Error opening file!" << endl;
		}
	}
	else
	{
		cout << "Error opening buffer file!" << endl;
	}

	record.close();
	reading.close();

	remove("Buffer_.txt");
}

void Copy()
{
	ifstream reading("Buffer.txt");
	ofstream record("Buffer_.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			// read from new file to new
			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
				{
					record << _city << endl;
				}
				else
				{
					record << _city;
				}

			}
		}
		else
		{
			cout << "Error opening buffer file!" << endl;
		}
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	// closing a file
	reading.close();
	record.close();	
}

void DeleteData()
{
	// data deletion

	// remember data
	// overwrite original buffer
	// except for the removed

	Copy();

	ifstream reading("Buffer_.txt");
	ofstream record("Buffer.txt", ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n, _n;

			// read from buffer file
			reading >> n;
			int b = n - 1;

			cout << "Select the number of the element to change (from 1 to " << n << "): " << endl;
			cin >> _n;
			_n--;

			system("cls");

			record << b << endl;

			if (_n >= 0 && _n < n)
			{
				for (int i = 0; i < n; i++)
				{
					if (i != _n)
					{
						reading >> _surname;
						record << _surname << endl;

						reading >> _phoneNum;
						record << _phoneNum << endl;

						reading >> _city;
						if (i < n - 1)
						{
							record << _city << endl;
						}
						else
						{
							record << _city;
						}
					}
					else
					{
						reading >> _surname;
						reading >> _phoneNum;
						reading >> _city;
					}
				}
				cout << "Data removed!" << endl;
			}
			else
			{
				cout << "The number entered is incorrect!" << endl;
			}
		}
		else
		{
			cout << "Error opening file!" << endl;
		}
	}
	else
	{
		cout << "Error opening buffer file!" << endl;
	}

	record.close();
	reading.close();

	remove("Buffer_.txt");
}  

int AmountOfData()
{
	// prints the amount of data from a file

	ifstream _buf("Buffer.txt");
	int n;

	if (_buf)
	{
		_buf >> n;
	}
	else
	{
		cout << "Error opening buffer file!" << endl;
	}

	_buf.close();

	return n;
} 

void AddData()
{
	// add data

	string _surname;
	int _phoneNum;
	string _city;
	int n = AmountOfData() + 1;

	ofstream record("Buffer.txt", ios::app);
	ofstream record_("Buffer.txt", ios::out | ios::in);

	if (record_)
	{
		record_ << n << endl;
	}
	else
	{
		cout << "Error opening buffer file!" << endl;
	}

	if (record)
	{
		record << endl;

		cout << "Enter data ¹1 (Last name): " << endl;
		cin >> _surname;

		cout << "Enter data ¹2 (Phone number):" << endl;
		cin >> _phoneNum;

		cout << "Enter data ¹3 (City):" << endl;
		cin >> _city;

		record << _surname << endl;
		record << _phoneNum << endl;
		record << _city;
	}
	else
	{
		cout << "Error opening buffer file!" << endl;
	}

	record.close();
	record_.close();
} 

void SaveData(string fileName)
{
	// saving data

	ifstream reading("Buffer.txt");
	ofstream record(fileName, ios::out);

	if (reading)
	{
		if (record)
		{
			string _surname;
			int _phoneNum;
			string _city;
			int n;

			reading >> n;
			record << n << endl;

			for (int i = 0; i < n; i++)
			{
				reading >> _surname;
				record << _surname << endl;

				reading >> _phoneNum;
				record << _phoneNum << endl;

				reading >> _city;
				if (i < n - 1)
				{
					record << _city << endl;
				}
				else
				{
					record << _city;
				}

			}

			cout << "Data saved to file!" << fileName << endl;
		}
		else
		{
			cout << "Error opening buffer file!" << endl;
		}
	}
	else
	{
		cout << "Error opening file!" << endl;
	}

	record.close();
	reading.close();
} 

bool DataCleaning()
{
	// buffer clearing

	bool clear = false;

	fstream _buf("Buffer.txt", ios::out);

	if (!_buf)
	{
		cout << "" << endl;
	}

	_buf.clear();

	// checking that the file is clean
	if (_buf.peek() == EOF)
	{
		clear = true;
	}
	else
	{
		clear = false;
	}

	_buf.close();

	return clear;
}