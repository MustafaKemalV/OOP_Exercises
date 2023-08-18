#pragma once

#ifndef MUSICFESTIVAL	
#define MUSICFESTIVAL

#include <string>

using namespace std;

class MusicFestival
{
public:
	void init(int bandnumber, string bandname, string city, double price);
	int get_bandnumber() { return _bandnumber; }
	string get_bandname() { return _bandname; }
	string get_city() { return _city; }
	double get_price() { return _price; }

private:
	int _bandnumber;
	string _bandname;
	string _city;
	double _price;
};

#endif
