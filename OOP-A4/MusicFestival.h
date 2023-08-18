#pragma once

#ifndef MUSICFESTIVAL	
#define MUSICFESTIVAL

#include <string>
#include "MusicFestivalSpec.h"

using namespace std;

class MusicFestival
{
public:
	
	MusicFestival()
		: _bandnumber(0), _price(0.0) { }

	MusicFestival(int bandnumber, double price, const MusicFestivalSpec& spec);
	int get_bandnumber() const { return _bandnumber; }
	double get_price() const { return _price; }
	MusicFestivalSpec get_spec() const { return _spec; }

private:
	int _bandnumber;
	double _price;
	MusicFestivalSpec _spec;

};

#endif
