#include "clientsmariem.h"

class clientsmariemData : public QSharedData
{
public:

};

clientsmariem::clientsmariem() : data(new clientsmariemData)
{

}

clientsmariem::clientsmariem(const clientsmariem &rhs) : data(rhs.data)
{

}

clientsmariem &clientsmariem::operator=(const clientsmariem &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

clientsmariem::~clientsmariem()
{

}
