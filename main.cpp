#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include "src/Aquarium/Aquarium.hpp"
#include <stdlib.h>
#include <time.h>
#include <vector>

// Kecepatan ikan
const double speed = 100;
// Posisi ikan
double cy = SCREEN_HEIGHT / 2;
double cx = SCREEN_WIDTH / 2;
double AQUARIUM_HEIGHT = SCREEN_HEIGHT;
// Shop
const int margin = 10;
int SHOP_ITEMS_NUMBER = 5;
std::string SHOP_ITEMS[5] = {
    "shop-icon-guppy.png",
    "shop-icon-piranha.png",
    "shop-icon-telur-1.png",
    "shop-icon-telur-2.png",
    "shop-icon-telur-3.png"
};

typedef struct {
    double left;
    double right;
    double top;
    double bot;
    std::string name;
} Button;

std::vector<Button> buttons;

void addButton(double left, double right, double top, double bot, std::string name) {
    Button *button = new Button;
    button->left = left;
    button->right = right;
    button->top = top;
    button->bot = bot;
    button->name = name;
    buttons.push_back(*button);
}

std::string buttonsCheck(double x, double y) {
    for (unsigned int i = 0; i < buttons.size(); ++i) {
        Button button = buttons[i];
        if (x > button.left && x < button.right &&
            y > button.top && y < button.bot) {
            return button.name; 
        }
    }
    return "";
}

Aquarium& initialization() {
    SDL_Surface* imageLoader;

    // Counting AQUARIUM_HEIGHT
    imageLoader = loadSurface("shop-case.png");
    AQUARIUM_HEIGHT = AQUARIUM_HEIGHT - imageLoader->h;

    // INITIALIZE BUTTON
    imageLoader = loadSurface("shop-icon-guppy.png");
    std::string buttonNames[5] = {
        "guppy",
        "piranha",
        "egg-1",
        "egg-2",
        "egg-3"
    };
    int distanceFromLeft = 0;
    for (int i = 0; i < SHOP_ITEMS_NUMBER; ++i) {
        addButton(distanceFromLeft, distanceFromLeft+imageLoader->w, 0, imageLoader->h, buttonNames[i]);
        distanceFromLeft += imageLoader->w + margin;
    }

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
<<<<<<< HEAD
		
		// UPDATE GUPPY TRY
=======

    // UPDATE GUPPY
>>>>>>> c6ecbb1d7402458447da2e64d930e2a85c76c091
    Element<Guppy> *eGuppy = aquarium.getGuppies().getFirst();
    while (eGuppy != NULL) {
        imageLoader = loadSurface(eGuppy->getInfo()->getImage());
        eGuppy->getInfo()->setRadX(imageLoader->w/2);
        eGuppy->getInfo()->setRadY(imageLoader->h/2);
        eGuppy = eGuppy->getNext();
    }
<<<<<<< HEAD
		// UPDATE GUPPY TRY
		
=======

    // UPDATE PIRANHA
    Element<Piranha> *ePiranha = aquarium.getPiranhas().getFirst();
    while (ePiranha != NULL) {
        imageLoader = loadSurface(ePiranha->getInfo()->getImage());
        ePiranha->getInfo()->setRadX(imageLoader->w/2);
        ePiranha->getInfo()->setRadY(imageLoader->h/2);
        ePiranha = ePiranha->getNext();
    }

    // UPDATE FOOD
    Element<Food> *eFood = aquarium.getFoods().getFirst();
    while (eFood != NULL) {
        imageLoader = loadSurface(eFood->getInfo()->getImage());
        eFood->getInfo()->setRadX(imageLoader->w/2);
        eFood->getInfo()->setRadY(imageLoader->h/2);
        eFood = eFood->getNext();
    }

>>>>>>> c6ecbb1d7402458447da2e64d930e2a85c76c091
    aquarium.tick(sec_since_last);
}

