#include "GuitarSpec.h"

bool GuitarSpec::matches(const ItemSpec& itemSpec) const
{
    if (this == &itemSpec)
        return true;  // if comparing to self

    bool result{ true };

    // try to downcast to the required derived specification type
    auto temp{ dynamic_cast<const GuitarSpec*>(&itemSpec) };
    if (nullptr == temp)
        return false; // if itemSpec doesn't refer to BicycleSpec (or derived) class instance

    // cast to reference type for actual comparison of properties
    const GuitarSpec& otherSpec{ *temp };

    if (otherSpec.get_band() != ""
        && otherSpec.get_band() != this->_band)
        result = false;

    if (otherSpec.get_type() != GuitarSpec::Type::ANY
        && otherSpec.get_type() != this->_city)
        result = false;

    return result;
}


void GuitarSpec::send_to(std::ostream& os) const
{
    static const char* Type_cstr[]{ "Any", "Acoustic", "Electric" };

    os << _band << ';'
        << Type_cstr[static_cast<size_t>(_city)];
}