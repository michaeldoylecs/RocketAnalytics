// Author: Michael Doyle
// Date: 6/13/17
// Replay.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "Replay.hpp"
#include "ReplayProperty.hpp"


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
	// TODO: Deallocate Replay from memory
}


// Return the amount of Replay objects initialized
int Replay::replay_count(void) { return replay_count_; }


// Standard Getters
std::string		Replay::filepath(void) const			{ return filepath_; }
std::int32_t	Replay::part1_length(void) const		{ return part1_length_; }
std::int32_t	Replay::part1_crc(void) const			{ return part1_crc_; }
std::int32_t	Replay::version_major(void) const		{ return version_major_; }
std::int32_t	Replay::version_minor(void) const		{ return version_minor_; }
std::string		Replay::replay_identifier(void) const	{ return replay_identifier_; }
std::int32_t	Replay::part2_length(void) const		{ return part2_length_; }
std::int32_t	Replay::part2_crc(void) const			{ return part2_crc_; }
std::int32_t	Replay::level_length(void) const		{ return level_length_; }


// To string
std::string Replay::to_string(void) {
	std::stringstream output_stream;
	output_stream << "filepath: " << filepath_ << '\n'
		<< "part1_length: " << part1_length_ << '\n'
		<< "part1_crc: " << part1_crc_ << '\n'
		<< "version_major: " << version_major_ << '\n'
		<< "version_minor: " << version_minor_ << '\n'
		<< "replay_identifier: " << replay_identifier_ << '\n'
		<< "properties: \n\t" << properties_.front().key << "\n\t" << properties_.front().value.i32 << '\n';
	std::string output = output_stream.str();
	return output;
}


// Parse the entire replay file
void Replay::parse() {
	std::ifstream binary_reader(filepath_, std::ios::binary);

	if (!binary_reader) {
		//TODO: What happens if replay file does not open?
	}
	else {
		binary_reader.seekg(0, std::ostream::beg);
		parse_part1_length(binary_reader);
		parse_part1_crc(binary_reader);
		parse_version_major(binary_reader);
		parse_version_minor(binary_reader);
		parse_replay_identifier(binary_reader);
		binary_reader.close();
	}
}


// Assumes the ifstream is pointed at the correct file position
void Replay::parse_part1_length(std::ifstream &br) {
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
	std::int32_t size; // Size of the string to read
	char * raw_string; // string buffer

	br.read(reinterpret_cast<char *>(&size), sizeof(size)); // Read size integer from file
	raw_string = new char[size]; // Initialize string of length 'size'
	br.read(raw_string, size); // Read characters from file
	replay_identifier_ = raw_string; // Assign the read string as the replay_identifier_
	delete raw_string; // deallocate the string buffer
}

void Replay::parse_replay_properties(std::ifstream &br) {
	std::int32_t key_length;
	std::string key;

	ReplayProperty::Property * property; // Initialize ReplayProperty
	std::int32_t size; // Integer to hold length of string to read
	char * raw_string; // string buffer

	// Read key length
	br.read(reinterpret_cast<char *>(&size), sizeof(size));
	key_length = size;

	// Read key
	raw_string = new char[size];
	br.read(reinterpret_cast<char *>(&raw_string), size);
	delete raw_string; // Deallocate string in memory

	// Check whether the 'None' key is read
	// If so, exit the function.
	if (raw_string == ReplayProperty::PROPERTY_NONE) {
		return;
	}

	// Assign key to property
	key = raw_string;
	 
	// Read type length
	br.read(reinterpret_cast<char *>(&size), sizeof(size));
	
	// Read property type
	raw_string = new char[size];
	br.read(reinterpret_cast<char *>(&raw_string), size);

	if (raw_string == type_to_string(ReplayProperty::IntProperty)) { // IntProperty
		std::int32_t value = read_int_property(br);

	}
	else if (raw_string == type_to_string(ReplayProperty::StrProperty)) { // StrProperty
		property->type = ReplayProperty::StrProperty;						// Assign property type
		char * raw_string = new char[size];									// Initialize integer buffer 
		br.read(reinterpret_cast<char *>(&raw_string), sizeof(raw_string));	// Read integer from replay file
		property->value.s = raw_string;										// Assign string value to property
		delete raw_string;
	}
	else if (raw_string == type_to_string(ReplayProperty::NameProperty)) { // NameProperty
		property->type = ReplayProperty::NameProperty;
	}
	else if (raw_string == type_to_string(ReplayProperty::BoolProperty)) { // BoolProperty
		property->type = ReplayProperty::BoolProperty;
	}
	else if (raw_string == type_to_string(ReplayProperty::QWordProperty)) { // QWordProperty
		property->type = ReplayProperty::QWordProperty;
	}
	else if (raw_string == type_to_string(ReplayProperty::ByteProperty)) { // ByteProperty
		property->type = ReplayProperty::ByteProperty;
	}
	else if (raw_string == type_to_string(ReplayProperty::FloatProperty)) { // FloatProperty
		property->type = ReplayProperty::FloatProperty;
	}
	else if (raw_string == type_to_string(ReplayProperty::ArrayProperty)) { // ArrayProperty
		property->type = ReplayProperty::ArrayProperty;
	}
}

// Read integer from replay file and return it
std::int32_t read_int_property(std::ifstream &br) {
	std::int32_t raw_int;
	br.read(reinterpret_cast<char *>(&raw_int), sizeof(raw_int));
	return raw_int;
}