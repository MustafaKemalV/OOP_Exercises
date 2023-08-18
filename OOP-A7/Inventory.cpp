#include "Inventory.h"

//void Inventory::add_item(unsigned id, double price, std::string model, unsigned short model_year, std::shared_ptr<const BicycleSpec> spec)
void Inventory::add_item(std::shared_ptr<Item> new_item)
{
    if (_count < Inventory::MAX_SIZE)
    {
        //MusicFestival new_item(bandnumber, price, band, bandyear, spec);

        if (new_item->get_bandnumber() != find_item(*new_item->get_spec()).get_bandnumber())
        {
            _items[_count] = new_item;
            _count++;
        }
    }
}

/// This overload is not possible unless also the class Item implements some kind of function matches()
//const Item & Inventory::find_item(const Item & query) const
//{
//    for (size_t i = 0; i < _count; i++)
//    {
//        // for integer and boolean type property
//        if (query.get_bandnumber() != 0
//
//            && query.get_bandnumber() != _items[i].get_bandnumber())
//            continue;
//
//     
//
//        // for double type property
//        constexpr double epsil{ 0.005 };
//        if (query.get_price() != 0.0
//            && epsil < std::abs(query.get_price() - _items[i].get_price()))
//            continue;
//
//        // for string type property
//        if (query.get_band() != ""
//            && query.get_band() != _items[i].get_band())
//            continue;
//
//        if (query.get_bandyear() != 0
//            && query.get_bandyear() != _items[i].get_bandyear())
//            continue;
//
//        // check specification properties
//       if (query.get_spec()
//            && _items[i].get_spec()
//            && _items[i].get_spec()->matches(*query.get_spec())) // note the dereferencing asterisk
//        
//            return _items[i];
//        }
    

//    static const Item def{};
//    return def; // return the 'default' value object (or null in Java)
//}

const Item& Inventory::find_item(const ItemSpec& query_spec) const
{
    for (size_t i{ 0U }; i < _count; i++)
        if (_items[i]->get_spec()->matches(query_spec))
            return *_items[i]; // return the first object with a matching specification

    static const Item def{};
    return def; // return the 'default' value object (or null in Java)
}


void Inventory::save(const std::string& csv_file_name) const
{
    // TODO :::
}


void Inventory::load(const std::string& csv_file_name)
{
    // TODO :::
}