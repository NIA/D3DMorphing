#include "main.h"
#include "Application.h"

INT WINAPI wWinMain( HINSTANCE, HINSTANCE, LPWSTR, INT )
{
    srand( static_cast<unsigned>( time(NULL) ) );

    try
    {
        Application app;

        const Vertex pyramid_vertices[]=
        {
            Vertex(D3DXVECTOR3(  1.0f, -1.0f,  0.00f )),
            Vertex(D3DXVECTOR3( -1.0f, -1.0f,  0.00f )),
            Vertex(D3DXVECTOR3( -1.0f,  1.0f,  0.00f )),
            Vertex(D3DXVECTOR3(  1.0f,  1.0f,  0.00f )),
            Vertex(D3DXVECTOR3(  0.0f,  0.0f,  1.41f )),
            Vertex(D3DXVECTOR3(  0.0f,  0.0f, -1.41f )),
        };
        const WORD pyramid_indices[] =
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
        const unsigned VERTICES_NUM = sizeof(pyramid_vertices)/sizeof(pyramid_vertices[0]);
        const unsigned INDICES_NUM = sizeof(pyramid_indices)/sizeof(pyramid_indices[0]);

        Model pyramid( app.get_device(),
                    D3DPT_TRIANGLELIST,
                    pyramid_vertices,
                    VERTICES_NUM,
                    pyramid_indices,
                    INDICES_NUM,
                    triangles_count(INDICES_NUM) );
        
        app.add_model(pyramid);
        app.run();
    }
    catch(RuntimeError &e)
    {
        const TCHAR *MESSAGE_BOX_TITLE = _T("Cube error!");
        MessageBox(NULL, e.message(), MESSAGE_BOX_TITLE, MB_OK | MB_ICONERROR);
        return -1;
    }
    return 0;
}
