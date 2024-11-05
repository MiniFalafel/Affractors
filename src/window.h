#pragma once

class Window
{
private:
    struct WindowData
    {
        const char* Title;
        int Width, Height;
        void* NativeWindow;
        
        // Constructor
        WindowData(const char* title, int width, int height, void* nativeWin)
            : Title(title), Width(width), Height(height), NativeWindow(nativeWin) {}
    };
    
    // PRIVATE MEMBERS
    WindowData m_Data;
    
public: // PUBLIC METHODS
    
    // CONSTRUCTOR
    Window(const char* title, int width, int height);
    
    // GETTERS
    void* GetNativeWindow();
    
};
