#include <iostream>
#include "MusicFestival.h"
#include "Inventory.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(const MusicFestival & item)
{
 //  static const char* TYPE_S[]{ "Any", "NEWYORK", "PARIS", "ROCK" };

    cout << item.get_bandnumber() << " "
        << "'" << item.get_spec().get_type_as_string() << "'"
        << item.get_price() << " "
        << endl;
}

// solution entry function
int main()
{
    Inventory inv;


    // adds several different abstraction objects to the inventory
    inv.add_item(2, 240.00, MusicFestivalSpec(MusicFestivalSpec::Type::PARIS));
    inv.add_item(3, 380.00, MusicFestivalSpec(MusicFestivalSpec::Type::NEWYORK));
    
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    MusicFestival qry(3, 0.0, MusicFestivalSpec(MusicFestivalSpec::Type::ANY));
    show(inv.find_item(qry));

    // tests with different query values
    MusicFestival qry1(0, 0.0, (MusicFestivalSpec::Type::PARIS));
    show(inv.find_item(qry1));
    
    // tests for nonmatching object
    MusicFestival qry2(0, 0.0, (MusicFestivalSpec::Type::ROCK));
    show(inv.find_item(qry2));


    return 0;
}