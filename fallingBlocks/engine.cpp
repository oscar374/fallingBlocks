#include "engine.h"

#include "settings.h"

Engine::Engine() : m_isRunning(false) {
    
	std::cout << "Initializing engine..." << "\n";

    window = SDL_CreateWindow(
        "game instance",
        settings.windowWidth,
        settings.windowHeight,
        SDL_WINDOW_OPENGL
    );

    if (!window) {
        std::cout << "Failed to initialize window" << "\n";
        return;
    }

    renderer = SDL_CreateRenderer(
        window,
        NULL
    );

    if (!renderer) {
        std::cout << "Failed to initialize renderer" << "\n";
        return;
    }
}

void Engine::run() {
    m_isRunning = true;

    float gravityStrength = settings.physicsGravityStrength;
    physics = PhysicsSystem(Vector2(settings.windowWidth, settings.windowHeight), gravityStrength);
    ObstacleSpawner oSpawner = ObstacleSpawner(world);
	obstacleSpawner = &oSpawner;

    std::shared_ptr<Player> p = std::make_shared<Player>("Player", Vector2(300, 300), Vector2(30, 60), Color(0, 0, 255, 0), 5, false);
    player = p;
	world.addGameObject(player);

	Uint64 lastTime = SDL_GetTicksNS();
    while (m_isRunning) {
        //deltatime
        Uint64 currentTime = SDL_GetTicksNS();
        float deltaTime = (currentTime - lastTime) / 1e9f;
        lastTime = currentTime;
        //deltatime

        handleEvents();
        update(deltaTime);
        render();
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Engine::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }

        else if(event.type == SDL_EVENT_KEY_DOWN) {
            if (event.key.key == SDLK_W) {
                player->Jump();
            }
		}
    }
}

void Engine::update(const float& deltaTime) {
    physics.update(world.getAllGameObjects(), deltaTime);
	obstacleSpawner->update(deltaTime);
}

void Engine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (const auto& obj : world.getAllGameObjects()) {
        SDL_FRect toDisplay = {
            static_cast<int>(obj->getPosition().x),
            static_cast<int>(obj->getPosition().y),
            static_cast<int>(obj->getSize().x),
            static_cast<int>(obj->getSize().y)
        };
        Color col = obj->getColor();
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
        SDL_RenderFillRect(renderer, &toDisplay);
    }

    SDL_RenderPresent(renderer);
}