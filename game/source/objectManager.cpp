#include "../content/objectManager.h"
#include <algorithm>

void objectManager::addPlayer(int id, int x, int y, int team, int initialVelocityX, int initialVelocityY, int speed, int gravity, int drag, int bounciness, int r, const char* ch) {
    players_.emplace_back(id, x, y, team, initialVelocityX, initialVelocityY, speed, gravity, drag, bounciness, r, ch);
}

int objectManager::generateRandomId() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1000, 9999);
    return distribution(gen);
}

void objectManager::addLocalPlayer(int team) {
    localId_ = generateRandomId();
    addPlayer(localId_, 35, 35, team);
    initPlayers();
}

void objectManager::initPlayers() {
    for (auto& player : players_) {
        player.initCircle();
    }
}

void objectManager::inputLocalPlayers(int input) {
    std::vector<player>::iterator playerIter;

    if (findPlayerById(localId_, playerIter)) {
        playerIter->handleInput(input);
    } else {
        // erm... (this should never happen)
    }
}

playerUpdate objectManager::packLocalUpdate() {
    auto playerIter = players_.begin(); // had a problem with "std::vector<player>::iterator playerIter;" so just replaced it with this

    if (findPlayerById(localId_, playerIter)) {
        return packPlayerToPlayerUpdate(*playerIter);
    } else {
        // erm... (this should never happen)
    }
}

bool objectManager::findPlayerById(int playerId, std::vector<player>::iterator& playerIter) {
    playerIter = std::find_if(players_.begin(), players_.end(),
                              [playerId](const player& player) {
                                  return player.getId() == playerId;
                              });

    return (playerIter != players_.end());
}

void objectManager::updatePlayer(const playerUpdate& update) {
    std::vector<player>::iterator it;

    if (findPlayerById(update.playerId, it)) {
        // Player found, update the player
        it->setX(update.x);
        it->setY(update.y);
        it->setVelocityX(update.velocityX);
        it->setVelocityY(update.velocityY);
    } else {
        // Player not found, create a new player
        addPlayer(update.playerId, update.x, update.y, update.team, update.velocityX, update.velocityY);
        initPlayers();
    }
}


void objectManager::applyServerPlayerUpdate(const playerUpdate& update) {
    updatePlayer(update);
}

playerUpdate objectManager::packPlayerToPlayerUpdate(const player& player) const {
    playerUpdate update;
    update.playerId = player.getId();
    update.x = player.getX();
    update.y = player.getY();
    update.team = player.getTeam();
    update.velocityX = player.getVelocityX();
    update.velocityY = player.getVelocityY();

    return update;
}

void objectManager::updatePlayers() {
    for (auto& player : players_) {
        player.update();
    }
}

void objectManager::drawPlayers() {
    for (auto& player : players_) {
        player.draw();
    }
}
