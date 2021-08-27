export module bde.base;

import <string>;
import <memory>;

namespace bde {

    export template<class Type> using sptr_t = std::shared_ptr<Type>;
    export template<class Type> using uptr_t = std::unique_ptr<Type>;

    export template<class Type> using ptr = Type *;
    export template<class Type> using sptr = sptr_t<Type>;
    export template<class Type> using uptr = uptr_t<Type>;

    export using error = std::string;

}
