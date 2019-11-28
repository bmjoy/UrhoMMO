#pragma once

#include "Screen.h"

#include "LoginScreen.h"
#include "CharacterScreen.h"
#include "TestScreen.h"
#include "WorldScreen.h"

#define ACTIVESCREEN			(SCREENMANAGER->GetActiveScreen())

class ScreenManager : public ManagerImpl
{
    URHO3D_OBJECT( ScreenManager, ManagerImpl );

    enum class FadeStep
    {
        Prepare,
        Out,
        ReleaseScreen,
        CreateScreen,
        In,
        Finished,
    };

public:
    //! Constructor.
    ScreenManager( Context* context );

    //! Deconstructor.
    ~ScreenManager();

    //! Initialize Screen Manager.
    bool Init();

    //! UnInitialize Screen Manager.
    void UnInit();

    //! Handlers.
    void HandleUpdate( StringHash eventType, VariantMap& eventData );

    //! Getters.
    Screen* GetActiveScreen() const{ return activeScreen; }
    const ScreenType& GetActiveScreenType() const{ return activeScreenType; }
    
    //! Setters.
    void SetActiveScreen( const ScreenType& screen );
private:
    //! Scene Handlers.
    void HandleSetLevelQueue( StringHash eventType, VariantMap& eventData );
    void HandleResolutionChange( StringHash eventType, VariantMap& eventData );

    //! Build Window.
    void BuildWindow();
private:
    List<ScreenType> screenQueue;
    SharedPtr<Screen> activeScreen;
    ScreenType activeScreenType;
    SharedPtr<Window> window;

    float fadeTime;
    FadeStep fadeStep;
};