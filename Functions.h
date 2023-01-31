#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// function prototypes
void DataInitialization(); // data initialization
void DataEntry(); // manual data entry
void DataReading(string fileName); // reading data
void Print(); // data output
bool DataCleaning(); // data cleaning
void DataChange(); // data change
void Copy(); // data copying
int AmountOfData(); // amount of data
void DeleteData(); // data deletion
void AddData(); // adding data
void SaveData(string fileName); // saving data