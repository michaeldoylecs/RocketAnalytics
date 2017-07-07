// Author: Michael Doyle
// Date: 6/10/17
// Replay.hpp


#ifndef REPLAY_H
#define REPLAY_H

#include <string>
#include <cstdint>
#include <vector>
#include "ReplayProperty.hpp"


class Replay {

	private:
		static int								replay_count_;
		std::string								filepath_;
		std::int32_t							part1_length_;
		std::int32_t							part1_crc_;
		std::int32_t							version_major_;
		std::int32_t							version_minor_;
		std::string								replay_identifier_;
		std::int32_t							part2_length_;
		std::int32_t							part2_crc_;
		std::int32_t							level_length_;
		std::vector<ReplayProperty::Property>	properties_;

		// Parsing functions
		void			parse_part1_length(std::ifstream &br);
		void			parse_part1_crc(std::ifstream &br);
		void			parse_version_major(std::ifstream &br);
		void			parse_version_minor(std::ifstream &br);
		void			parse_replay_identifier(std::ifstream &br);
		void			parse_replay_properties(std::ifstream &br);

		// Helping functions
		void			read_property_value(std::ifstream &br, char* type, ReplayProperty::Property* property);
			
			

	public:
		// Constructors
		Replay(std::string filepath);
		Replay();
		~Replay();

		// Getters
		static int		replay_count(void);
		std::string		filepath(void) const;
		std::int32_t	part1_length(void) const;
		std::int32_t	part1_crc(void) const;
		std::int32_t	version_major(void) const;
		std::int32_t	version_minor(void) const;
		std::string		replay_identifier(void) const;
		std::int32_t	part2_length(void) const;
		std::int32_t	part2_crc(void) const;
		std::int32_t	level_length(void) const;

		// Other
		std::string		to_string(void);
		void			parse();
		
};

#endif