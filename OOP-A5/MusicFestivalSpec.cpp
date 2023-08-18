#include "MusicFestivalSpec.h"

bool MusicFestivalSpec::matches(const MusicFestivalSpec& otherSpec) const
{
    if (this == &otherSpec) // if comparing to self
        return true;

    if (otherSpec.get_city() != MusicFestivalSpec::Type::ANY
        && otherSpec.get_city() != get_city())
        return false;  

    if (otherSpec.get_concert_duration() != 0
        && otherSpec.get_concert_duration() != get_concert_duration())
        return false;

    return true;
}
