#pragma once
#include "ItemSpec.h"
#include <string>

class GuitarSpec : public ItemSpec
{
public:
    enum class Type { ANY, ACOUSTIC, ELECTRIC };

    GuitarSpec() = default;
    GuitarSpec(const std::string& band, Type city)
        : ItemSpec(), _band(band), _city(city) { }

    bool matches(const ItemSpec& itemSpec) const override;

    std::string get_band() const { return _band; }
    Type get_type() const { return _city; }

    void send_to(std::ostream& os) const override;
private:
    std::string _band;
    Type _city;
};
