#include "IngameState.h"
#include "Teeth.h"

using namespace hamur;

void IngameState::Enter()
{
	playerTeeth = new Teeth("PlayerBase");
}

void IngameState::Update( float deltaTime )
{

}

void IngameState::Draw( float deltaTime )
{

}

void IngameState::Exit()
{

}