#include "SoundManager.h"
#include <iostream>

using namespace sf;
using namespace gm;

SoundManager::SoundManager() {
    if (!levelComplete.loadFromFile("Assets/levelComplete.wav")) {
        // error...
        std::cerr << "Error: Failed to load levelComplete.wav" << std::endl;
        exit(-1);
    }
    if (!loseBall.loadFromFile("Assets/loseBall.wav")) {
        // error...
        std::cerr << "Error: Failed to load loseBall.wav" << std::endl;
        exit(-1);
    }
    if (!gameOver.loadFromFile("Assets/gameOver.wav")) {
        // error...
        std::cerr << "Error: Failed to load gameOver.wav" << std::endl;
        exit(-1);
    }
    if (!bounceWall.loadFromFile("Assets/bounceWall.wav")) {
        // error...
        std::cerr << "Error: Failed to load bounceWall.wav" << std::endl;
        exit(-1);
    }
    if (!bouncePaddle.loadFromFile("Assets/bouncePaddle.wav")) {
        // error...
        std::cerr << "Error: Failed to load bouncePaddle.wav" << std::endl;
        exit(-1);
    }
    if (!bounceBrick.loadFromFile("Assets/bounceBrick.wav")) {
        // error...
        std::cerr << "Error: Failed to load bounceBrick.wav" << std::endl;
        exit(-1);
    }
    if (!bounceBrickDamage.loadFromFile("Assets/bounceBrickDamage.wav")) {
        // error...
        std::cerr << "Error: Failed to load bounceBrickDamage.wav" << std::endl;
        exit(-1);
    }
}
void SoundManager::PlaySFX(SFX sfx) {
    switch (sfx) {
    case SFX::levelComplete:
        sound.setBuffer(levelComplete);
        sound.play();
        break;
    case SFX::loseBall:
        sound.setBuffer(loseBall);
        sound.play();
        break;
    case SFX::gameOver:
        sound.setBuffer(gameOver);
        sound.play();
        break;
    case SFX::bounceWall:
        sound.setBuffer(bounceWall);
        sound.play();
        break;
    case SFX::bouncePaddle:
        sound.setBuffer(bouncePaddle);
        sound.play();
        break;
    case SFX::bounceBrick:
        sound.setBuffer(bounceBrick);
        sound.play();
        break;
    case SFX::bounceBrickDamage:
        sound.setBuffer(bounceBrickDamage);
        sound.play();
        break;
    }
}
SoundManager::~SoundManager() {

}