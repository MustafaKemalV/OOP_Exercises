#include <iostream>
#include "MusicFestival.h"
#include "Inventory.h"

using namespace std;

// outputs abstraction object properties to the console window
void show(const MusicFestival & item)
{
 //  static const char* TYPE_S[]{ "Any", "NEWYORK", "PARIS", "ROCK" };

    cout << item.get_bandnumber() << " ";

    auto is_ptr{ item.get_spec() };
    if (is_ptr)
    {
        cout << "'" << is_ptr->get_type_as_string() << "'";
    }
    cout
        << item.get_price() << " "
        << endl;
}

MusicFestival max_price(const Inventory& inv)
{
    //:::
    return MusicFestival{};
}

// solution entry function
int main()
{

    MusicFestival b0;

    Inventory inv;

    auto paris_spec{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::PARIS, 4) };

    // adds several different abstraction objects to the inventory
    inv.add_item(2, 240.00, paris_spec);
    inv.add_item(3, 380.00, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::NEWYORK, 5));
    inv.add_item(4, 420.00, paris_spec);

    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    MusicFestival qry(3, 0.0, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::ANY, 0));
    show(inv.find_item(qry));

    // tests with different query values
    MusicFestival qry1(4, 0.0, paris_spec);
    show(inv.find_item(qry1));
    show(inv.find_item(*paris_spec));
    
    // tests for nonmatching object
    MusicFestival qry2(0, 0.0, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::ROCK, 50));
    show(inv.find_item(qry2));


    return 0;
}