#include "enet/enet.h"
#include <iostream>
#include <cstring>

int main() {
    if (enet_initialize() != 0) {
        std::cerr << "Failed to initialize ENet." << std::endl;
        return EXIT_FAILURE;
    }

    ENetHost* client;
    ENetAddress address;

    client = enet_host_create(NULL, 1, 2, 0, 0);

    if (client == NULL) {
        std::cerr << "Failed to create ENet client host." << std::endl;
        enet_deinitialize();
        return EXIT_FAILURE;
    }


    enet_address_set_host(&address, "localhost");
    address.port = 1234;

    ENetPeer* peer = enet_host_connect(client, &address, 2, 0);

    if (peer == NULL) {
        std::cerr << "No available peers for initiating an ENet connection." << std::endl;
        enet_host_destroy(client);
        enet_deinitialize();
        return EXIT_FAILURE;
    }

    std::cout << "Connecting to server..." << std::endl;

    ENetEvent event;
    if (enet_host_service(client, &event, 5000) > 0 && event.type == ENET_EVENT_TYPE_CONNECT) {
        std::cout << "Connected to the server!" << std::endl;

        // Send a message to the server
        const char* message = "Hello, server!";
        ENetPacket* packet = enet_packet_create(message, strlen(message) + 1, ENET_PACKET_FLAG_RELIABLE);
        enet_peer_send(peer, 0, packet);

        enet_host_flush(client);

        // Wait for a response from the server
        while (enet_host_service(client, &event, 1000) > 0) {
            if (event.type == ENET_EVENT_TYPE_RECEIVE) {
                std::cout << "Message received from server: " << event.packet->data << std::endl;
                enet_packet_destroy(event.packet);
                break;
            }
        }
    } else {
        std::cerr << "Connection to the server failed." << std::endl;
        enet_peer_reset(peer);
    }

    enet_host_destroy(client);
    enet_deinitialize();

    return EXIT_SUCCESS;
}
