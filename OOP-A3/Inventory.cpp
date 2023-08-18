#include "Inventory.h"
#include <math.h>

// The parameters must match with the class declaration
void Inventory::add_item(int bandnumber, MusicFestival::Type bandname, MusicFestival::Type city, double price)
{
    if (_count < Inventory::MAX_SIZE)
    {
        MusicFestival new_item;
        new_item.init(bandnumber, bandname, city, price);
        if (find_item(new_item).get_bandnumber() != bandnumber)
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

        // for enum type property
        if (query.get_bandname() != MusicFestival::Type::ANY
            && query.get_bandname() != _items[i].get_bandname())
            continue;

        // for enum type property
        if (query.get_city() != MusicFestival::Type::ANY
            && query.get_city() != _items[i].get_city())
            continue;

        // for double type property
        constexpr double epsil{ 0.005 };
        if (query.get_price() != 0.0
            && epsil < std::abs(query.get_price() - _items[i].get_price()))
            continue;



        return _items[i];
    }

    return MusicFestival{}; // return the 'default' object
}