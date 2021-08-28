export module bde.base;

import <string>;
import <memory>;

export namespace bde {

    template<class Type> using sptr_t = std::shared_ptr<Type>;
    template<class Type> using uptr_t = std::unique_ptr<Type>;

    template<class Type> using ptr = Type *;
    template<class Type> using sptr = sptr_t<Type>;
    template<class Type> using uptr = uptr_t<Type>;

    using error = std::string;

}
