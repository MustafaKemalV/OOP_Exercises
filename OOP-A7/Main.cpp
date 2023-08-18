#include "Inventory.h"
#include "MusicFestival.h"
#include "Guitar.h"

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


void show(const Item& item)
{
    cout << item << "\n";
}

// This is not finished and shows only the downcasting examples!
MusicFestival max_concert_duration(const Inventory& inv)
{
    int max_pos{ -1 };
    /*
        :::
        for (auto i{0}; i < inv.get_count(); i++)
        {
            auto ptr { dynamic_cast<const MusicFestivalSpec*>(&*inv[i].get_spec()) }; // or dynamic_cast<const MusicFestival*>(&inv[i]) if the property is in the abstration class
            if (nullptr == ptr) //if the instance does not refer to a required type
                continue;
            :::
            max_pos = i;
        }
        :::
    */
    return (max_pos >= 0)
        ? *dynamic_cast<const MusicFestival*>(&inv[max_pos])
        : MusicFestival{}; //if there is no MusicFestival in the inventory
}

int main()
{
Inventory inv;

// specification is constructed separately
auto spec_paris{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::PARIS, 4, 8) };
auto b1{ std::make_shared<MusicFestival>(2, 240.0, "Metallica", 1981, spec_paris) };
inv.add_item(b1);

MusicFestival b0(3, 380.0, "Iron Maiden", 1975, spec_paris);
cout << b0 << "\n";

auto filename{ "b0.csv" };
ofstream ofs(filename);
if (ofs)
    ofs << b0 << "\n";
ofs.close();
cout << "Saved...\n";

//MusicFestival b2;
//ifstream ifs(filename);
//if (ifs)
//ifs >> b2;
//ifs.close();
//cout << "Read...\n"
//<< b2 << "\n----\n";


    // specification is constructed during passing of an argument
auto b2{ std::make_shared<MusicFestival>(2, 240.00, "Metallica", 1981, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::PARIS, 6, 8)) };
inv.add_item(b2);

    // constructing and using shared specification
    auto spec_rock{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::ROCK, 3, 6) };
    inv.add_item(std::make_shared<MusicFestival>(3, 380.00, "Rammstein", 1994, spec_rock));
    inv.add_item(std::make_shared<MusicFestival>(4, 420.00, "Gunsnroses", 1985, spec_rock));

    // provide some querying values (some can be default (e.g., "", 0) to denote unset criteria)
    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ANY, 20, 0 }));

    // test with another query values
    show(inv.find_item(*spec_rock));

    show(inv.find_item(MusicFestivalSpec{}));

    // testing for non-matching criterion
    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ROCK, 0, 0 }));
    //show(inv.find_item(MusicFestival{ 6, 0.0, "", 0, std::make_shared<MusicFestivalSpec>() }));

      // add another type of abstraction
    auto g1{ std::make_shared<Guitar>(6, 500.0, std::make_shared<GuitarSpec>("Fender Player Stratocaster MN", GuitarSpec::Type::ELECTRIC)) };
    inv.add_item(g1);

    show(inv.find_item(GuitarSpec{ "", GuitarSpec::Type::ELECTRIC }));

    show(max_concert_duration(inv));

    auto inv_file_name{ "inventory.csv" };
    // save all items to file
    inv.save(inv_file_name);

    /// Not implemented for Assignment 7:
    // load into different object
    //Inventory inv2;
    //inv2.load(inv_file_name);

    return 0;
}