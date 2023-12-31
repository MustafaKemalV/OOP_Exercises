#pragma once
#ifndef ITEM

#include <memory>
#include <ostream>
#include "ItemSpec.h"

class Item
{
public:
    Item() = default;
    virtual ~Item() = default;

    Item(int bandnumber, std::shared_ptr<const ItemSpec> spec)
        : _bandnumber{ bandnumber }
    {
        set_spec(spec);
    }

    int get_bandnumber() const
    {
        return _bandnumber;
    }

    std::shared_ptr<const ItemSpec> get_spec() const
    {
        return _spec;
    }

    virtual void send_to(std::ostream& os) const
    {
        os << _bandnumber;

        if (_spec)
        {
            os << ';';
            _spec->send_to(os);
        }
    }

protected:
    // for changing the specification only in this and in derived classes:
    void set_spec(std::shared_ptr<const ItemSpec> spec)
    {
        _spec = spec;
    }

private:
    int _bandnumber;
    std::shared_ptr<const ItemSpec> _spec;
};

std::ostream& operator<<(std::ostream& os, const Item& item);

#endif // !ITEM
