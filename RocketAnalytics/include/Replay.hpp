// Author: Michael Doyle
// Date: 6/10/17
// Replay.hpp


#ifndef REPLAY_H
#define REPLAY_H

#include <string>
#include <cstdint>
#include <vector>
#include "../include/ReplayProperty.hpp"


class ReplayProperty::Property;

class Replay {
	public:
		// Constructors
		Replay(std::string filepath);
		Replay();
		~Replay();

		// Getters
		static int		replay_count();
		std::string		filepath() const;
		std::int32_t	part1_length() const;
		std::int32_t	part1_crc() const;
		std::int32_t	version_major() const;
		std::int32_t	version_minor() const;
		std::string		replay_identifier() const;
		std::int32_t	part2_length() const;
		std::int32_t	part2_crc() const;
		std::int32_t	level_length() const;

		// Other
		std::string		to_string(void);
		void			parse();

	private:
		static int								replay_count_;
		std::string								filepath_;
		std::int32_t							part1_length_;
		std::int32_t							part1_crc_;
		std::int32_t							version_major_;
		std::int32_t							version_minor_;
		std::string								replay_identifier_;
		std::vector<ReplayProperty::Property*>	properties_;
		std::int32_t							part2_length_;
		std::int32_t							part2_crc_;
		std::int32_t							level_length_;

		// Parsing functions
		void	parse_part1_length(std::ifstream &br);
		void	parse_part1_crc(std::ifstream &br);
		void	parse_version_major(std::ifstream &br);
		void	parse_version_minor(std::ifstream &br);
		void	parse_replay_identifier(std::ifstream &br);
		void	parse_replay_properties(std::ifstream &br);

		// Helping property reader functions
		ReplayProperty::Property *								read_property(std::ifstream &br);
		std::int32_t											read_int_property(std::ifstream &br);
		std::string												read_str_property(std::ifstream &br);
		std::string												read_name_property(std::ifstream &br);
		bool													read_bool_property(std::ifstream &br);
		std::int64_t											read_qword_property(std::ifstream &br);
		std::int8_t												read_byte_property(std::ifstream &br);
		float													read_float_property(std::ifstream &br);
		std::vector< std::vector<ReplayProperty::Property *> >	read_array_property(std::ifstream &br);
};

#endif