#ifndef DataCollector_base_h
#define DataCollector_base_h

class DataCollector_base
{
public:
    virtual float publish();
    virtual String prettyPublish();
};

#endif