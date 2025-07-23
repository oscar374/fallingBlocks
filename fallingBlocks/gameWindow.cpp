#include "gameWindow.h"

GameWindow::GameWindow(const Settings& settings) {
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

	float gravityStrength = 0.1f;
    physics = PhysicsSystem(Vector2(settings.windowWidth, settings.windowHeight), gravityStrength);

    run();
}

void GameWindow::run() {
    world.addGameObject(GameObject("player", Vector2(500, 100), Vector2(100, 100), Color(255, 0, 0, 255), 0.05f));

    while (m_isRunning) {
        handleEvents();
        update();
        render();
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void GameWindow::handleEvents() {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_isRunning = false;
        }
    }
}

void GameWindow::update() {
    physics.update(world.getAllGameObjects(), 0.1f);
}

void GameWindow::render() {
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