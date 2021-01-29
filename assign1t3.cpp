// assign1t3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
class Contestant {
public:
    string Name;
    int Age, Ratings;
 
    int input();
    int output_highest_rated();
};
 
int Contestant::input()
{ 
    fstream file_obj;
    file_obj.open("contest.txt", ios::out);
 
    Contestant obj;
 
    string str = "Mahesh";
    int age = 18, ratings = 2500;
 
    obj.Name = str;
    obj.Age = age;
    obj.Ratings = ratings;
 
    file_obj.write((char*)&obj, sizeof(obj));
 
    str = "Tanmay";
    age = 21;
    ratings = 3200;
 
    obj.Name = str;
    obj.Age = age;
    obj.Ratings = ratings;
 
    file_obj.write((char*)&obj, sizeof(obj));

	str = "Remo";
    age = 26;
    ratings = 3700;
 
    obj.Name = str;
    obj.Age = age;
    obj.Ratings = ratings;
 
    file_obj.write((char*)&obj, sizeof(obj));
	file_obj.close();
    return 0;
}
 
int Contestant::output_highest_rated()
{
    fstream file_obj;
    file_obj.open("contest.txt", ios::in);
 
    Contestant obj;
 
    file_obj.read((char*)&obj, sizeof(obj));
 
    int max = 0;
 
    string Highest_rated;
 
    while (!file_obj.eof()) {
        if (obj.Ratings > max) {
            max = obj.Ratings;
            Highest_rated = obj.Name;
        }
 
        file_obj.read((char*)&obj, sizeof(obj));
    }
	file_obj.close();
 
    cout << Highest_rated <<" is the highest rated player.\n";
    return 0;
}
 
int _tmain(int argc, _TCHAR* argv[])
{
    Contestant object;
 
    object.input();
 
    object.output_highest_rated();
 
    return 0;
}
