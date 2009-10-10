#include "tessellate.h"

const unsigned TESSELATE_DEGREE = 65;
const unsigned TESSELATED_VERTICES_COUNT = (TESSELATE_DEGREE+1)*(TESSELATE_DEGREE+2)/2;
const unsigned TESSELATED_INDICES_COUNT = 3*TESSELATE_DEGREE*TESSELATE_DEGREE;

void add_triangle( WORD i1, WORD i2, WORD i3, WORD *indices, WORD &current_index )
{
    indices[current_index++] = i1;
    indices[current_index++] = i2;
    indices[current_index++] = i3;
}

void tessellate(const Vertex *src_vertices,
                const WORD *src_indices, const WORD index_offset,
                Vertex **res_vertices, WORD **res_indices)
// Divides each side of triangle into given number of parts
{
    Vertex *vertices = new Vertex[TESSELATED_VERTICES_COUNT];
    WORD *indices = new WORD[TESSELATED_INDICES_COUNT];
    
    // i1, i2 i3 are indices of source triangle vertices
    const WORD i1 = src_indices[index_offset];
    const WORD i2 = src_indices[index_offset + 1];
    const WORD i3 = src_indices[index_offset + 2];
    const D3DXVECTOR3 step_down = (src_vertices[i1].pos - src_vertices[i2].pos)/TESSELATE_DEGREE;
    const D3DXVECTOR3 step_right = (src_vertices[i3].pos - src_vertices[i1].pos)/TESSELATE_DEGREE;

    vertices[0] = src_vertices[i2];
    WORD vertex = 1; // current vertex
    WORD index = 0; // current index
    
    D3DXVECTOR3 start_pos = vertices[0].pos;
    for( WORD line = 1; line <= TESSELATE_DEGREE; ++line )
    {
        for( WORD column = 0; column < line + 1; ++column ) // line #1 contains 2 vertices
        {
            vertices[vertex] = Vertex( start_pos
                               + static_cast<FLOAT>(line)*step_down
                               + static_cast<FLOAT>(column)*step_right );
            if( column != 0 ) // not first coumn
            {
                // add outer triangle
                add_triangle( vertex, vertex - 1, vertex - line - 1, indices, index );
            }
            if( ( column != 0 ) && ( column != line ) ) // not first and not last column
            {
                // add inner triangle
                add_triangle(  vertex, vertex - line - 1, vertex - line, indices, index );
            }
            ++vertex;
        }
    }

    *res_vertices = vertices;
    *res_indices = indices;
}