#pragma once

#ifndef MUSICFESTIVAL	
#define MUSICFESTIVAL

#include "Item.h"
#include "MusicFestivalSpec.h"
#include <string>
#include <memory>
#include <iostream>



class MusicFestival : public Item
{
public:
    MusicFestival() = default;
    MusicFestival(unsigned bandnumber, double price, std::string band, unsigned short bandyear, std::shared_ptr<const MusicFestivalSpec> spec)
        : Item(bandnumber, spec)
        , _price{ price }
        , _band{ band }
        , _bandyear{ bandyear }
        { }

    double get_price() const { return _price; }
    std::string get_band() const { return _band; }
    unsigned short get_bandyear() const { return _bandyear; }

    void send_to(std::ostream & os) const override;
    void recv_from(std::istream & is);
    friend std::istream& operator>>(std::istream & is, MusicFestival& item);

private:
    
    double _price;
    std::string _band;
    unsigned short _bandyear;
   
};

//std::ostream & operator<<(std::ostream& os, const MusicFestival& item);


#endif
