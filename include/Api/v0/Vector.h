#pragma once

typedef struct tf_v0_vec2{
	float x;
	float y;
} tf_v0_vec2;

typedef struct tf_v0_ivec2{
	int x;
	int y;
} tf_v0_ivec2;

typedef struct tf_v0_vec3{
	float x;
	float y;
	float z;
} tf_v0_vec3;

typedef struct tf_v0_ivec3{
	int x;
	int y;
	int z;
} tf_v0_ivec3;


inline
tf_v0_ivec2 tf_v0_convertLocalToLocalInt(tf_v0_ivec2 from, int fromResolution, int toResolution) {
	int numerator = 1, denominator = 1;
	if (fromResolution > 0) {
		numerator *= fromResolution;
	} else {
		denominator *= -fromResolution;
	}
	if (toResolution > 0) {
		denominator *= toResolution;
	} else {
		numerator *= -toResolution;
	}
	tf_v0_ivec2 toRet = {(from.x * numerator) / denominator, (from.y * numerator) / denominator};
	return toRet;
}

inline
tf_v0_ivec2 tf_v0_convertLocalToWorldInt(tf_v0_ivec2 from, int localResolution) {
	tf_v0_ivec2 converted = tf_v0_convertLocalToLocalInt(from, localResolution, 1);
	tf_v0_ivec2 toRet = {converted.x, converted.y};
	return toRet;
}

inline
tf_v0_ivec2 tf_v0_convertWorldToLocalInt(tf_v0_ivec2 from, int localResolution) {
	return tf_v0_convertLocalToLocalInt(from, 1, localResolution);
}

inline
tf_v0_ivec2 tf_v0_convertVec2ToIVec2(tf_v0_vec2 from){
	tf_v0_ivec2 toRet = {(int)from.x, (int)from.y};
	return toRet;
}

inline
tf_v0_vec2 tf_v0_convertIVec2ToVec2(tf_v0_ivec2 from){
	tf_v0_vec2 toRet = {(float)from.x, (float)from.y};
	return toRet;
}
