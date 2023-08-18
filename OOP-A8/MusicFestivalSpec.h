#pragma once

#include <string>

class MusicFestivalSpec
{
public:
	enum class Type { ANY, NEWYORK, PARIS, ROCK };

	Type get_city() const { return _city; }

	int get_concert_duration() const {
		return _concert_duration;
	}

	MusicFestivalSpec()
		: _city(MusicFestivalSpec::Type::ANY), _concert_duration(0) { }

	MusicFestivalSpec(MusicFestivalSpec::Type city, int concert_duration)
	{
		_city = city;
		_concert_duration = concert_duration;
	}

	// another C++ idiom to return an enumeration value as a string
	const std::string& get_type_as_string() const {
		static const std::string Type_S[]{ "Any", "NEWYORK", "PARIS", "ROCK" };
		return Type_S[(std::size_t)_city];
	}

	bool matches(const MusicFestivalSpec& otherSpec) const;

private:

	MusicFestivalSpec::Type _city;
	int _concert_duration;


};