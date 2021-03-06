#pragma once

class UserHandler : public HandlerImpl
{
    URHO3D_OBJECT( UserHandler, HandlerImpl );
public:
    //! Constructor.
    UserHandler( Context* context );

    //! Deconstructor.
    ~UserHandler();

    //! World Data Handler.
    bool HandleWorldData( Connection* connection, MemoryBuffer& message );

    //! Load User Handler.
    bool HandleLoadUser( Connection* connection, MemoryBuffer& message );
private:
    bool LoadCharacter( User* user, const MapID& mapID, const Vector3& position );
};

