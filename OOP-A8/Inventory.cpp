#include "Inventory.h"
#include "MusicFestival.h"
#include <cmath>
#include <iostream>
#include <fstream>

// The parameters must match with the class declaration
//void Inventory::add_item(int bandnumber, double price, std::shared_ptr<const MusicFestivalSpec> spec)
void Inventory::add_item(const MusicFestival& new_item)
{
    auto found{ this->find_all_items(*new_item.get_spec()) };

    for (auto found_item : found)
        if (found_item.get_bandnumber() == new_item.get_bandnumber())
            return;

    _items.push_back(new_item);
}


std::vector<MusicFestival> Inventory::find_all_items(const MusicFestivalSpec& otherSpec) const
{
    std::vector<MusicFestival> found;

    for (auto item : _items)
        if (item.get_spec()->matches(otherSpec))
            found.push_back(item);

    return found; // If there are no matches, then empty container object is returned.
}



MusicFestival Inventory::find_item(const MusicFestivalSpec& otherSpec) const
{
    auto found{ this->find_all_items(otherSpec) };

    if (!found.empty())
        return found[0]; // return the first object with matching specification

    return MusicFestival{}; // return the 'default' value object
}

