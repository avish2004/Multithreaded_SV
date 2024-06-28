# Multithreaded_SV
This is a simple web server that can handle multiple client requests simultaneously using multithreading. Can include features like handling GET and POST requests, serving static files, and logging. 
Skills Demonstrated: Multithreading, Network Programming, Sockets, HTTP Protocol.

#### Overview

This project implements a multithreaded web server in C++. The server is designed to handle multiple client connections concurrently using POSIX threads. It serves static HTML files from a specified directory and provides appropriate HTTP responses, including handling 404 errors for non-existent files. (Please use your own HTML files)

#### Project Structure
I have the project directory organized as follows:
multithreaded_web_server/
├── CMakeLists.txt

├── include/
│   └── server.h

├── src/
│   ├── main.cpp
│   └── server.cpp

├── static/
│   ├── index.html
│   └── 404.html

└── README.md

NOTE: For macOS users using eclipse, if putting server.h in the inlcude folder does not work, keep it in .src.

- **CMakeLists.txt**: Configuration file for building the project with CMake.
- **include/server.h**: Header file declaring the `Server` class.
- **src/main.cpp**: Main entry point of the application.
- **src/server.cpp**: Implementation of the `Server` class. (make sure to change the path for the html files)
- **static/index.html**: Default HTML file served at the root URL.
- **static/404.html**: HTML file served when a requested file is not found.
- **README.md**: Documentation file for the project.

#### Key Features
- **Multithreading**: The server uses POSIX threads to handle multiple client connections simultaneously.
- **HTTP Responses**: The server processes HTTP GET requests and serves static HTML files.
- **404 Error Handling**: When a requested file is not found, the server responds with a custom 404 error page.
- **Modular Design**: The project is organized into separate source and header files, making it easy to understand and extend.

#### Building the Project
To build the project, follow these steps:

1. **Clone the Repository**:
   git clone https://github.com/yourusername/multithreaded_web_server.git
   cd multithreaded_web_server


2. **Create a Build Directory**:
   mkdir build
   cd build

3. **Generate Build Files with CMake**:
   cmake ..

4. **Compile the Project**:
   make

#### Running the Server
After building the project, you can run the server with the following command:
./multithreaded_web_server

The server will start and listen for incoming connections on the specified port (default is 8080). I had used 8081 since I encountered errors

#### Testing the Server
To test the server, open a web browser and navigate to `http://localhost:8080`:
- **Root URL**: The server should display the content of `static/index.html`.
- **Non-Existent URL**: Navigating to a non-existent URL, such as `http://localhost:8080/nonexistent`, should display the content of `static/404.html`.

Alternatively, you can use `curl` from the command line:
curl http://localhost:8080
curl http://localhost:8080/nonexistent

#### Customization
- **Port Number**: You can change the port number in `src/main.cpp` to any available port.
- **Static Files**: Add or modify files in the `static` directory to serve different content.

#### Troubleshooting
- **Port Already in Use**: If you encounter a `bind failed: Address already in use` error, ensure no other process is using the specified port, or change the port number.
- **File Not Found**: If the server returns a 404 error for existing files, verify the file paths and names in the `static` directory.

#### Future Improvements
- **Support for More HTTP Methods**: Extend the server to handle other HTTP methods such as POST, PUT, and DELETE.
- **Dynamic Content**: Implement support for serving dynamic content using server-side scripting.
- **Security Features**: Add HTTPS support and implement security features such as input validation and protection against common web vulnerabilities.

#### License
This project is licensed under the MIT License. See the `LICENSE` file for details.

#### Acknowledgments
This is one of my summer projects. Any open source contributions would be greatly appreciated!!!
