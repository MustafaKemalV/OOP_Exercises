#pragma once
#ifndef MUSICFESTIVAL_SPEC
#define MUSICFESTIVAL_SPEC

#include <iostream>

class MusicFestivalSpec
{
public:
	enum class Type { ANY, NEWYORK, PARIS, ROCK };

	MusicFestivalSpec() = default;
	MusicFestivalSpec(Type city, unsigned short concert_duration, unsigned short music_amount)
		: _city{ city }
		, _concert_duration{ concert_duration }
		, _music_amount{ music_amount }
	    { }

	bool matches(const MusicFestivalSpec& otherSpec) const;

	Type get_city() const { return _city; }

	unsigned short get_concert_duration() const { return _concert_duration; }
	unsigned short get_music_amount() const { return _music_amount; }

	void send_to(std::ostream& os) const;
	void recv_from(std::istream& is);
	friend std::istream& operator>>(std::istream& is, MusicFestivalSpec& spec);

private:

	Type _city;
	unsigned short _concert_duration;
	unsigned short _music_amount;

};

std::ostream& operator<<(std::ostream& os, MusicFestivalSpec::Type city);
std::istream& operator>>(std::istream& is, MusicFestivalSpec::Type& city);

std::ostream& operator<<(std::ostream& os, const MusicFestivalSpec& spec);

#endif