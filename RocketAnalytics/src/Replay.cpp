// Author: Michael Doyle
// Date: 6/13/17
// Replay.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/Replay.hpp"
#include "../include/ReplayProperty.hpp"


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
		<< "properties: \n\t" << properties_.front()->key << "\n\t" << properties_.front()->value.i32 << '\n'; //HACK: Only looking at first property in first array index
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

// Parse all properties in replay file.
// Assumeds the ifstream is pointed at the currect file position.
void Replay::parse_replay_properties(std::ifstream &br) {

	while (true) { // While 'None' was not read (exits internally)

		ReplayProperty::Property * property = read_property(br);

		// Check whether the 'None' key is read
		// If so, exit the function.
		// Else, read the property
		if (property->type == ReplayProperty::None) {
			delete property;
			return;
		}
		else {
			properties_.push_back(property); // Read property
		}
	}
}

ReplayProperty::Property * Replay::read_property(std::ifstream &br) {
	std::int32_t key_length;	// Length of key to read
	std::string key_name;		// Key name
	std::int32_t type_length;
	std::string  type_string;
	ReplayProperty::Property * property = new ReplayProperty::Property(); // Initialize ReplayProperty

	// Read key length
	br.read(reinterpret_cast<char *>(&key_length), sizeof(key_length));

	// Read key
	br.read(reinterpret_cast<char *>(&key_name), key_length);

	// Assign key to property
	property->key = key_name;

	// If the key_name is 'None', assign None Type and return property.
	if (key_name == type_to_string(ReplayProperty::None)) {
		property->type = ReplayProperty::None;
		return property;
	}

	// Read type length
	br.read(reinterpret_cast<char *>(&type_length), sizeof(type_length));

	// Read property type
	br.read(reinterpret_cast<char *>(&type_string), type_length);

	// Determine the type of property which must be read
	if (type_string == type_to_string(ReplayProperty::IntProperty)) { // IntProperty
		property->type = ReplayProperty::IntProperty;
		property->set_int(read_int_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::StrProperty)) { // StrProperty
		property->type = ReplayProperty::StrProperty;
		property->set_str(read_str_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::NameProperty)) { // NameProperty
		property->type = ReplayProperty::NameProperty;
		property->set_name(read_name_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::BoolProperty)) { // BoolProperty
		property->type = ReplayProperty::BoolProperty;
		property->set_bool(read_bool_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::QWordProperty)) { // QWordProperty
		property->type = ReplayProperty::QWordProperty;
		property->set_qword(read_qword_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::ByteProperty)) { // ByteProperty
		property->type = ReplayProperty::ByteProperty;
		property->set_byte(read_byte_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::FloatProperty)) { // FloatProperty
		property->type = ReplayProperty::FloatProperty;
		property->set_float(read_float_property(br));
	}
	else if (type_string == type_to_string(ReplayProperty::ArrayProperty)) { // ArrayProperty
		property->type = ReplayProperty::ArrayProperty;
		property->set_array(read_array_property(br));
	}

	return property;
}

// Read Integer from replay file and return it
std::int32_t Replay::read_int_property(std::ifstream &br) {
	std::int32_t value;
	br.seekg(8, std::ios::cur);			// Next 8 bytes are always "04 00 00 00 00 00 00 00"
	br.read(reinterpret_cast<char *>(&value), sizeof(value));
	return value;
}

// Read String from replay file and return it
std::string Replay::read_str_property(std::ifstream &br) {
	std::int64_t string_size;												// Buffer to read string size
	std::string value;
	br.read(reinterpret_cast<char *>(&string_size), sizeof(string_size));	// Get string size to read
	br.read(reinterpret_cast<char *>(&value), string_size);					// Read string from file
	return value;
}

// Read Name from replay file and return it
// * Currently does the same thing as read_str_property
std::string Replay::read_name_property(std::ifstream &br) {
	std::int64_t name_size;												// Buffer to read name size
	std::string value;
	br.read(reinterpret_cast<char *>(&name_size), sizeof(name_size));	// Get name size to read
	br.read(reinterpret_cast<char *>(&value), name_size);				// Read name from file
	return value;
}

// Read Bool from replay file and return it
bool Replay::read_bool_property(std::ifstream &br) {
	bool value;
	br.seekg(8, std::ios::cur);						// Next 8 bytes are always "00 00 00 00 00 00 00 00"
	br.read(reinterpret_cast<char *>(&value), 1);	// Read bool from file
	return value;
}

// Read QWord from replay file and return it
std::int64_t Replay::read_qword_property(std::ifstream &br) {
	std::int64_t value;
	br.seekg(8, std::ios::cur);									// Next 8 bytes are always "08 00 00 00 00 00 00 00"	
	br.read(reinterpret_cast<char *>(&value), sizeof(value));	// Read QWord from file
	return value;
}

// Read Byte from replay file and return it
std::int8_t Replay::read_byte_property(std::ifstream &br) {
	std::int8_t value;	
	br.read(reinterpret_cast<char *>(&value), sizeof(value));	// Read Byte from file
	br.seekg(7, std::ios::cur);									// Next 7 bytes are always "00 00 00 00 00 00 00"
	return value;
}

// Read Float from replay file and return it
float Replay::read_float_property(std::ifstream &br) {
	float value;
	br.seekg(8, std::ios::cur);									// Next 8 bytes are always "08 00 00 00 00 00 00"
	br.read(reinterpret_cast<char *>(&value), sizeof(value));	// Read Float from file
	return value;
}

// Read Vector from replay file and return it
std::vector< std::vector<ReplayProperty::Property *> > Replay::read_array_property(std::ifstream &br) {
	// TODO: Complete read_array_property
	std::int32_t size;													// Size buyffer
	std::vector<std::vector<ReplayProperty::Property *>> value_array;   // Vector to hold Property vectors
	br.seekg(8, std::ios::cur);											// Skip 8 bytes.	HACK: What do these skipped 8 bytes do?
	br.read(reinterpret_cast<char *>(&size), sizeof(size));				// Read array size from file
	
	for (int i = 0; i < size; i++) {
		std::vector<ReplayProperty::Property *> properties;
		while (true) {
			ReplayProperty::Property * property = read_property(br); // Read property
			if (property) {
				// Check whether the 'None' key is read
				// If so, exit the function.
				// Else, add property to vector
				if (property->type == ReplayProperty::None) {
					delete property;
					break;
				}
				else {
					properties.push_back(property);
				}
			}
		}
		value_array.push_back(properties); // Add list of properties to the ArrayList of Properties
	}

	return value_array;
}