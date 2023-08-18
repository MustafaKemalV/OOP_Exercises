#include "Inventory.h"
#include <cmath>
#include <fstream> // for implementing load() and save() below

// The parameters must match with the class declaration
void Inventory::add_item(unsigned bandnumber, double price, std::string band, unsigned short bandyear, std::shared_ptr<const MusicFestivalSpec> spec)
{
    if (_count < Inventory::MAX_SIZE)
    {
        MusicFestival new_item(bandnumber, price, band, bandyear, spec);

        if (bandnumber != find_item(new_item).get_bandnumber())
        {
            _items[_count] = new_item;
            _count++;
        }
    }
}

MusicFestival Inventory::find_item(const MusicFestival & query) const
{
    for (size_t i = 0; i < _count; i++)
    {
        // for integer and boolean type property
        if (query.get_bandnumber() != 0
            && query.get_bandnumber() != _items[i].get_bandnumber())
            continue;

     

        // for double type property
        constexpr double epsil{ 0.005 };
        if (query.get_price() != 0.0
            && epsil < std::abs(query.get_price() - _items[i].get_price()))
            continue;

        // for string type property
        if (query.get_band() != ""
            && query.get_band() != _items[i].get_band())
            continue;

        if (query.get_bandyear() != 0
            && query.get_bandyear() != _items[i].get_bandyear())
            continue;

        // check specification properties
        if (query.get_spec()
            && _items[i].get_spec()
            && _items[i].get_spec()->matches(*query.get_spec())) // note the dereferencing asterisk
        {
            return _items[i];
        }
    }

    return MusicFestival{}; // return the 'default' object
}

MusicFestival Inventory::find_item(const MusicFestivalSpec& spec_query) const
{
	for (size_t i = 0; i < _count; i++)
	{

		if (_items[i].get_spec()
			&& _items[i].get_spec()->matches(spec_query))
		{
			return _items[i]; // return the first object with a matching specification
		}
	}

    return MusicFestival{}; // return the 'default' object
}

void Inventory::save(const std::string& csv_file_name) const
{
    std::ofstream os(csv_file_name);
    // TODO!
    // :::
}


void Inventory::load(const std::string& csv_file_name)
{
    std::ifstream is(csv_file_name);
    // TODO!
    // :::
}