/*
 * server.h
 *
 *  Created on: Jun 27, 2024
 *      Author: aditya
 */

#ifndef SERVER_H
#define SERVER_H

#include <string>

class Server {
public:
    Server(int port, int max_clients);
    void start();
private:
    int port;
    int max_clients;
    int server_fd;
    static void* thread_func(void* arg);
    static std::string process_request(const std::string& request);
    void handle_client(int client_socket);
};

#endif // SERVER_H
