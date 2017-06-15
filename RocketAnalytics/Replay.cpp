// Author: Michael Doyle
// Date: 6/13/17
// Replay.cpp

#include "Replay.hpp"
#include <iostream>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include "boost/lexical_cast.hpp"


// Initialize static replay count
int Replay::replay_count_ = 0;


// Constructors
Replay::Replay() {
	replay_count_++; // Increment replay count
}

Replay::Replay(std::string filepath) {
	filepath_ = filepath;
	replay_count_++; // Increment replay count
}


// Destructor
Replay::~Replay(void) {
	replay_count_--; // Decrement replay count
}


// Return the amount of Replay objects initialized
int Replay::replay_count(void) { return replay_count_; }


// Standard Getters
std::string		Replay::filepath(void) const		{ return filepath_; }
std::int32_t	Replay::part1_length(void) const	{ return part1_length_; }
std::int32_t	Replay::part1_crc(void) const		{ return part1_crc_; }
std::int32_t	Replay::version_major(void) const	{ return version_major_; }
std::int32_t	Replay::version_minor(void) const	{ return version_minor_; }
std::string		Replay::replay_identifier(void) const { return replay_identifier_; }
std::int32_t	Replay::part2_length(void) const	{ return part2_length_; }
std::int32_t	Replay::part2_crc(void) const		{ return part2_crc_; }
std::int32_t	Replay::level_length(void) const	{ return level_length_; }


// To string
std::string Replay::to_string(void) {
	std::stringstream output_stream;
	output_stream << "filepath: " << filepath_ << '\n'
		<< "part1_length: " << part1_length_ << '\n'
		<< "part1_crc: " << part1_crc_ << '\n'
		<< "version_major: " << version_major_ << '\n'
		<< "version_minor: " << version_minor_ << '\n'
		<< "replay_identifier: " << replay_identifier_ << '\n';
	std::string output = output_stream.str();
	return output;
}


// Parse the entire replay file
void Replay::parse(std::ifstream &br) {
	parse_part1(br);
	parse_part1_crc(br);
	parse_version_major(br);
	parse_version_minor(br);
}


// Assumes the ifstream is pointed at the correct file position
void Replay::parse_part1(std::ifstream &br) {
	std::int32_t raw_int;
	br.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
	part1_length_ = raw_int;
}


// Assumes the ifstream is pointed at the correct file position
void Replay::parse_part1_crc(std::ifstream &br) {
	std::int32_t raw_int;
	br.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
	part1_crc_ = raw_int;
}


// Assumes the ifstream is pointed at the correct file position
void Replay::parse_version_major(std::ifstream &br) {
	std::int32_t raw_int;
	br.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
	version_major_ = raw_int;
}


// Assumes the ifstream is pointed at the correct file position
void Replay::parse_version_minor(std::ifstream &br) {
	std::int32_t raw_int;
	br.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
	version_minor_ = raw_int;
}


// Assumes the ifstream is pointed at the correct file position
void Replay::parse_replay_identifier(std::ifstream &br) {
	std::int32_t size;
	std::string raw_string;
	br.read(reinterpret_cast<char *>(&size), sizeof(size));
	br.read(reinterpret_cast<char *>(&raw_string), size);
	replay_identifier_ = raw_string;
}