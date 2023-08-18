#include "MusicFestival.h"

#include <string> // for std::getline()

std::ostream& operator<<(std::ostream& os, const MusicFestival& item)
{
    item.send_to(os);
    return os;
}


void MusicFestival::send_to(std::ostream& os) const
{
    os << _bandnumber << ';'
        << _price << ';'
        << _band << ';'
        << _bandyear;

    if (_spec)
    {
        os << ';';
        _spec->send_to(os);
    }
}


std::istream& operator>>(std::istream& is, MusicFestival& item)
{
    item.recv_from(is);
    return is;
}


void MusicFestival::recv_from(std::istream& is)
{
    if (is)
        (is >> _bandnumber).ignore(); // calling ignore() to skip ';'

    if (is)
        (is >> _price).ignore();

    if (is)
        std::getline(is >> std::ws, _band, ';'); // skips ';' automatically

    if (is)
        (is >> _bandyear).ignore();

    auto temp_spec{ std::make_shared<MusicFestivalSpec>() };
    temp_spec->recv_from(is); // alternatively: is >> *temp_spec;
    _spec = temp_spec; // replace the specification
}