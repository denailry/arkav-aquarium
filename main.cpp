#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include "src/Aquarium/Aquarium.hpp"
#include <stdlib.h>
#include <time.h>

const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();

    Aquarium aquarium(SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* imageLoader = loadSurface("snail-small-left.png");
    srand(time(NULL));

    Snail *snail = new Snail(rand() % SCREEN_WIDTH + 1, SCREEN_HEIGHT-(imageLoader->h/2), imageLoader->w, imageLoader->h);
    aquarium.setSnail(snail);

    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

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

        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                {
                    imageLoader = loadSurface("koin-mahal.png");
                    aquarium.addCoin(new Coin(rand() % SCREEN_WIDTH + 1, 0+(imageLoader->h/2), imageLoader->w, imageLoader->h, 10));
                }
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1.0/120.0) {
            imageLoader = loadSurface(aquarium.getSnail().getImage());
            aquarium.getSnail().setRadX(imageLoader->w/2);
            aquarium.getSnail().setRadY(imageLoader->h/2);

            Element<Coin> *eCoin = aquarium.getCoins().getFirst();
            while (eCoin != NULL) {
                imageLoader = loadSurface(eCoin->getInfo()->getImage());
                eCoin->getInfo()->setRadX(imageLoader->w/2);
                eCoin->getInfo()->setRadY(imageLoader->h/2);
                eCoin = eCoin->getNext();
            }
            aquarium.tick(sec_since_last);

            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        draw_image("bg.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
        draw_image(aquarium.getSnail().getImage(), aquarium.getSnail().getX(), aquarium.getSnail().getY());
        // draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        draw_image("ikan.png", cx, cy);
        Element<Coin> *eCoin = aquarium.getCoins().getFirst();
        while (eCoin != NULL) {
            Coin *coin = eCoin->getInfo();
            draw_image(coin->getImage(), coin->getX(), coin->getY());
            eCoin = eCoin->getNext();
        }
        update_screen();
    }

    close();

    return 0;
}
