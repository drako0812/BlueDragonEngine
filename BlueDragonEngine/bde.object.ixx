export module bde.object;

import bde.base;

namespace bde {

    export class Object {
    public:
        using ptr = ptr<Object>;
        using sptr = sptr<Object>;
        using uptr = uptr<Object>;

        virtual ~Object() = 0;

        virtual void OnConstruct() { }
        virtual void OnDestruct() { }
    };
}
