#include <iostream>
#include <queue>
using namespace std;

class Message {
public:
    string messageId;
    Message(){}
};

class ServerResponse : public Message{
public:
    string serverId;
    string metadata;
    ServerResponse(string messageId, string serverId, string metadata){
        this->messageId = messageId;
        this->serverId = serverId;
        this->metadata = metadata;
    }
};

class ClientRequest : public Message{
public:
    string clientId;
    int requestTime;
    ClientRequest(string messageId, string clientId, int requestTime){
        this->messageId = messageId;
        this->clientId = clientId;
        this->requestTime = requestTime;
    }
};

class customQueue {
private:
    queue<Message*> q;

public:
    void enqueue(ServerResponse* e) {
        q.push(e);
    }

    void enqueue(ClientRequest* e) {
        q.push(e);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    string getFront() {
        return "";
    }
};

int main() {

    return 0;
}