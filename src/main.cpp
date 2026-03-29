#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "appe/math/vec3.h"

int main() {
	std::cout << "----- PHYSICS ENGINE by abhinavp06 -----" << std::endl;

	try {
		SDL_Window* window;
		bool done = false;

		SDL_Init(SDL_INIT_VIDEO);

		window = SDL_CreateWindow(
			"appe window",
			800,
			600,
			0
		);

		if (window == NULL) {
			const char* window_error = SDL_GetError();
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", window_error);
			throw std::runtime_error(window_error);
		}

		SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
		if (!renderer) {
			throw std::runtime_error(SDL_GetError());
		}
		SDL_SetRenderVSync(renderer, 1);

		while (!done) {
			SDL_Event event;

			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_EVENT_QUIT) {
					done = true;
				}
				if (event.type == SDL_EVENT_KEY_DOWN &&
					event.key.key == SDLK_ESCAPE) {
					done = true;
				}
			}

			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // black
			SDL_RenderClear(renderer);
			SDL_RenderPresent(renderer);
		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
	} catch (const std::exception& e) {
		std::cerr << "[Error] " << e.what() << "\n";
		return 1;
	}

	std::cout << "----- GOODBYE -----" << std::endl;

	return 0;
}