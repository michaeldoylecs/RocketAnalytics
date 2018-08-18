# RocketAnalytics
> Parse Rocket League replay files *fast*.

RocketAnalytics is a Rocket League replay parsing static library. The goal of
 this library is to enable the ability to parse large quantities of replay
 files as fast as possible for statistical analysis purposes. This library
 would not have been possible if it were not for the hard work of the people
 found in [this thread](https://www.psyonix.com/forum/viewtopic.php?f=33&t=13656)
 on the offical Rocket League forums. Thank you very much for your hard work.

## Installation
There are two ways to access the library: downloading a release version, or
 building the library from source.

### Release Version
Library releases are tagged and released
 [here](https://github.com/michaeldoylecs/RocketAnalytics/releases).

### Source building
*Requires CMake 3.6+*  

Create a `build` directory in the root of the project folder:

```sh
$ mkdir build
```

Enter the `build` directory and type the following commands to create the make
 file and build the project:

```sh
$ cmake ..
$ make
```

This will create a few relevant files (among some less relevant ones):
 * `libRocketAnalytics` - The Rocket League parsing library
 * `unitTests` - The unitTests for libRocketAnalytics using gtest
 * `RocketAnalyticsApp` - A small app I use to test replay output

The most important of these is `libRocketAnalytics`, which you will use along
 with the header files located in `RocketAnalyticsLib/include` to utitize the
 library.

*Note: This library is currently only tested on Arch Linux, please report any
 issues in building or using on alternate systems.*

## Usage
The library is contained inside of the `rocketanalytics` namespace. The only
header file that needs to be included is `RocketAnalytics.hpp`. It contains
all of the necessary implementations to handle the replay file parsing.

Starting out, parsing a replay is very simple. All we need to do it give
the `ReplayFile` constructor a valid path to a replay file.

```cpp
#include "../include/RocketAnalytics.hpp"               // Include the header file
#include <string>                                       // (And the necessary STL headers)

int main() {
  std::string filename = "rocketleague.replay";         // An absolute or relative replay filepath.
  auto replay = rocketanalytics::ReplayFile(filename);  // Open and parse the replay file.
  return 0;
}
```

We now have a parsed replay file. So, what can we do with it? We can access
individual parts of the replay, or we can serialize the whole thing to JSON.

```cpp
#include "../include/RocketAnalytics.hpp"               // Include the header file
#include <iostream>                                     //
#include <string>                                       // (And the necessary STL headers)

int main() {
  std::string filename = "rocketleague.replay";         // An absolute or relative replay filepath.
  auto replay = rocketanalytics::ReplayFile(filename);  // Open and parse the replay file.

  auto replay_header = replay.header();                 // Get replay header information
  auto replay_keyframes = replay.keyframes();           // Get replay keyframe information
  std::cout << replay.serialize_to_json() << std::endl; // Print the replay JSON to standard output
  return 0;
}
```

Now we know how to get information out of the replay, but there is one last
important thing. Parsing a replay (or opening a file) can fail. Thus, we need
to include exception handling.

```cpp
#include "../include/RocketAnalytics.hpp"                 // Include the header file
#include <iostream>                                       //
#include <string>                                         // (And the necessary STL headers)

int main() {
  try {
    std::string filename = "rocketleague.replay";         // An absolute or relative replay filepath.
    auto replay = rocketanalytics::ReplayFile(filename);  // Open and parse the replay file.
    std::cout << replay.serialize_to_json() << std::endl; // Send the parsed information to standard output
    return 0;
  } catch (const std::runtime_error& e) {
    std::cout << "Replay file failed to parse" << std::endl;
  }
}
```

## Features

Does the library currently support a specific feature? Lets finds out!

| Does it parse...    | Answer             |
| ------------------- |:------------------:|
| Header CRC          | YES                |
| Replay version      | YES                |
| Replay ID           | YES                |
| Replay Properties   | YES                | 
| Body CRC            | YES                |
| Levels              | YES                |
| Keyframes           | YES                |
| Netstream           | **NO**<sup>1</sup> |
| Tick Information    | YES                |
| Replicated Packages | YES                |
| Object Table        | YES                |
| Name Table          | YES                |
| Class Index Map     | YES                |
| Class Net Cache     | YES                |

| Can it...              | Answer |
| ---------------------- |:------:|
| Verify header CRC      | **NO** |
| Verify Body CRC        | **NO** |
| Parse Netstream frames | **NO** |

*<sup>1</sup> Netstream byte data is accessible, but individual frames are not
 parsed.*

The function signatures for a ReplayFile can be found in
`include/ReplayFile.hpp`. Additional function signatures for class-specific
 values returned from a ReplayFile can also be found in their respective header
 files (e.g. `ReplayHeader.hpp`, `Keyframe.hpp`, `ReplayTick.hpp`, and
 `ClassNetCacheObject.hpp`).

## Issues
If you have any issues, please open a ticket
[here](https://github.com/michaeldoylecs/RocketAnalytics/issues). These could 
be, but is not limited to, technical issues or feature requests.
