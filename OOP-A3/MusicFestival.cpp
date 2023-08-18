#include "MusicFestival.h"

void MusicFestival::init(int bandnumber, MusicFestival::Type bandname, MusicFestival::Type city, double price)
{
	_bandnumber = bandnumber;
	_bandname = bandname;
	_city = city;
	_price = price;
}