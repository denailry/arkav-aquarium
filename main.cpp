#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include "src/Aquarium/Aquarium.hpp"
#include <stdlib.h>
#include <time.h>

// Kecepatan ikan
const double speed = 50;
// Posisi ikan
double cy = SCREEN_HEIGHT / 2;
double cx = SCREEN_WIDTH / 2;
double AQUARIUM_HEIGHT = SCREEN_HEIGHT;

Aquarium& initialization() {
    SDL_Surface* imageLoader;

    // Counting AQUARIUM_HEIGHT
    imageLoader = loadSurface("shop-case.png");
    AQUARIUM_HEIGHT = AQUARIUM_HEIGHT - imageLoader->h;

    // INITIALIZE AQUARIUM OBJECT
    Aquarium *aquarium = new Aquarium(SCREEN_WIDTH, imageLoader->h, SCREEN_HEIGHT);
    imageLoader = loadSurface("snail-small-left.png");
    srand(time(NULL));
    Snail *snail = new Snail(rand() % SCREEN_WIDTH + 1, SCREEN_HEIGHT-(imageLoader->h/2), imageLoader->w, imageLoader->h);
    aquarium->setSnail(snail);
		return *aquarium;
}

void updateFrame(Aquarium &aquarium, double sec_since_last) {
    SDL_Surface* imageLoader;

    // UPDATE SNAIL
    imageLoader = loadSurface(aquarium.getSnail().getImage());
    aquarium.getSnail().setRadX(imageLoader->w/2);
    aquarium.getSnail().setRadY(imageLoader->h/2);

    // UPDATE COIN
    Element<Coin> *eCoin = aquarium.getCoins().getFirst();
    while (eCoin != NULL) {
        imageLoader = loadSurface(eCoin->getInfo()->getImage());
        eCoin->getInfo()->setRadX(imageLoader->w/2);
        eCoin->getInfo()->setRadY(imageLoader->h/2);
        eCoin = eCoin->getNext();
    }
		
		// UPDATE GUPPY TRY
    Element<Guppy> *eGuppy = aquarium.getGuppies().getFirst();
    while (eGuppy != NULL) {
        imageLoader = loadSurface(eGuppy->getInfo()->getImage());
        eGuppy->getInfo()->setRadX(imageLoader->w/2);
        eGuppy->getInfo()->setRadY(imageLoader->h/2);
        eGuppy = eGuppy->getNext();
    }
		// UPDATE GUPPY TRY
		
    aquarium.tick(sec_since_last);
}

void updateScreen(Aquarium &aquarium) {
    // draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
    // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
    SDL_Surface* imageLoader;

    clear_screen();

    // SCREEN ACCESSORIES
    const int margin = 10;
    int distanceFromLeft = 0;
    draw_image("bg.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    imageLoader = loadSurface("shop-case.png");
    draw_image("shop-case.png", SCREEN_WIDTH / 2, imageLoader->h/2);
    imageLoader = loadSurface("shop-icon-guppy.png");
    draw_image("shop-icon-guppy.png", distanceFromLeft+imageLoader->w/2, imageLoader->h/2);
    distanceFromLeft += imageLoader->w + margin;
    draw_image("shop-icon-piranha.png", distanceFromLeft+imageLoader->w/2, imageLoader->h/2);
    distanceFromLeft += imageLoader->w + margin;
    draw_image("shop-icon-telur-1.png", distanceFromLeft+imageLoader->w/2, imageLoader->h/2);
    distanceFromLeft += imageLoader->w + margin;
    draw_image("shop-icon-telur-2.png", distanceFromLeft+imageLoader->w/2, imageLoader->h/2);
    distanceFromLeft += imageLoader->w + margin;
    draw_image("shop-icon-telur-3.png", distanceFromLeft+imageLoader->w/2, imageLoader->h/2);
    distanceFromLeft += imageLoader->w + margin;

    draw_image(aquarium.getSnail().getImage(), aquarium.getSnail().getX(), aquarium.getSnail().getY());
    Element<Coin> *eCoin = aquarium.getCoins().getFirst();
    while (eCoin != NULL) {
        Coin *coin = eCoin->getInfo();
        draw_image(coin->getImage(), coin->getX(), coin->getY());
        eCoin = eCoin->getNext();
    }
		//TRY GUPPY
		Element<Guppy> *eGuppy = aquarium.getGuppies().getFirst();
    while (eGuppy != NULL) {
        Guppy *guppy = eGuppy->getInfo();
        draw_image(guppy->getImage(), guppy->getX(), guppy->getY());
        eGuppy = eGuppy->getNext();
    }
		//TRY GUPPY
    update_screen();
}

int main( int argc, char* args[] )
{
    init();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    bool running = true;

    double prevtime = time_since_start();

    Aquarium &aquarium = initialization();

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }
				/*
        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.
        for (auto key : get_pressed_keys()) {
            switch (key) {
            case SDLK_UP:
                cy -= speed * sec_since_last;
                break;
            case SDLK_DOWN:
                cy += speed * sec_since_last;
                break;
            case SDLK_LEFT:
                cx -= speed * sec_since_last;
                break;
            case SDLK_RIGHT:
                cx += speed * sec_since_last;
                break;
            }
        }
				*/
        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                {
                    SDL_Surface* imageLoader = loadSurface("koin-mahal.png");
                    aquarium.addCoin(new Coin(rand() % SCREEN_WIDTH + 1, aquarium.getTop()+(imageLoader->h/2), imageLoader->w, imageLoader->h, 10));
                }
                break;
								
						// GUPPY TRY
            case SDLK_g:
                {
                    SDL_Surface* imageLoader = loadSurface("ikan.png");
                    aquarium.addGuppy(new Guppy(rand() % SCREEN_WIDTH + 1, aquarium.getTop()+(imageLoader->h/2), imageLoader->w, imageLoader->h));
                }
                break;
						// GUPPY TRY		
						
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1.0/120.0) {
            updateFrame(aquarium, sec_since_last);
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }
        updateScreen(aquarium);
    }

    close();

    return 0;
}
