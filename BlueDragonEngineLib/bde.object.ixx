module;
#include "bde.export.hpp"
export module bde.object;

import bde.base;

export namespace bde {

    class Object {
    public:
        using ptr = ptr<Object>;
        using sptr = sptr<Object>;
        using uptr = uptr<Object>;

        BDE_API virtual ~Object();

        BDE_API virtual void OnConstruct();
        BDE_API virtual void OnDestruct();
    };
}
