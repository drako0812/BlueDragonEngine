module bde.errors;

import <string>;
import <exception>;
import <stdexcept>;

namespace bde {

    BDEException::BDEException(std::string const & what) : std::runtime_error{ what } {}

}
