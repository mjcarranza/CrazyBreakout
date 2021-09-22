#include "Server.h"

Server * server;
void * serverRun(void *){
    try {
        server->run();
    }catch (string ex){
        cout<< ex <<endl;
    }
    pthread_exit(NULL);
}

int main() {
    server = new Server;
    pthread_t hiloServ;
    pthread_create(&hiloServ,0,serverRun,NULL);
    pthread_detach(hiloServ);

    // loop to send messages to cient   // ojo que esta vara se debe cambiar para que envie los mensajes adecuados al cliente (el while)
    // segun lo que llegue como mensaje
    while (true){
        string json;
        cout<<"introduzca el mensaje: "<<endl;
        cin>>json;
        if (json == "salir"){
            break;
        }
        server->setMessage(json.c_str());
    }
    delete server;
    return 0;
}
