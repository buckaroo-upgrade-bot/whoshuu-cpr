#include "parameters.h"

#include <initializer_list>
#include <string>

#include "util.h"

namespace cpr {

Parameters::Parameters(const std::initializer_list<Parameter>& parameters) {
    for (const auto& parameter : parameters) {
        if (!content.empty()) {
            content += "&";
        }
        auto escaped = cpr::util::urlEncode(parameter.value);
        content += parameter.key + "=" + escaped;
    }
}

} // namespace cpr
