#pragma once

#include <Api/v0/Vector.h>

typedef enum tf_v0_RockType {
	TF_V0_ROCK_DIRT = 0,
	TF_V0_ROCK_IGNEOUS = 1,
	TF_V0_ROCK_SEDIMENTARY = 2
} tf_v0_RockType;

typedef struct tf_v0_RockLayer{
	int rockType;
	float depth;
	float bottomLimit;
} tf_v0_RockLayer;

typedef enum tf_v0_BiomeType {
	TF_V0_BIOME_TEMPERATE_FOREST = 0,
	TF_V0_BIOME_BOREAL_FOREST = 1,
	TF_V0_BIOME_TROPICAL_RAINFOREST = 2,
	TF_V0_BIOME_OASIS = 3,
	TF_V0_BIOME_GRASSLANDS = 4,
	TF_V0_BIOME_SAVANNAH = 5,
	TF_V0_BIOME_MANGROVE_SWAMP = 6,
	TF_V0_BIOME_HOT_DESERT = 7,
	TF_V0_BIOME_SWAMP = 8,
	TF_V0_BIOME_MARSH = 9,
	TF_V0_BIOME_COLD_DESERT = 10,
	TF_V0_BIOME_TUNDRA = 11,
	TF_V0_BIOME_TEMPERATE_RAINFOREST = 12,
	TF_V0_BIOME_SHRUBLANDS = 13,
	TF_V0_BIOME_RIPARIAN = 14,
	TF_V0_BIOME_NOTHING = 15
} tf_v0_BiomeType;

typedef struct tf_v0_Biome{
	tf_v0_BiomeType biomeType;
	/* Between 0 and 1 */
	float coverage;
} tf_v0_Biome;

typedef struct tf_v0_WorldPoint{
	tf_v0_ivec2 localPosition;
	tf_v0_vec2 globalPostion;
	/* How far above or below sea level the top of the land is */
	float landHeight;
	/* Depth of water above the land height at this point */
	float waterHeight;
	/* Depth of the lava above the land height at this point */
	float lavaHeight;
	/* Temperature of the lava above the surroundings, from 0 to 1000 celcius */
	float lavaTemperature;
	/* The layers of rock or dirt at this point.  Ordered from top to bottom, depth represents the depth of each successive layer */
	tf_v0_RockLayer rockLayers[10];
	/* Biomes at this point.  The coverage of all the biomes will add up to 1.0 */
	tf_v0_Biome biomes[4];

	float grassCoverage, marshCoverage;
	tf_v0_vec3 grassColour;
	float iceDepth;
	int inSnow;
	/* Coverage of dirt at this point, between 0 and 1.  Sourced from the render:land layer.
	   0.f = fully sand, 1.f = fully dirt. */
	float dirtCoverage;
} tf_v0_WorldPoint;

typedef void* tf_v0_ContextPtr;

typedef struct tf_v0_Rasteriser{
	tf_v0_ContextPtr ctx;
	tf_v0_WorldPoint (* getWorldPoint )(tf_v0_ContextPtr instance, tf_v0_ivec2 position);
	int (*validPoint)(tf_v0_ContextPtr instance, tf_v0_ivec2 position);
} tf_v0_Rasteriser;
