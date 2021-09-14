#include"sampleplugin.h"

extern "C" Plugin* Create()
{
        return new SamplePlugin();
}


extern "C" void Destory(Plugin* plugin)
{
        delete plugin;
}
