#include <SDL3/SDL.h>

#include <iostream>
#include <string>

//#include "application.h"

#include "window.h"

Window::Window(const char* title, int width, int height) : m_Data(title, width, height, nullptr)
{   // Create SDL window
    
    // Last parameter is flags. This is where I could, for example put SDL_WINDOW_OPENGL
    SDL_Window* window = SDL_CreateWindow(m_Data.Title, m_Data.Width, m_Data.Height, 0);
    // Check window creation success
    if (window == nullptr)
    {   // Log window error
        std::string message = "Failed to create SDL window\n";
        message += SDL_GetError();
        std::cout << message.c_str() << "\n";
    }
    
    // Set it in m_Data
    m_Data.NativeWindow = window;
    
}

// GETTERS
void* Window::GetNativeWindow()
{
    return m_Data.NativeWindow;
}
