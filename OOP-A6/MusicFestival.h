#pragma once

#ifndef MUSICFESTIVAL	
#define MUSICFESTIVAL

#include <string>
#include <memory>
#include <iostream>
#include "MusicFestivalSpec.h"

using namespace std;

class MusicFestival
{
public:
    MusicFestival() = default;
    MusicFestival(unsigned bandnumber, double price, std::string band, unsigned short bandyear, std::shared_ptr<const MusicFestivalSpec> spec)
        : _bandnumber{ bandnumber }
        , _price{ price }
        , _band{ band }
        , _bandyear{ bandyear }
        , _spec{ spec }
        { }

    unsigned get_bandnumber() const { return _bandnumber; }
    double get_price() const { return _price; }
    std::string get_band() const { return _band; }
    unsigned short get_bandyear() const { return _bandyear; }
    std::shared_ptr<const MusicFestivalSpec> get_spec() const { return _spec; }

    void send_to(std::ostream & os) const;
    void recv_from(std::istream & is);
    friend std::istream& operator>>(std::istream & is, MusicFestival& item);

private:
    unsigned _bandnumber;
    double _price;
    std::string _band;
    unsigned short _bandyear;
    std::shared_ptr<const MusicFestivalSpec> _spec;
};

std::ostream & operator<<(std::ostream& os, const MusicFestival& item);


#endif