void updateScreen(Aquarium &aquarium) {
    // draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
    // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
    SDL_Surface* imageLoader;

    clear_screen();

    // SCREEN ACCESSORIES
    int distanceFromLeft = 0;
    draw_image("bg.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    imageLoader = loadSurface("shop-case.png");
    draw_image("shop-case.png", SCREEN_WIDTH / 2, imageLoader->h/2);
    imageLoader = loadSurface("shop-icon-guppy.png");
    for (int i = 0; i < SHOP_ITEMS_NUMBER; ++i) {
        draw_image(SHOP_ITEMS[i], distanceFromLeft+imageLoader->w/2, imageLoader->h/2);
        distanceFromLeft += imageLoader->w + margin;
    }
    draw_image("cursor.png", cx, cy);
    draw_image(aquarium.getSnail().getImage(), aquarium.getSnail().getX(), aquarium.getSnail().getY());
    Element<Coin> *eCoin = aquarium.getCoins().getFirst();
    while (eCoin != NULL) {
        Coin *coin = eCoin->getInfo();
        draw_image(coin->getImage(), coin->getX(), coin->getY());
        eCoin = eCoin->getNext();
    }
<<<<<<< HEAD
		//TRY GUPPY
		Element<Guppy> *eGuppy = aquarium.getGuppies().getFirst();
=======
    Element<Guppy> *eGuppy = aquarium.getGuppies().getFirst();
>>>>>>> c6ecbb1d7402458447da2e64d930e2a85c76c091
    while (eGuppy != NULL) {
        Guppy *guppy = eGuppy->getInfo();
        draw_image(guppy->getImage(), guppy->getX(), guppy->getY());
        eGuppy = eGuppy->getNext();
    }
<<<<<<< HEAD
		//TRY GUPPY
=======
    Element<Piranha> *ePiranha = aquarium.getPiranhas().getFirst();
    while (ePiranha != NULL) {
        Piranha *piranha = ePiranha->getInfo();
        draw_image(piranha->getImage(), piranha->getX(), piranha->getY());
        ePiranha = ePiranha->getNext();
    }
    Element<Food> *eFood = aquarium.getFoods().getFirst();
    while (eFood != NULL) {
        Food *food = eFood->getInfo();
        draw_image(food->getImage(), food->getX(), food->getY());
        eFood = eFood->getNext();
    }
>>>>>>> c6ecbb1d7402458447da2e64d930e2a85c76c091
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
<<<<<<< HEAD
								
						// GUPPY TRY
            case SDLK_g:
                {
                    SDL_Surface* imageLoader = loadSurface("ikan.png");
                    aquarium.addGuppy(new Guppy(rand() % SCREEN_WIDTH + 1, aquarium.getTop()+(imageLoader->h/2), imageLoader->w, imageLoader->h));
                }
                break;
						// GUPPY TRY		
						
=======
            case SDLK_t:
                {
                    SDL_Surface* imageLoader = loadSurface("unknown.png");
                    aquarium.addFood(new Food(rand() % SCREEN_WIDTH + 1, aquarium.getTop()+(imageLoader->h/2), imageLoader->w, imageLoader->h));
                }
                break;
>>>>>>> c6ecbb1d7402458447da2e64d930e2a85c76c091
            // x untuk keluar
            case SDLK_x:
                {
                    std::string name = buttonsCheck(cx, cy);
                    if (name == "guppy") {
                        SDL_Surface* imageLoader = loadSurface("ikan.png");
                        aquarium.addGuppy(new Guppy(rand() % SCREEN_WIDTH + 1, aquarium.getTop()+(imageLoader->h/2), imageLoader->w, imageLoader->h));
                        aquarium.buy(10);
                    } else if (name == "piranha") {
                        SDL_Surface* imageLoader = loadSurface("ikan.png");
                        aquarium.addPiranha(new Piranha(rand() % SCREEN_WIDTH + 1, aquarium.getTop()+(imageLoader->h/2), imageLoader->w, imageLoader->h));
                        aquarium.buy(25);
                    } else if (name == "egg-1") {
                        aquarium.buy(50);
                    } else if (name == "egg-2") {
                        aquarium.buy(100);
                    } else if (name == "egg-3") {
                        aquarium.buy(200);
                    }
                }
                // running = false;
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
