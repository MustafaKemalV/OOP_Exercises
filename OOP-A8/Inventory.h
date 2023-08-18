#pragma once
#ifndef INVENTORY
#define INVENTORY
#include <vector>
#include <fstream>
#include <string>
#include <exception>
#include <memory>
#include "MusicFestival.h"
#include "MusicFestivalSpec.h"

class Inventory
{
public:

    std::vector<MusicFestival> find_all_items(const MusicFestivalSpec& otherSpec) const;
    // Initializes the inventory
    //Inventory() { _count = 0; }

    // Returns the current number of abstraction objects
    //size_t get_count() const { return _count; }
    //size_t get_count() const { return _items.size(); }

    std::vector<MusicFestival>::const_iterator begin() const { return _items.begin(); }
    std::vector<MusicFestival>::const_iterator end() const { return _items.end(); }


    // Returns stored abstraction object by its index or default object if index is invalid
    //MusicFestival get_item(size_t i) const { return (i < _count) ? _items[i] : MusicFestival{}; }
    size_t get_count() const { return _items.size(); }
    // From passed property values, creates and adds new abstraction object in an array _items
    // (replace parameters to match your property types and identifiers)
    void add_item(const MusicFestival& new_item);

    //void add_item(const MusicFestival& MusicFestival);

    // Looks for a matching abstraction object and returns the first found or default object
    MusicFestival find_item(const MusicFestival & query) const;
    MusicFestival find_item(const MusicFestivalSpec& spec_query) const;


private:

    std::vector<MusicFestival> _items;
    // The maximum number of abstraction objects that can be stored
    //static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    //MusicFestival _items[Inventory::MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    //size_t _count;
};

#endif
