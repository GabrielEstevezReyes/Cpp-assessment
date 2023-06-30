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
    unordered_set<string> clientIds;
    unordered_set<string> serverIds;

public:
    void enqueue(ServerResponse* e) {
        q.push(e);
        serverIds.insert(e->serverId);
    }

    void enqueue(ClientRequest* e) {
        q.push(e);
        clientIds.insert(e->clientId);
    }

    void dequeue() {
        if (!q.empty()) {
            q.pop();
        }
    }

    string getFront() {
        return "";
    }

    unsigned int getCountClients() {
        return clientIds.size();
    }

    unsigned int getCountServers() {
        return serverIds.size();
    }
};

int main() {
    customQueue queue;
    queue.enqueue(new ClientRequest("m1", "C1", 10));
    queue.enqueue(new ServerResponse("m2", "S1", "4bytes,1second"));
    queue.enqueue(new ClientRequest("m3", "C2", 15));

    cout << queue.getCountClients() << endl;
    cout << queue.getCountServers() << endl;
    cout << queue.getFront() << endl;

    queue.dequeue();

    cout << queue.getFront() << endl;
    return 0;
}