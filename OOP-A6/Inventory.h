#pragma once
#ifndef INVENTORY
#define INVENTORY

#include "MusicFestival.h" 
#include "MusicFestivalSpec.h"
#include <string>
#include <exception>
#include <memory>

class Inventory
{
public:
    // Initializes the inventory
    Inventory() : _count{ 0 } { }

    // Returns the current number of abstraction objects
    size_t get_count() const { return _count; }

    const MusicFestival& operator[](size_t i) const { return get_item(i); }
    // Returns stored abstraction object by its index or throws an exception if index is invalid
    const MusicFestival& get_item(size_t i) const
    {
        if (i < _count)
        {
            return _items[i];
        }

        throw std::out_of_range("Invalid index value.");
    }

    // From passed property values, creates and adds new abstraction object in an array _items
    // (replace parameters to match your property types and identifiers)
    void add_item(unsigned bandnumber, double price, std::string band, unsigned short bandyear, std::shared_ptr<const MusicFestivalSpec> spec);
    //void add_item(const MusicFestival& MusicFestival);

    // Looks for a matching abstraction object and returns the first found or default object
    MusicFestival find_item(const MusicFestival & query) const;

    MusicFestival find_item(const MusicFestivalSpec& spec_query) const;

    void save(const std::string& csv_file_name) const;
    void load(const std::string& csv_file_name);

private:
    // The maximum number of abstraction objects that can be stored
    static const size_t MAX_SIZE{ 10 };

    // An array for storing abstraction objects
    MusicFestival _items[Inventory::MAX_SIZE];

    // The number of currently stored abstraction objects in the array _items
    size_t _count;
};

#endif
