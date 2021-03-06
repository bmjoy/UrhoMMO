#include "PrecompiledHeader.h"
#include "User.h"

namespace Core
{
User::User( Context* context ) :
    Object( context ),
    connection( nullptr )
{
}

User::~User()
{
    connection = nullptr;
}
}