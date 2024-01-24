#ifndef BDP_OBJECTMANAGER_H
#define BDP_OBJECTMANAGER_H

#include <vector>
#include <random>
#include "player.h"
#include "../../networking/content/playerUpdate.h"

class objectManager {
public:
    void addLocalPlayer(int team);
    void initPlayers();
    void inputLocalPlayers(int input);
    void applyServerPlayerUpdate(const playerUpdate& update);
    void updatePlayers();
    void drawPlayers();
    playerUpdate packLocalUpdate();

private:
    std::vector<player> players_;
    int localId_;

    void addPlayer(int id, int x, int y, int team, int initialVelocityX = 0, int initialVelocityY = 0, int speed = 2,
                   int gravity = -9, int drag = 1, int bounciness = 1, int r = 10, const char* ch = "X");
    int generateRandomId();
    bool findPlayerById(int playerId, std::vector<player>::iterator& playerIter);
    void updatePlayer(const playerUpdate& update);
    playerUpdate packPlayerToPlayerUpdate(const player& player) const;
};

#endif //BDP_OBJECTMANAGER_H
