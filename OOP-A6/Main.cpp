#include <iostream>
#include <iomanip>
#include "Inventory.h"
#include <fstream>

using namespace std;

// outputs abstraction object properties to the console window
void show(const MusicFestival& item)
{
    cout << item << "\n";
}
// solution entry function
int main()
{
Inventory inv;

// specification is constructed separately
auto spec_paris{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::PARIS, 4, 8) };
inv.add_item(2, 240.0, "Metallica", 1981, spec_paris);

MusicFestival b1(3, 380.0, "Iron Maiden", 1975, spec_paris);
cout << b1 << "\n";

auto filename{ "b1.csv" };
ofstream ofs(filename);
if (ofs)
ofs << b1 << "\n";
ofs.close();
cout << "Saved...\n";

MusicFestival b2;
ifstream ifs(filename);
if (ifs)
ifs >> b2;
ifs.close();
cout << "Read...\n"
<< b2 << "\n----\n";


    // specification is constructed during passing of an argument
    inv.add_item(2, 240.00, "Metallica", 1981, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::PARIS, 6, 8));

    // constructing and using shared specification
    auto spec_rock{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::ROCK, 3, 6) };
    inv.add_item(3, 380.00, "Rammstein", 1994, spec_rock);
    inv.add_item(4, 420.00, "Gunsnroses", 1985, spec_rock);

    // provide some querying values (some can be default (e.g., "", 0) to denote unset criteria)
    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ANY, 20, 0 }));

    // test with another query values
    show(inv.find_item(*spec_rock));

    show(inv.find_item(MusicFestival{ 0, 0.0, "", 1980, std::make_shared<MusicFestivalSpec>() }));

    // testing for non-matching criterion
    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ROCK, 0, 0 }));
    show(inv.find_item(MusicFestival{ 6, 0.0, "", 0, std::make_shared<MusicFestivalSpec>() }));

    auto inv_file_name{ "inventory.csv" };
    // save all items to file
    inv.save(inv_file_name);
    // load into different object
    Inventory inv2;
    inv2.load(inv_file_name);
    // test, that loading into inv2 succeeded
    // :::

#ifndef NDEBUG
    //cin.get();  // wait until Enter key is pressed
#endif


    return 0;
}