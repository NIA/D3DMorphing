#pragma once
#include "main.h"
#include "Vertex.h"

// These must be macros, not constants, because they must be known at compile-time (they are used for array initialization)
#define TESSELATE_DEGREE 20

// Counts - per one tesselated triangle
#define TESSELATED_VERTICES_COUNT ((TESSELATE_DEGREE+1)*(TESSELATE_DEGREE+2)/2)
#define TESSELATED_INDICES_COUNT (3*TESSELATE_DEGREE*TESSELATE_DEGREE)

// Divides each side of triangle into given number of parts
// Writes data into arrays given as `res_vertices' and `res_indices',
//   assuming that there are already `res_vertices_offset' vertices before `res_vertices' pointer.
void tessellate(const Vertex *src_vertices, const Index *src_indices, DWORD src_index_offset,
                Vertex *res_vertices, Index res_vertices_offset, Index *res_indices);
