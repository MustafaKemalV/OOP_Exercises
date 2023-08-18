#pragma once

#include <string>

class MusicFestivalSpec
{
public:
	enum class Type { ANY, NEWYORK, PARIS, ROCK };

	Type get_city() const { return _city; }

	MusicFestivalSpec()
		: _city(MusicFestivalSpec::Type::ANY) {}

	MusicFestivalSpec(MusicFestivalSpec::Type city)
	{
		_city = city;
	}

	// another C++ idiom to return an enumeration value as a string
	const std::string& get_type_as_string() const {
		static const std::string Type_S[]{ "Any", "NEWYORK", "PARIS", "ROCK" };
		return Type_S[(std::size_t)_city];
	}

private:

	MusicFestivalSpec::Type _city;


};