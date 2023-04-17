
#include <iostream>
#include "Application.h"
#include "Services/Projeto02services.h"
#include "Services/Projeto02Utilityservices.h"
#include <grpcpp/grpcpp.h>




 int main(int argc, char const *argv[])
{

    std::string server_address = "0.0.0.0:1234";

    vma::Projeto02Service appService;
    grpc::EnableDefaultHealthCheckService(true);
    grpc::ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());

    builder.RegisterService(&appService);

    auto server = builder.BuildAndStart();
    std::cout << "Server listening on " + server_address << std::endl;

    server->Wait();

    return 0;
}