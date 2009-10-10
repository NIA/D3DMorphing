#include "main.h"
#include "Application.h"
#include "tessellate.h"

INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, INT )
{
    srand( static_cast<unsigned>( time(NULL) ) );
    Vertex *triangle_vertices = NULL;
    Index *triangle_indices = NULL;

    try
    {
        Application app;

        const Index PLANES_PER_PYRAMID = 8;
        const Vertex pyramid_vertices[]=
        {
            Vertex(D3DXVECTOR3(  1.0f, -1.0f,  0.00f )),
            Vertex(D3DXVECTOR3( -1.0f, -1.0f,  0.00f )),
            Vertex(D3DXVECTOR3( -1.0f,  1.0f,  0.00f )),
            Vertex(D3DXVECTOR3(  1.0f,  1.0f,  0.00f )),
            Vertex(D3DXVECTOR3(  0.0f,  0.0f,  1.41f )),
            Vertex(D3DXVECTOR3(  0.0f,  0.0f, -1.41f )),
        };
        const Index pyramid_indices[PLANES_PER_PYRAMID*VERTICES_PER_TRIANGLE] =
        {
            0, 4, 3,
            3, 4, 2,
            2, 4, 1,
            1, 4, 0,

            0, 3, 5,
            3, 2, 5,
            2, 1, 5,
            1, 0, 5,
        };

        const Index ALL_TESSELATED_VERTICES_COUNT = PLANES_PER_PYRAMID*TESSELATED_VERTICES_COUNT; // per 8 tessellated triangles
        const DWORD ALL_TESSELATED_INDICES_COUNT = PLANES_PER_PYRAMID*TESSELATED_INDICES_COUNT; // per 8 tessellated triangles

        triangle_vertices = new Vertex[ALL_TESSELATED_VERTICES_COUNT];
        triangle_indices = new Index[ALL_TESSELATED_INDICES_COUNT];

        for( DWORD i = 0; i < PLANES_PER_PYRAMID; ++i )
        {
            tessellate( pyramid_vertices, pyramid_indices, i*VERTICES_PER_TRIANGLE,
                        &triangle_vertices[i*TESSELATED_VERTICES_COUNT], i*TESSELATED_VERTICES_COUNT,
                        &triangle_indices[i*TESSELATED_INDICES_COUNT] );
        }
        
        Model triangle( app.get_device(),
                        D3DPT_TRIANGLELIST,
                        triangle_vertices,
                        ALL_TESSELATED_VERTICES_COUNT,
                        triangle_indices,
                        ALL_TESSELATED_INDICES_COUNT,
                        ALL_TESSELATED_INDICES_COUNT/VERTICES_PER_TRIANGLE );

        app.add_model(triangle);
        app.run();

        delete_array(&triangle_indices);
        delete_array(&triangle_vertices);
    }
    catch(RuntimeError &e)
    {
        delete_array(&triangle_indices);
        delete_array(&triangle_vertices);

        const TCHAR *MESSAGE_BOX_TITLE = _T("Cube error!");
        MessageBox(NULL, e.message(), MESSAGE_BOX_TITLE, MB_OK | MB_ICONERROR);
        return -1;
    }
    return 0;
}
