#include "PrecompiledHeader.h"
#include "UserManager.h"

UserManager::UserManager( Context* context ) : ManagerImpl( context )
{
}

UserManager::~UserManager()
{
}

User* UserManager::GetUser( const String& accountName )
{
    for( auto& userConnection : users )
        if( userConnection.second_->accountName.Compare( accountName, false ) == 0 )
            return userConnection.second_;

    return nullptr;
}

SharedPtr<User> UserManager::AddUser( Connection* connection )
{
    //Doesn't add net connection as user
    if( connection->IsNetConnection() )
        return nullptr;

    auto it = users.Find( connection );

    //We can't hold two instances of user for the same connection
    if( it != users.End() )
        return it->second_;

    //User Added
    SharedPtr<User> newUser( new User( context_ ) );
    newUser->connection = connection;
    users[connection] = newUser;

    return newUser;
}

void UserManager::DelUser( Connection* connection )
{
    auto it = users.Find( connection );

    if( it != users.End() )
        users.Erase( it );
}