//============================================================================
// Name        : Multithread_Summer_Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "server.h"
#include <iostream>
#include <vector>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <fstream>
#include <sstream>
#include <pthread.h>

Server::Server(int port, int max_clients) : port(port), max_clients(max_clients) {}

void* Server::thread_func(void* arg) {
    int client_socket = *((int*)arg);
    delete (int*)arg;
    char buffer[1024] = {0};
    read(client_socket, buffer, 1024);
    std::string request(buffer);
    std::string response = process_request(request);
    send(client_socket, response.c_str(), response.size(), 0);
    close(client_socket);
    return NULL;
}

void Server::start() {
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, max_clients) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    std::vector<pthread_t> threads;
    while (true) {
        int* client_socket = new int;
        *client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (*client_socket < 0) {
            perror("accept failed");
            delete client_socket;
            continue;
        }
        pthread_t thread;
        pthread_create(&thread, NULL, thread_func, (void*)client_socket);
        threads.push_back(thread);
    }

    for (size_t i = 0; i < threads.size(); ++i) {
        pthread_join(threads[i], NULL);
    }
}

std::string Server::process_request(const std::string& request) {
    std::istringstream request_stream(request);
    std::string method, path, version;
    request_stream >> method >> path >> version;

    if (path == "/") path = "static/index.html";
    std::ifstream file("static" + path);
    if (file.good()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        return "HTTP/1.1 200 OK\nContent-Type: text/html\n\n" + buffer.str();
    } else {
        std::ifstream error_file("static/404.html");
        std::stringstream buffer;
        buffer << error_file.rdbuf();
        return "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\n" + buffer.str();
    }
}
