#pragma once

#include "../Shared/LoginDef.h"

class LoginHandler : public HandlerImpl
{
    URHO3D_OBJECT( LoginHandler, HandlerImpl );
public:
    //! Constructor.
    LoginHandler( Context* context );

    //! Deconstructor.
    ~LoginHandler();

    //! Initialize Object.
    bool Init() override;
private:
    void ProcessLogin( Core::User* user );

    void HandleClientIdentity( StringHash eventType, VariantMap& eventData );
};