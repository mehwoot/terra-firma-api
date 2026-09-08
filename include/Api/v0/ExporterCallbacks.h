#pragma once

#include <Api/v0/ExporterApi.h>
#include <Api/v0/GuiApi.h>

typedef struct tf_v0_ExporterCallbacks {
	void (*doExport)(tf_v0_ExportDataApi exportData);
	void (*makeExporterConfigurationUI)(tf_v0_GuiApi guiApi);
	char* exporterButtonHoverText;
	char* exporterButtonIconPath;
} tf_v0_ExporterCallbacks;
