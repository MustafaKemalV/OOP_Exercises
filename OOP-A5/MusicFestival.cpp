#include "MusicFestival.h"

MusicFestival::MusicFestival(int bandnumber, double price, std::shared_ptr<const MusicFestivalSpec> spec)
{
	_bandnumber = bandnumber;
	_price = price;
	_spec = spec;
}