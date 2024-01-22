#include "../content/objectManager.h"
#include <algorithm>

void objectManager::addLocalPlayer(int x, int y, int team, int initialVelocityX, int initialVelocityY, int speed, int gravity, int drag, int bounciness, int r, const char* ch) {
    localPlayers_.emplace_back(x, y, team, initialVelocityX, initialVelocityY, speed, gravity, drag, bounciness, r, ch);
}

void objectManager::addRemotePlayer(int x, int y, int team, int initialVelocityX, int initialVelocityY, int speed, int gravity, int drag, int bounciness, int r, const char* ch) {
    localPlayers_.emplace_back(x, y, team, initialVelocityX, initialVelocityY, speed, gravity, drag, bounciness, r, ch);
}

void objectManager::initPlayers() {
    for (auto& player : localPlayers_) {
        player.initCircle();
    }
    for (auto& player : remotePlayers_) {
        player.initCircle();
    }
}

void objectManager::inputLocalPlayers(int input) {
    for (auto& player : localPlayers_) {
        player.handleInput(input);
    }
}

void objectManager::serverUpdatePlayer(int playerId, int x, int y, int velocityX, int velocityY) {
    // Find the player with the specified ID
    auto it = std::find_if(remotePlayers_.begin(), remotePlayers_.end(),
                           [playerId](const player& player) {
                               return player.getId() == playerId;
                           });

    // Update the player if found
    if (it != remotePlayers_.end()) {
        it->setX(x);
        it->setY(y);
        it->setVelocityX(velocityX);
        it->setVelocityY(velocityY);
    }
}


void objectManager::updatePlayers() {
    for (auto& player : localPlayers_) {
        player.update();
    }
    for (auto& player : remotePlayers_) {
        player.update();
    }
}

void objectManager::drawPlayers() {
    for (auto& player : localPlayers_) {
        player.draw();
    }
    for (auto& player : remotePlayers_) {
        player.draw();
    }
}
