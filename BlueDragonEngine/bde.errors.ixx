export module bde.errors;

import <string>;
import <exception>;
import <stdexcept>;

namespace bde {

    export class BDEException : public std::runtime_error {
    public:
        BDEException(std::string const & what);
    };

    BDEException::BDEException(std::string const & what) : std::runtime_error{ what } {}
}
