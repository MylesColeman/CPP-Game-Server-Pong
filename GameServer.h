#ifndef GAMESERVER_H
#define GAMESERVER_H

#include "Ball.h"
#include "Constants.h"
#include <SFML/Network.hpp>
#include <vector>
#include <mutex>
#include <string>

class GameServer {
public:
    GameServer(unsigned short tcp_port, unsigned short udp_port);
    void tcp_start();
    void udp_start();
    void gameLogic();
private:
    unsigned short m_tcp_port;
    unsigned short m_udp_port;
    std::vector<sf::TcpSocket*> m_clients;
    std::mutex m_clients_mutex;

    std::mutex m_paddle_mutex;
    sf::Clock m_playerClocks[2];
    float m_paddleX[2] = { 0.f, 0.f };

    Ball m_ball;

    int m_playerScore = 0;
    int m_opponentScore = 0;

    void handle_client(sf::TcpSocket* client, int playerID);
    void broadcast_message(const std::string& message, sf::TcpSocket* sender);
};

#endif