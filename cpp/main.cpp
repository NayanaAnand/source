#include <iostream>
#include "ossie/ossieSupport.h"

#include "source.h"
int main(int argc, char* argv[])
{
    source_i* source_servant;
    Component::start_component(source_servant, argc, argv);
    return 0;
}

