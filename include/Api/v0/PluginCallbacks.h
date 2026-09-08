#pragma once

#include <Api/v0/ExporterCallbacks.h>

typedef struct tf_v0_GameApi tf_v0_GameApi;

typedef struct tf_v0_PluginCallbacks {

    char* pluginFriendlyName;

    /**
     * This is called after all modules are loaded and all their plugins are
     * registered This is so plugins have an opportunity to coordinate with
     * other plugins as near as possible to initial loading while making sure
     * the other plugins are also already registered and instantiated if they
     * are present
     *
     * @param gameApi the GameApi for this specific plugin instance
     */
    void (*load)(tf_v0_GameApi gameApi);

    /**
     * Called by plugin system when it's time to delete and deallocate your
     * plugins
     */
    void (*unload)();

    /* ==== Exporting ==== */

    /**
     * @brief function pointer to tell Game how to interact with the plugin for
     * the purposes of exporting, if the plugin supports acting as an exporter
     *
     * leave/set this function pointer to null to specify that this plugin does
     * not support exporting
     */
    tf_v0_ExporterCallbacks (*getExporterCallbacks)();

} tf_v0_PluginCallbacks;
