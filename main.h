#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <cstdlib>
#include <ctime>
#include "Error.h"

inline void release_interface(IUnknown* iface)
{
    if( iface != NULL )
        iface->Release();
}
