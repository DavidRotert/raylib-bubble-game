#ifndef RAYENGINE_UTILS_HPP
#define RAYENGINE_UTILS_HPP

#include <type_traits>

namespace rayengine {

template<typename Base, typename T> inline bool instanceof(const T&) {
    return std::is_base_of_v<Base, T>;
}

}

#endif
