#include <string>
#include <math.h>

#include "application.h"

// Default value for s_InitializedSDL
bool Application::s_InitializedSDL = false;

// Static methods
void Application::InitializeSDL()
{   // Check that SDL isn't already initialized
    if (s_InitializedSDL)
    {
        SDL_Log("ERROR::Application:\nApplication has already been initialized");
    }
    
    int success = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    if (success < 0)
    {   // Wuh oh! log sdl init error
        SDL_Log("ERROR::SDL_Init:\n%s", SDL_GetError());
    }
    
}


// CONSTRUCTOR
Application::Application(const char* title, int width, int height)
    : m_Running(false)
{   // Initialize Logger
    m_Logger = std::make_shared<Logger>(LogLevel::TRACE);
    
    // Create window
    m_Window = std::make_shared<Window>(title, width, height);
}
// DESTRUCTOR
Application::~Application()
{
    
}

// RUN LOOP
void Application::Run()
{   
    // Create renderer
    // TODO: Abstract renderer into Renderer object stored in the application class
    SDL_Renderer* renderer = nullptr;
    renderer = SDL_CreateRenderer((SDL_Window*)m_Window->GetNativeWindow(), nullptr);
    // Check renderer creation success
    if (renderer == nullptr)
    {   // Log window error
        std::string message = "SDL Renderer Failed to create:\n";
        message += SDL_GetError();
        // Log error
        m_Logger->LogError(message.c_str());
    }
 
    // Set rendering to true and start loop
    m_Running = true;
    while (m_Running)
    {
        // Poll through all events and dispatch them
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_EVENT_QUIT:
                    m_Logger->LogInfo("Quitting application...");
                    m_Running = false;
            }
        }
        
        // Game updating
        // Set render color
        float PI = 3.1415926f;
        float time = (float)SDL_GetTicks() / 1000.0f;
        
        float blue  = (sin(time) * 0.5 + 0.5) * 255.0;
        float green = (sin(time + PI / 2.0f) * 0.5 + 0.5) * 255.0;
        float red   = (sin(time + 2.5 * PI / 2.0f) * 0.5 + 0.5) * 255.0;
        SDL_SetRenderDrawColor(renderer, (int)red, (int)green, (int)blue, 255);
        
        // Rendering
        // Clear the screen
        SDL_RenderClear(renderer);
        
        // Display rendered contents to the screen
        SDL_RenderPresent(renderer);
        SDL_Delay(1); // Is this necessary?
    }
}
