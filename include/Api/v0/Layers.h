#pragma once

typedef struct tf_v0_WaterFormat {
	float landHeight;
	float waterHeight;
	float totalHeight;
	float waterFlowHeight;

	float flows[4];
	
	float primaryFlowDirection;
	float groundWater;
	float maxSlope;
	float rainfall;
	
	float oceanHeight;
	float sediment;
	float floodHeight;
	float unused1;

} tf_v0_WaterFormat;

typedef struct tf_v0_WaterRow0{
	float landHeight;
	float waterHeight;
	float totalHeight;
	float waterFlowHeight;
} tf_v0_WaterRow0;

typedef struct tf_v0_WaterOffsetFormat{
	float offsetX, offsetY, flipTriangles, flipTrianglesCounter;
}tf_v0_WaterOffsetFormat;

typedef struct tf_v0_Render_WaterFormat{
	float height, primaryFlowDirection, totalHeight, unused1;
}tf_v0_Render_WaterFormat;

typedef struct tf_v0_Render_LandFormat{
	float dirtCoverage;
	float groundwaterDisplay;
}tf_v0_Render_LandFormat;

typedef struct tf_v0_RockPropertiesFormat{
	float flags;
	/* Depth of dirt ontop of everything else */
	float dirtDepth;
	/* Type of rock underneath dirt */
	float rockType;
	/* Depth of rock */
	float rockDepth;

	float underneathRocks[4];
}tf_v0_RockPropertiesFormat;

typedef struct tf_v0_Biomes_BiomePoint {
	float id;
	float coverage;
	float treesColour;
	float underlayColour;
}tf_v0_Biomes_BiomePoint;

typedef struct tf_v0_Biomes_BiomeFormat{
	tf_v0_Biomes_BiomePoint biomes[2];
	float grassCoverage, grassColour, shrubsColour, marshCoverage;
}tf_v0_Biomes_BiomeFormat;

typedef struct tf_v0_IceRow0Format {
	float ice, sediment, iceMelt, erosion;
}tf_v0_IceRow0Format;

typedef struct tf_v0_IceRow1Format {
	float displayHeight, displayHeightCounter;
}tf_v0_IceRow1Format;

typedef struct tf_v0_IceRow2Format {
	float snowCoverage, unused;
}tf_v0_IceRow2Format;

typedef struct tf_v0_IceFormat{
	tf_v0_IceRow0Format row0;
	tf_v0_IceRow1Format row1;
	tf_v0_IceRow2Format row2;
}tf_v0_IceFormat;

typedef struct tf_v0_TemperatureRow0Format{
	float temperature, yearlyAverage, excessTemperature, unused1;
}tf_v0_TemperatureRow0Format;

typedef struct tf_v0_LavaFormat{
	float lavaHeight, unused1, slopeMagnitude, landAdd;
	float flows[4];
	float textureOffsetX, textureOffsetZ, lavaDisplayHeight, temperature;
	float lavaGenerateThisStep, lavaAdd, minSlope, lavaGenerateMinSlope;
}tf_v0_LavaFormat;

typedef struct tf_v0_LandHeightFormat{
	float height;
	float normalX;
	float normalZ;
	float totalHeight;
}tf_v0_LandHeightFormat;
