#pragma once

#include <Api/v0/PluginCallbacks.h>

typedef void* tf_v0_ContextPtr;

typedef struct tf_v0_PluginModuleApi
{
    /**
     * @brief plugins context. must be passed back as first argument to any api function call
     */
    tf_v0_ContextPtr ctx;

    /**
     * @brief register a plugin.
     *
     * @param context           see \ref context
     * @param pluginCallbacks   callback functions for the plugin
     */
    void (*registerPlugin)(tf_v0_ContextPtr ctx, tf_v0_PluginCallbacks pluginCallbacks);

}tf_v0_PluginModuleApi;

/**
*  This is called when the module is loaded to let you instantiate your plugins
*  You must call registerPlugin with the context and the callbacks for your plugin for each plugin you're registering in this module
*/
typedef void (*tf_v0_InitialisePluginModuleFunc)(tf_v0_PluginModuleApi pluginsApi);


#define TF_V0_DEFINE_INITIALISE_PLUGIN_MODULE_FUNC \
	__declspec(dllexport) void tf_v0_initialisePluginModule(tf_v0_PluginModuleApi pluginsApi)

#define TF_V0_INIT_PLUGIN_MODULE_FUNC_NAME_STR "tf_v0_initialisePluginModule"
