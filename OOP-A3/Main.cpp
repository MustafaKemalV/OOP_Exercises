#include <iostream>
#include "MusicFestival.h"
#include "Inventory.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(const MusicFestival & item)
{
    static const char* TYPE_S[]{ "Any", "METALLICA_IRONMAIDEN", "AVENGEDSEVENFOLD_THEROLLINGSTONES_GREENDAY", "NEWYORK", "PARIS", "ACDC" };

    cout << item.get_bandnumber() << " "
        << "'" << TYPE_S[(size_t)item.get_bandname()] << "' "
        << "'" << TYPE_S[(size_t)item.get_city()] << "' "
        << item.get_price() << " "
        << endl;
}

// solution entry function
int main()
{
    Inventory inv;

    inv.init();

    // adds several different abstraction objects to the inventory
    inv.add_item(2, MusicFestival::Type::METALLICA_IRONMAIDEN, MusicFestival::Type::PARIS, 240.00);
    inv.add_item(3, MusicFestival::Type::AVENGEDSEVENFOLD_THEROLLINGSTONES_GREENDAY, MusicFestival::Type::NEWYORK, 380.00);

    MusicFestival qry;
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    qry.init(3, MusicFestival::Type::ANY, MusicFestival::Type::ANY, 0.0);
    show(inv.find_item(qry));

    // tests with different query values
    qry.init(0, MusicFestival::Type::METALLICA_IRONMAIDEN, MusicFestival::Type::ANY, 0.0);
    show(inv.find_item(qry));

    // tests for nonmatching object
    qry.init(0, MusicFestival::Type::ACDC, MusicFestival::Type::ANY, 0.0);
    show(inv.find_item(qry));


    return 0;
}