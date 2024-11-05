//#include <SDL3/SDL.h>
//#include <SDL3/SDL_main.h>
//#include <SDL3/SDL_render.h>

#include "application.h"

#include <math.h>

int main(int argc, char** argv)
{   // Create the application
    Application app("epic swag window B)", 800, 600);
    
    // Run game loop
    app.Run();
    
    // Application destructor should take care of graceful exit for us.
    
    // return 0; - IMPLICIT
}
