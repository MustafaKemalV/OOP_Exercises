#include <iostream>
#include "MusicFestival.h"
#include "Inventory.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(MusicFestival item)
{
    cout << item.get_bandnumber() << " "
        << "'" << item.get_bandname() << "' "
        << "'" << item.get_city() << "' "
        << item.get_price() << " "
        << endl;
}

// solution entry function
int main()
{
    Inventory inv;

    inv.init();

    // adds several different abstraction objects to the inventory
    inv.add_item(2, "Metallica, Iron Maiden", "Paris", 240.00);
    inv.add_item(3, "Avenged Sevenfold, The Rolling Stones, Green Day ", "New York", 380.00);

    MusicFestival qry;
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    qry.init(3, "", "", 0.0);
    show(inv.find_item(qry));

    // tests with different query values
    qry.init(0, "Metallica, Iron Maiden", "", 0.0);
    show(inv.find_item(qry));

    // tests for nonmatching object
    qry.init(0, "AC/DC", "", 0.0);
    show(inv.find_item(qry));


    return 0;
}