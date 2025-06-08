#include <SDL3/SDL.h>
#include <iostream>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL Init failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Quit();
    return 0;
}
