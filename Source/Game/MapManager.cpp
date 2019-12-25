#include "PrecompiledHeader.h"
#include "MapManager.h"

MapManager::MapManager( Context* context ) :
    ManagerImpl( context ),
    maps{}
{
}

MapManager::~MapManager()
{
    maps.Clear();
}

bool MapManager::Init()
{
    BaseMap* map = nullptr;

    //TODO: Load Maps from SQL

    //Ricarten Town
    map = maps[(MAP_ID)MapID::Ricarten] = new BaseMap( context_ );
    map->name = "Ricarten Town";
    map->objectFile = "Objects/s_v2/s_v2.xml";

    //Garden of Freedom
    map = maps[(MAP_ID)MapID::GardenOfFreedom] = new BaseMap( context_ );
    map->name = "Garden of Freedom";
    map->objectFile = "Objects/s_f/s_f_01.xml";

    return true;
}

void MapManager::UnInit()
{
    maps.Clear();
}

bool MapManager::Load( const MapID& mapID )
{
    if( SCREEN_TYPE == ScreenType::World )
    {
        auto it = maps.Find( (MAP_ID)mapID );

        if( it != maps.End() )
            return WORLDSCREEN->GetScene()->InstantiateXML( RESOURCECACHE->GetResource<XMLFile>( it->second_->objectFile )->GetRoot(), it->second_->centerPosition, Quaternion::IDENTITY, LOCAL );
    }

    return false;
}

BaseMap* MapManager::GetMap( const MapID& mapID )
{
    auto it = maps.Find( (MAP_ID)mapID );

    if( it != maps.End() )
        return it->second_;

    return nullptr;
}