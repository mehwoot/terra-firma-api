#pragma once

#include <Api/v0/Layers.h>
#include <Api/v0/Rasteriser.h>
#include <Api/v0/Vector.h>
#include <Api/v0/World.h>

typedef void* tf_v0_ContextPtr;

typedef enum tf_v0_HeightMode {
	TF_V0_HM_LAND_ONLY,
	TF_V0_HM_WATER_ONLY,
	TF_V0_HM_LAND_AND_WATER
} tf_v0_HeightMode;

typedef struct tf_v0_HeightCache {
	tf_v0_ContextPtr ctx;

	float (*getDataHeight)(tf_v0_ContextPtr ctx, tf_v0_ivec2 position, tf_v0_HeightMode heightMode);
	float (*getHeightAt)(tf_v0_ContextPtr ctx, tf_v0_vec2 position, tf_v0_HeightMode heightMode);
	tf_v0_vec3 (*getNormalAt)(tf_v0_ContextPtr ctx, tf_v0_vec2 position);
	tf_v0_ivec2 (*getDataPosition)(tf_v0_ContextPtr ctx, tf_v0_vec2 position);
} tf_v0_HeightCache;

typedef struct tf_v0_WorldConfig {
	tf_v0_ContextPtr ctx;

	float minHeight;
	float maxHeight;
	float seaLevelMetres;

	tf_v0_ivec2 size;
	tf_v0_ivec2 dimensions;

	char* (*getName)(tf_v0_ContextPtr ctx);
	float (*simulationCellsToWorldMetres)(tf_v0_ContextPtr ctx, float simulationCells);
	float (*worldMetresToSimulationCells)(tf_v0_ContextPtr ctx, float worldMetres);
	float (*simulationUnitsToWorldMetres)(tf_v0_ContextPtr ctx, float simulationUnits);
	float (*worldMetresToSimulationUnits)(tf_v0_ContextPtr ctx, float worldMetres);

	float (*getTemperatureCelsius)(tf_v0_ContextPtr ctx, float landHeight, tf_v0_vec2 relativeWorldPosition, float dayOfYear);
	double (*getGameDaysOfYear)(tf_v0_ContextPtr ctx);
} tf_v0_WorldConfig;

typedef struct tf_v0_WorldData {
	tf_v0_ContextPtr ctx;
	tf_v0_ivec2 dimensions;
	tf_v0_ivec2 size;
	int resolution;

	tf_v0_WaterFormat* waterArray;
	tf_v0_WaterRow0* waterRow0;
	tf_v0_WaterOffsetFormat* waterOffsetArray;
	tf_v0_Render_WaterFormat* waterRenderArray;
	tf_v0_Render_LandFormat* landRenderArray;
	tf_v0_RockPropertiesFormat* rockPropertiesArray;
	tf_v0_Biomes_BiomeFormat* biomeData;
	tf_v0_IceFormat* iceData;
	tf_v0_TemperatureRow0Format* temperatureData;
	tf_v0_LavaFormat* lavaData;
	tf_v0_LandHeightFormat* landHeightData;

	tf_v0_HeightCache heightCache;

	tf_v0_WorldConfig worldConfig;
} tf_v0_WorldData;

typedef struct tf_v0_ExportOptions {
	char* filename;
	char* folder;
} tf_v0_ExportOptions;

typedef struct tf_v0_ExportDataApi {
	tf_v0_ContextPtr ctx;

	void (*setProgress)(tf_v0_ContextPtr ctx, float progress);
	float (*getProgress)(tf_v0_ContextPtr ctx);
	void (*setCancelled)(tf_v0_ContextPtr ctx, int cancelled);
	int (*getCancelled)(tf_v0_ContextPtr ctx);

	tf_v0_WorldData (*getWorldData)(tf_v0_ContextPtr ctx);

	tf_v0_ExportOptions (*getOptions)(tf_v0_ContextPtr ctx);

	/* Read a value set by a control this plugin added via tf_v0_GuiApi, keyed by the id it was
	 * added with.  Missing int ids return 0; missing string ids return NULL.  Returned strings
	 * are only valid for the duration of the doExport call. */
	int (*getConfigValueInt)(tf_v0_ContextPtr ctx, const char* id);
	const char* (*getConfigValueString)(tf_v0_ContextPtr ctx, const char* id);

	// char const* (*getExporterName)(tf_v0_ContextPtr ctx);

} tf_v0_ExportDataApi;
