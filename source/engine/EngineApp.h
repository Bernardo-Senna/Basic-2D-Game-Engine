#ifndef ENGINE_APP_H
#define ENGINE_APP_H

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.h"
#include "InputMap.h"
#include "Layer.h"
#include "Physics.h"

class EngineApp{
public:
    EngineApp(std::string name);
    virtual ~EngineApp();

    void GameLoop();

    void LoadJson(std::string path);
    void LoadTexture(std::string name, std::string path);

    void DrawSprite(std::string& texture, Vector& position, Vector& scale, bool flip);

    void AddEntity(Entity* e);
    void RemoveEntity(Entity* e);

    // Physics Methods
    std::vector<Entity*> GetCollisions(Entity* e, Layer layer);
    bool Collided(Entity* e, Layer layer);
    Entity* GetFirstCollision(Entity* e, Layer layer);

    //
    InputMap& GetInputMap();
    SDL_Renderer& GetRenderer();

    Vector& GetCameraPosition();
    Vector& GetWindowSize();

    void SetOrthographicScale(float scale);

private:
    void Render();
    void RemoveQueuedEntities();

    void UpdateWindowSize();

    Vector m_cameraPosition;
    Vector m_windowSize; // Updated every frame
    float m_orthoScale;

    std::vector<Entity*> m_entities;
    std::vector<Entity*> m_removeEntities;
    std::unordered_map<std::string, SDL_Texture*> m_textures;

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    InputMap m_inputMap;

    SDL_Rect m_poolRect;
};

#endif // !ENGINE_APP_H