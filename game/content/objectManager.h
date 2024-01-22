#ifndef BDP_OBJECTMANAGER_H
#define BDP_OBJECTMANAGER_H

#include <vector>
#include "player.h"

class objectManager {
public:
    // TODO: store players in one vector and use id to update the right one
    void addLocalPlayer(int id, int x, int y, int team, int initialVelocityX = 0, int initialVelocityY = 0, int speed = 2,
                   int gravity = -9, int drag = 1, int bounciness = 1, int r = 10, const char* ch = "L");
    void addRemotePlayer(int id, int x, int y, int team, int initialVelocityX = 0, int initialVelocityY = 0, int speed = 2,
                        int gravity = -9, int drag = 1, int bounciness = 1, int r = 10, const char* ch = "R");
    void initPlayers();
    void inputLocalPlayers(int input);
    void serverUpdatePlayer(int playerId, int x, int y, int velocityX, int velocityY);
    void updatePlayers();
    void drawPlayers();

private:
    std::vector<player> remotePlayers_;
    std::vector<player> localPlayers_;
};

#endif //BDP_OBJECTMANAGER_H
