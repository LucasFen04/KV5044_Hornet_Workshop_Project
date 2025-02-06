#include "Game.h"
#include "HtCamera.h"
#include "ObjectManager.h"

void Game::StartOfProgram()
{



    // This makes the operating system's mouse pointer invisible
    // It's usually best to use your own instead.
    HtMouse::instance.SetPointerVisiblity(false);
}

// Use this function to intialise your game objects and load any assets
void Game::StartOfGame()
{
    shipImage = HtGraphics::instance.LoadPicture("assets/ship.bmp");
    Vector2D pos(300, 300);

    shootSound = HtAudio::instance.LoadSound("assets/launchshort.wav");
    thrustSound = HtAudio::instance.LoadSound("assets/thrustloop.wav");
    thrustSoundChannel = -1;
}

// Function runs each frame.
// "frametime" is the time in seconds since the last call (delta time)
void Game::Update(double frametime)
{
    // In the space below, you can write code to create a game the hard way.
    // To start with, we will use this area, but later will use game objects.
    
    Vector2D velocity;
    velocity.setBearing(angle, 0.1);
    pos = pos + velocity;

    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_RIGHT))
    {
        angle = angle + 0.02;
    }
    if (HtKeyboard::instance.KeyPressed(SDL_SCANCODE_LEFT))
    {
        angle = angle - 0.02;
    }

    HtGraphics::instance.DrawAt(pos, shipImage);

    if (HtKeyboard::instance.NewKeyPressed(SDL_SCANCODE_SPACE))
    {
        HtAudio::instance.Play(shootSound);
    }
    if (HtKeyboard::instance.NewKeyPressed(SDL_SCANCODE_W))
    {
       thrustSoundChannel = HtAudio::instance.Play(thrustSound, true);
    }
    if (!HtKeyboard::instance.KeyPressed(SDL_SCANCODE_W) && thrustSoundChannel >= 0)
    {
        HtAudio::instance.Stop(thrustSoundChannel);
        thrustSoundChannel = -1;
    }



    // The code below runs the managed part of the game engine
    // Best to leave it alone
    ObjectManager::instance.UpdateAll(frametime);
    ObjectManager::instance.ProcessCollisions();
    ObjectManager::instance.RenderAll();
#ifdef _DEBUG
    ObjectManager::instance.CycleDebugObject();
    ObjectManager::instance.RenderDebug();
#endif
    ObjectManager::instance.DeleteInactiveItems();

    // Draws all graphics to the screen. Best not to remove this line.
    HtGraphics::instance.Present();
}

// Function runs when the user pauses the program.
// You may want to stop sound effects.
void Game::OnSuspend()
{
    
}


// This function runs when the user resumes the game from pause
// You can start sound effects if needed, but it is usually
// best to just let the game create new sounds if needed.
void Game::OnResume()
{

}

// You can use this to clear up any memory, if needed
void Game::EndOfGame()
{



    //This line automatically deletes all managed objects
    ObjectManager::instance.DeleteAllObjects();
}

void Game::EndOfProgram()
{
}
