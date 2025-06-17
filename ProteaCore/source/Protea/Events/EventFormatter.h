#ifndef EVENTFORMATTER_H
#define EVENTFORMATTER_H

#include "spdlog/fmt/ostr.h"

//////////////////////////////////////////////////////////////////////////////////////////
/// TODO: Include formatting automatically or change the signature for Event returns
//////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
    requires std::is_base_of_v<Protea::Event, T>
struct fmt::formatter<T> : ostream_formatter {
};

#endif //EVENTFORMATTER_H
