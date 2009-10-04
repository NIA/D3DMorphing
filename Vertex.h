#pragma once
#include "main.h"

inline int rand_col_comp()
// Returns random color component: an integer between 0 and 255
{
    return rand()*255/RAND_MAX;
}

class Vertex
{
public:
    D3DXVECTOR3 pos; // The position for the vertex
    D3DCOLOR color; // The vertex color

    Vertex(D3DXVECTOR3 pos, D3DCOLOR color) : pos(pos), color(color) {}
    Vertex(D3DXVECTOR3 pos) : pos(pos)
    {
        color = D3DCOLOR_XRGB( rand_col_comp(), rand_col_comp(), rand_col_comp() );
    }
};

extern D3DVERTEXELEMENT9 VERTEX_DECL_ARRAY[];
