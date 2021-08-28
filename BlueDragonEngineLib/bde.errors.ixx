module;
#include "bde.export.hpp"
export module bde.errors;

import <string>;
import <exception>;
import <stdexcept>;

export namespace bde {

    class BDEException : public std::runtime_error {
    public:
        BDE_API BDEException(std::string const & what);
    };

}
