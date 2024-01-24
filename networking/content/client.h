#ifndef BDP_CLIENT_H
#define BDP_CLIENT_H

#include <enet/enet.h>
#include "playerUpdate.h"
#include "../../game/content/objectManager.h"

class client {
public:
    client();
    ~client();

    void connect(const char* address);
    void update(objectManager& objManager);
    void sendPlayerUpdate(const playerUpdate& update);
    void disconnect();

private:
    ENetHost* clientHost;
    ENetPeer* serverPeer;

    void handlePacket(ENetPacket* packet, objectManager& objManager);
};

#endif //BDP_CLIENT_H
