#include "MusicFestivalSpec.h"

#include <string> // for std::getline()

#ifdef _MSC_VER // Visual C++ ?
    #define strcasecmp _stricmp // then use the function _stricmp() 
#else
    #include <strings.h> // for strcasecmp() function in POSIX C++
#endif

static const std::string Type_S[]{ "Any", "Newyork", "Paris", "Rock" };

std::ostream& operator<<(std::ostream& os, MusicFestivalSpec::Type c)
{
    os << Type_S[static_cast<size_t>(c)];
    return os;
}


std::ostream& operator<<(std::ostream& os, const MusicFestivalSpec& spec)
{
    spec.send_to(os);
    return os;
}


void MusicFestivalSpec::send_to(std::ostream& os) const {
    os << _city << ';'
        << _concert_duration << ';'
        << _music_amount;
        
}

std::istream& operator>>(std::istream& is, MusicFestivalSpec::Type& city)
{
    if (is)
    {
        std::string tmp;
        std::getline(is, tmp, ';');
        if (is)
        {
            bool found{ false };

            for (size_t i{ 0 }; i < sizeof(Type_S) / sizeof(Type_S[0]); i++)
            {
                if (tmp.length() == Type_S[i].length()
                    && 0 == strcasecmp(tmp.c_str(), Type_S[i].c_str())) // case insensitive comparison
                {
                    city = static_cast<MusicFestivalSpec::Type>(i);
                    found = true;
                    break;
                }
            }

            if (!found)
                city = MusicFestivalSpec::Type::ANY;
        }
    }

    return is;
}

std::istream& operator>>(std::istream& is, MusicFestivalSpec& item)
{
    item.recv_from(is);
    return is;
}


void MusicFestivalSpec::recv_from(std::istream& is)
{
    // Must be in the same order as in BicycleSpec::send_to(..)!

    if (is)
        is >> _city; // operator>>() processed ';'

    if (is)
        (is >> _concert_duration).ignore(); // call ignore() to skip ';'

    if (is)
        (is >> _music_amount).ignore();

}

bool MusicFestivalSpec::matches(const MusicFestivalSpec& otherSpec) const
{
    bool result{ true };

    if (otherSpec.get_city() != MusicFestivalSpec::Type::ANY
        && otherSpec.get_city() != this->get_city())
        result = false;

    if (otherSpec.get_concert_duration() != 0
        && otherSpec.get_concert_duration() != this->get_concert_duration())
        result = false;

    if (otherSpec.get_music_amount() != 0
        && otherSpec.get_music_amount() != this->get_music_amount())
        result = false;

    return result;
}
