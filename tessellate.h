#pragma once
#include "main.h"
#include "Vertex.h"

extern const unsigned TESSELATE_DEGREE;
extern const unsigned TESSELATED_VERTICES_COUNT;
extern const unsigned TESSELATED_INDICES_COUNT;

// Divides each side of triangle into given number of parts
void tessellate(const Vertex *src_vertices,
                const WORD *src_indices, const WORD index_offset,
                Vertex **res_vertices, WORD **res_indices);
