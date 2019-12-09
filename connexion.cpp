#include "connexion.h"

class connexionData : public QSharedData
{
public:

};

connexion::connexion() : data(new connexionData)
{

}

connexion::connexion(const connexion &rhs) : data(rhs.data)
{

}

connexion &connexion::operator=(const connexion &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

connexion::~connexion()
{

}
