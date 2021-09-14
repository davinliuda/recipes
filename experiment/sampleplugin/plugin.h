#ifndef _PLUGIN_H
#define _PLUGIN_H

class Plugin
{
public:
	virtual void Print() = 0;
};
typedef Plugin* (Create_t)();
typedef void (Destory_t)(Plugin*);
#endif
