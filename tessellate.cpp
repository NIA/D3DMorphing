#include "tessellate.h"

void add_triangle( WORD i1, WORD i2, WORD i3, WORD *indices, WORD &ci )
{
    indices[ci++] = i1;
    indices[ci++] = i2;
    indices[ci++] = i3;
}

void tessellate(const Vertex *src_vertices,
                const WORD *src_indices, const WORD index_offset,
                Vertex **res_vertices, WORD **res_indices)
// Divides each side of triangle into given number of parts
{
    Vertex *vertices = new Vertex[TESSELATED_VERTICES_COUNT];
    WORD *indices = new WORD[TESSELATED_INDICES_COUNT];
    
    const WORD i1 = src_indices[index_offset];
    const WORD i2 = src_indices[index_offset + 1];
    const WORD i3 = src_indices[index_offset + 2];
    const D3DXVECTOR3 step_down = (src_vertices[i1].pos - src_vertices[i2].pos)/TESSELATE_DEGREE;
    const D3DXVECTOR3 step_right = (src_vertices[i3].pos - src_vertices[i1].pos)/TESSELATE_DEGREE;

    vertices[0] = src_vertices[i2];
    WORD cv = 1; // current vertex
    WORD ci = 0; // current index
    
    D3DXVECTOR3 start_pos = vertices[0].pos;
    for( unsigned line = 1; line <= TESSELATE_DEGREE; ++line )
    {
        for( unsigned column = 0; column < line + 1; ++column ) // line #1 contains 2 vertices
        {
            vertices[cv] = Vertex( start_pos + line*step_down + column*step_right );
            if( column != 0 ) // not first coumn
            {
                // add outer triangle
                add_triangle( cv, cv - 1, cv - line - 1, indices, ci );
            }
            if( ( column != 0 ) && ( column != line ) ) // not first and not last column
            {
                // add inner triangle
                add_triangle(  cv, cv - line - 1, cv - line, indices, ci );
            }
            ++cv;
        }
    }

    *res_vertices = vertices;
    *res_indices = indices;
}