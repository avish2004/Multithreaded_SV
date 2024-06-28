/*
 * main.cpp
 *
 *  Created on: Jun 27, 2024
 *      Author: aditya
 */


#include "server.h"

int main() {
    int port = 8081;
    int max_clients = 10;
    Server server(port, max_clients);
    server.start();
    return 0;
}
