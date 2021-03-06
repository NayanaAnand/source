#include "source_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

source_base::source_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    //setThreadName(label);

    loadProperties();

    output = new bulkio::OutShortPort("output");
    //output->setLogger(this->_baseLog->getChildLogger("output", "ports"));
    addPort("output", output);
}

source_base::~source_base()
{
    output->_remove_ref();
    output = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void source_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Component::start();
    ThreadedComponent::startThread();
}

void source_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void source_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void source_base::loadProperties()
{
    addProperty(xfer_length,
                100000,
                "xfer_length",
                "",
                "readwrite",
                "",
                "external",
                "property");

}



