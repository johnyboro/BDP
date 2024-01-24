#include "../content/client.h"
#include <iostream>
#include <cstring>

client::client() : clientHost(nullptr), serverPeer(nullptr) {
    if (enet_initialize() != 0) {
        std::cerr << "Failed to initialize ENet." << std::endl;
        exit(EXIT_FAILURE);
    }
}

client::~client() {
    disconnect();
    enet_deinitialize();
}

void client::connect(const char* address) {
    ENetAddress serverAddress;

    enet_address_set_host(&serverAddress, address);
    serverAddress.port = 1234;

    clientHost = enet_host_create(nullptr, 1, 2, 0, 0);

    if (clientHost == nullptr) {
        std::cerr << "Failed to create ENet gClient host." << std::endl;
        exit(EXIT_FAILURE);
    }

    serverPeer = enet_host_connect(clientHost, &serverAddress, 2, 0);

    if (serverPeer == nullptr) {
        std::cerr << "Failed to initiate connection to the server." << std::endl;
        enet_host_destroy(clientHost);
        exit(EXIT_FAILURE);
    }

    std::cout << "Connected to the server." << std::endl;
}

void client::disconnect() {
    if (clientHost != nullptr) {
        if (serverPeer != nullptr) {
            enet_peer_disconnect(serverPeer, 0);
            while (enet_host_service(clientHost, nullptr, 3000) > 0) {
                // Wait for the server to acknowledge the disconnect
            }
            enet_peer_reset(serverPeer);
        }

        enet_host_destroy(clientHost);
        clientHost = nullptr;
        serverPeer = nullptr;

        std::cout << "Disconnected from the server." << std::endl;
    }
}

void client::update(objectManager& objManager) {
    ENetEvent event;

    if (clientHost == nullptr) {
        return;
    }

    while (enet_host_service(clientHost, &event, 0) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                std::cout << "Connected to the server." << std::endl;
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                handlePacket(event.packet, objManager);
                enet_packet_destroy(event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                std::cout << "Disconnected from the server." << std::endl;
                disconnect();
                break;

            default:
                break;
        }
    }
}

void client::sendPlayerUpdate(const playerUpdate& update) {
    if (clientHost != nullptr && serverPeer != nullptr) {
        ENetPacket* packet = enet_packet_create(&update, sizeof(playerUpdate), ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(serverPeer, 0, packet);
    }
}

void client::handlePacket(ENetPacket* packet, objectManager& objManager) {
    // Assuming that the packet contains the entire vector of PlayerUpdate structs
    size_t numUpdates = packet->dataLength / sizeof(playerUpdate);

    // Access the data as an array of PlayerUpdate
    playerUpdate* updates = reinterpret_cast<playerUpdate*>(packet->data);

    // Process each update individually
    for (size_t i = 0; i < numUpdates; ++i) {
        // Access the individual PlayerUpdate
        playerUpdate& receivedUpdate = updates[i];
        // Call applyServerPlayerUpdate on the object manager
        objManager.applyServerPlayerUpdate(receivedUpdate);
    }
}

