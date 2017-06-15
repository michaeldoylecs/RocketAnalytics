// Author: Michael Doyle
// Date: 6/10/17
// Replay.h


#ifndef REPLAY_H
#define REPLAY_H

#include <string>
#include <cstdint>


class Replay {

	private:
		static int		replay_count_;
		std::string		filepath_;
		std::int32_t	part1_length_;
		std::int32_t	part1_crc_;
		std::int32_t	version_major_;
		std::int32_t	version_minor_;
		std::string		replay_identifier_;
		std::int32_t	part2_length_;
		std::int32_t	part2_crc_;
		std::int32_t	level_length_;
			
			

	public:
		// Constructors
		Replay();
		Replay(std::string filepath);
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
		void			parse(std::ifstream &br);
		void			parse_part1(std::ifstream &br);
		void			parse_part1_crc(std::ifstream &br);
		void			parse_version_major(std::ifstream &br);
		void			parse_version_minor(std::ifstream &br);
		void			parse_replay_identifier(std::ifstream &br);
};

#endif