// assign1t1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{	
	cout << "Hello!!!" << "\n";
	cout << "Opening and Writing information into a file." << "\n";
	fstream newfile;
	newfile.open("myfile.txt",ios::out);
	if(newfile.is_open()){
      newfile<<"My first Program in Max Secure Softwares \n";
      newfile.close();
	}
	
	cout << "Opening and Reading information from a file." << "\n";
	newfile.open("myfile.txt",ios::in);
	if (newfile.is_open()){
      string tp;
      while(getline(newfile, tp)){
         cout << tp << "\n";
      }
      newfile.close();
	}
	cin.get();
	return 0;
}

