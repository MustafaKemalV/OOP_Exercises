#include <iostream>
#include "MusicFestival.h"
#include "Inventory.h"
#include <iomanip>
#include <algorithm>
#include <fstream>


using namespace std;

// outputs abstraction object properties to the console window
void show(const MusicFestival & item)
{
 //  static const char* TYPE_S[]{ "Any", "NEWYORK", "PARIS", "ROCK" };

    cout << item.get_bandnumber() << " ";

    auto is_ptr{ item.get_spec() };
    if (is_ptr)
    {
        cout << "'" << is_ptr->get_type_as_string() << "'"
                    << item.get_price() << " "
                    << is_ptr->get_concert_duration() << " ";
    }
    cout << endl;   
}



// solution entry function
int main()
{

    

    Inventory inv;

    auto paris_spec{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::PARIS, 4) };

    // adds several different abstraction objects to the inventory
    //inv.add_item(2, 240.00, paris_spec);
    //inv.add_item(3, 380.00, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::NEWYORK, 5));
    //inv.add_item(4, 420.00, paris_spec);
    // provides querying values (some can be default (e.g., "", 0) to denote unset criteria)
    //MusicFestival qry(3, 0.0, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::ANY, 0));
    //show(inv.find_item(qry));
    // tests with different query values
    //MusicFestival qry1(4, 0.0, paris_spec);
    //show(inv.find_item(qry1));
    //show(inv.find_item(*paris_spec));
    // tests for nonmatching object
    //MusicFestival qry2(0, 0.0, std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::ROCK, 50));
    //show(inv.find_item(qry2));

    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ANY, 3 }));

    auto spec_newyork{ std::make_shared<MusicFestivalSpec>(MusicFestivalSpec::Type::NEWYORK, 4) };


    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ANY, 2, }));


    show(inv.find_item(MusicFestivalSpec{ MusicFestivalSpec::Type::ROCK, 0 }));

    show(inv.find_item(*spec_newyork));

    
#ifndef NDEBUG
    cin.get(); 
#endif
    return 0;
}
    bool is_less(const MusicFestival & item1, const MusicFestival & item2)
    {
        return item1.get_price() < item2.get_price();
    }


    MusicFestival max_price(const Inventory& inv)

       
    {
        if (0 == inv.get_count()) // alternatively this condition can be used: inv.begin() == inv.end()
            throw std::range_error("There are no items");

        return *std::max_element(inv.begin(), inv.end(), is_less);
    }
   


    class Average
    {

    public:
        Average() : _sum{ 0.0 }, _count{ 0 } { }
        void operator()(const MusicFestival& item)
        {
            _sum += item.get_price();
            _count++;
        }
        double result() const { return _count ? _sum / _count : 0.0; }
    private:
        double _sum;   // the accumulated sum
        size_t _count; // the count of items accumulated
    };

    double avg_priceget_price(const Inventory& inv)
    {
        return std::for_each(inv.begin(), inv.end(), Average()).result();
    }