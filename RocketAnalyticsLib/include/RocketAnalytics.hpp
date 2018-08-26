/******************************************************************************
 *	Author:	Michael Doyle
 *	Date:	8/16/18
 *	File:	RocketAnalytics.hpp
 *	Description:
 *		Public interface for parsing Rocket League replay files with
 *	RocketAnalytics.
 *****************************************************************************/

#ifndef ROCKETANALYTICS_HPP
#define ROCKETANALYTICS_HPP

#include "ReplayFile.hpp"
#include <memory>

namespace rocketanalytics {

	class ReplayFile {
	  public:
	    explicit ReplayFile(std::string file);

	    ReplayHeader header();
      std::vector<std::string> levels();
      std::vector<Keyframe> keyframes();
      Netstream netstream();
      std::vector<ReplayTick> tick_information();
      std::vector<std::string> replicated_packages();
      std::vector<std::string> object_table();
      std::vector<std::string> name_table();
      std::vector<std::pair<std::string, std::uint32_t>> class_index_map();
      std::vector<ClassNetCacheObject> class_net_cache();
      std::string serialize_to_json();

	  private:
      std::unique_ptr<ReplayFileImpl> d_ptr;
	};

}

#endif
