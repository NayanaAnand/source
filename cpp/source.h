#ifndef SOURCE_I_IMPL_H
#define SOURCE_I_IMPL_H

#include "source_base.h"

class source_i : public source_base
{
    ENABLE_LOGGING
    public:
        source_i(const char *uuid, const char *label);
        ~source_i();

        void constructor();

        int serviceFunction();

        std::vector<short> data;

        bulkio::OutShortStream stream;

    protected:
};

#endif // SOURCE_I_IMPL_H
