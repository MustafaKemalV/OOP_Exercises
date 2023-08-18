#pragma once

#ifndef MUSICFESTIVAL	
#define MUSICFESTIVAL

#include <string>

using namespace std;

class MusicFestival
{
public:
	enum class Type { ANY, METALLICA_IRONMAIDEN, AVENGEDSEVENFOLD_THEROLLINGSTONES_GREENDAY, NEWYORK, PARIS, ACDC };

	void init(int bandnumber, MusicFestival::Type bandname, MusicFestival::Type city, double price);
	int get_bandnumber() const { return _bandnumber; }
	MusicFestival::Type get_bandname() const { return _bandname; }
	MusicFestival::Type get_city() const { return _city; }
	double get_price() const { return _price; }

private:
	int _bandnumber;
	MusicFestival::Type _bandname;
	MusicFestival::Type _city;
	double _price;
};

#endif
