#include "engine.h"

Engine::Engine(const Settings& settings) {
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

    std::cout << "game is running correctly" << "\n";
    m_isRunning = true;

	float gravityStrength = settings.physicsGravityStrength;
    physics = PhysicsSystem(Vector2(settings.windowWidth, settings.windowHeight), gravityStrength);

    run();
}

void Engine::run() {
    for (int i = 0; i < 30; i++) {
        world.addGameObject(GameObject("Block", Vector2(rand() % 1000, rand() % 500), Vector2(30, 30), Color(255, 0, 0, 255), 0.05f));
    }

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
    }
}

void Engine::update(const float& deltatime) {
    physics.update(world.getAllGameObjects(), deltatime);
}

void Engine::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (const GameObject& obj : world.getAllGameObjects()) {
        SDL_FRect toDisplay = {
            static_cast<int>(obj.getPosition().x),
            static_cast<int>(obj.getPosition().y),
            static_cast<int>(obj.getSize().x),
            static_cast<int>(obj.getSize().y)
        };
        Color col = obj.getColor();
        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, col.a);
        SDL_RenderFillRect(renderer, &toDisplay);
    }

    SDL_RenderPresent(renderer);
}