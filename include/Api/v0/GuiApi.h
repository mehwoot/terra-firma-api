#pragma once

typedef void* tf_v0_ContextPtr;

/*
 * Passed to a plugin's makeExporterConfigurationUI callback.  Each add function appends one
 * control to that plugin's export panel, in call order.  `id` is the key used to read the
 * configured value back during export (see getConfigValueInt/getConfigValueString on
 * tf_v0_ExportDataApi); `label` is the text displayed next to the control.
 *
 * Values read back during export:
 *   - selector int:    the chosen entry of `choices` (getConfigValueInt)
 *   - toggle:          1 or 0 (getConfigValueInt)
 *   - slider int:      the slider value (getConfigValueInt)
 *   - input int:       the entered number (getConfigValueInt)
 *   - selector string: the chosen entry of `choices` (getConfigValueString)
 */
typedef struct tf_v0_GuiApi {

	tf_v0_ContextPtr ctx;

	void (*addFixedAlternativesSelectorInt)(tf_v0_ContextPtr ctx, const char* id, const char* label, const int* choices, int choiceCount, int defaultIndex);
	void (*addBinaryToggle)(tf_v0_ContextPtr ctx, const char* id, const char* label, int defaultValue);
	void (*addSliderInt)(tf_v0_ContextPtr ctx, const char* id, const char* label, int low, int high, int step, int defaultValue);
	void (*addArbitraryInputInt)(tf_v0_ContextPtr ctx, const char* id, const char* label, int defaultValue);
	void (*addFixedAlternativesSelectorString)(tf_v0_ContextPtr ctx, const char* id, const char* label, const char* const* choices, int choiceCount, int defaultIndex);

} tf_v0_GuiApi;
