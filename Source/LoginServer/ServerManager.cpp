#include "PrecompiledHeader.h"
#include "ServerManager.h"

void ServerManager::RegisterLibrary( Context* context )
{
    context->RegisterSubsystem( new ServerManager( context ) );
}

ServerManager::ServerManager( Context* context ) :
    ManagerImpl( context )
{
    IMPL_MANAGER( UserManager );
}

ServerManager::~ServerManager()
{
    managers.Clear();
}

bool ServerManager::Init()
{
    for( const auto& m : managers )
        m.second_->Init();

    return true;
}

void ServerManager::UnInit()
{
    for( const auto& m : managers )
        m.second_->UnInit();
}