#include "MusicFestival.h"

MusicFestival::MusicFestival(int bandnumber, double price, const MusicFestivalSpec& spec)
{
	_bandnumber = bandnumber;
	_price = price;
	_spec = spec;
}