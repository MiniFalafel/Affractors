#pragma once

#include <SDL3/SDL.h>

#include <memory>

#include "core.h"
#include "window.h"


class Application
{
    // STATIC MEMBER
    static bool s_InitializedSDL;
    
    // PRIVATE MEMBERS
    std::shared_ptr<Logger> m_Logger;
    
    std::shared_ptr<Window> m_Window;
    bool m_Running;
    
public: // PUBLIC METHODS
    // STATIC METHODS
    static inline bool IsSDLInitialized() { return s_InitializedSDL; }
    
    // CONSTRUCTOR
    Application(const char* title, int width, int height);
    // DESTRUCTOR
    ~Application();
    
    // GAME LOOP
    void Run();
    
    
private: // PRIVATE METHODS
    static void InitializeSDL();
    
};
