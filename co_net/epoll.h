#pragma once

#include <sys/epoll.h>
#include <functional>

#include "../utility/nocopy.h"

namespace CoNet
{

struct Event
{
    std::function<bool(int,Event*)> Callback;
};


class Epoll : public Utility::NoCopy
{
public:
    Epoll() = default;
    ~Epoll() = default;

    bool Init();
    void Loop();
    void Destroy();

    bool Add(int fd);
    bool Mod(int fd);
    bool Del(int fd);

private:
    int _efd{-1};
};

}