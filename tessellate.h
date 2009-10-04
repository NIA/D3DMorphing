#pragma once
#include "main.h"
#include "Vertex.h"

const unsigned TESSELATE_DEGREE = 5;
const unsigned TESSELATED_VERTICES_COUNT = (TESSELATE_DEGREE+1)*(TESSELATE_DEGREE+2)/2;
const unsigned TESSELATED_INDICES_COUNT = 3*TESSELATE_DEGREE*TESSELATE_DEGREE;

// Divides each side of triangle into given number of parts
void tessellate(const Vertex *src_vertices,
                const WORD *src_indices, const WORD index_offset,
                Vertex **res_vertices, WORD **res_indices);
