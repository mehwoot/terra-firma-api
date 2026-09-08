#pragma once

#include <Api/v0/Vector.h>
#include <Api/v0/Rasteriser.h>
#include <Api/v0/ExporterApi.h>
#include <Api/v0/PluginCallbacks.h>
#include <Api/v0/PluginModuleApi.h>
#include <Api/v0/World.h>

typedef void* tf_v0_ContextPtr;

typedef void (* tf_v0_DebugButtonCallback) (void* data);

typedef struct tf_v0_GameApi
{
    /**
     * @brief plugin context. must be passed back as first argument to any api function call
     */
    tf_v0_ContextPtr ctx;

    /* ==== config ==== */

    char* (*getAssetsFolder)(tf_v0_ContextPtr ctx);

    /* ==== Logging and error reporting ==== */

    /**
     * @brief log a message
     *
     * @param context   see \ref context
     * @param logString message to log
     */
    void (*log)(tf_v0_ContextPtr ctx, char const *logString);

    /**
     * @brief report an error for which execution of the plugin's current action should cease, as well as logging the error
     * 
     */
    void (*reportFatalError)(tf_v0_ContextPtr ctx, char const *what);

    /**
     * @brief report an error which is continuable, but should be reported
     * 
     */
    void (*reportNonFatalError)(tf_v0_ContextPtr ctx, char const *what);

    /* ==== World ==== */
    tf_v0_World (*getWorld)(tf_v0_ContextPtr ctx);
    

	tf_v0_Rasteriser (*getNewRasteriser)(tf_v0_ContextPtr ctx, tf_v0_WorldData* worldData, tf_v0_ivec2 resolution);
	void (*deleteRasteriser)(tf_v0_ContextPtr ctx, tf_v0_Rasteriser* rasteriser);

    /* ==== Debug Facilities ==== */
    void (*registerDebugButton)(tf_v0_ContextPtr ctx, char const *buttonText, tf_v0_DebugButtonCallback onClick, void *data);

}tf_v0_GameApi;


