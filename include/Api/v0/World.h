#pragma once

typedef void* tf_v0_ContextPtr;

typedef struct tf_v0_World_Dims{
    int x;
    int y;
} tf_v0_World_Dims;

typedef struct tf_v0_World{
    tf_v0_ContextPtr ctx;

    //void                (* setConfig        )(void* world, void* config);
    tf_v0_World_Dims    (* getDimensions    )(void* world);
    int                 (* getMinResolution )(void* world);
    int                 (* getMaxResolution )(void* world);
    int                 (* getResolution    )(void* world);
}tf_v0_World;
