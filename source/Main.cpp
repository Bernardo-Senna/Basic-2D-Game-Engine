//Downloads:
//sudo apt-get install libsdl2-dev
//sudo apt-get install libsdl2-image-dev


// Compile:
// g++ -std=c++11 *.cpp -o app -lSDL2 -lSDL2_image
// g++ -std=c++11 engine/*.cpp *.cpp -o app -lSDL2 -lSDL2_image

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Engine/EngineApp.h"
#include "Engine/GameObject.h"

int main (int argc, char *argv[]) {
    EngineApp app("Game1");
    InputMap* inputMap = app.GetInputMap();

    inputMap->NewMap("upward");
    inputMap->NewMap("forward");
    inputMap->BindKey("upward", KEY_W, 1.0f);
    inputMap->BindKey("upward", KEY_S, -1.0f);
    inputMap->BindKey("forward", KEY_A, -1.0f);
    inputMap->BindKey("forward", KEY_D, 1.0f);



    app.LoadTexture("exit", "exit2.png");

    GameObject* a = new GameObject();
    a->SetSprite("exit");
    a->GetLayers()->Register(2);
    app.AddEntity(a);

    GameObject* b = new GameObject();
    b->SetSprite("exit");
    b->GetPosition()->x += 50;
    b->GetPosition()->y += 50;
    app.AddEntity(b);

    /////////////////////////////// Game Loop ///////////////////////////////
    app.GameLoop();



	return 0;
}