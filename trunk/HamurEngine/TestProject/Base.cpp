#include "Base.h"
#include "ToothPasteBullet.h"
#include "IngameState.h"
#include "Bacteria.h"

//#include <cstdlib> 
//#include <ctime> 
#include <iostream>
using namespace std;

Base::Base(const string &name):HamurObject(name), killedEnemyCount(0)
{
	update = true;

	// Don't know at the moment, we'll have to try width & height
    mWidth = 20;
    mHeight = 20;

	mPos.x = HamurOpenGL::GetInstance()->GetScreenWidth() / 2 - mWidth / 2; 
	mPos.y = HamurOpenGL::GetInstance()->GetScreenHeight() / 2 - mHeight / 2;
	mPos.z = 0;

    //setPhysics();
}

/* Not using it at the moment...

void Base::setPhysics()
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set((mPos.x + mWidth / 2) / 100.0f, (mPos.y + mHeight /2) / 100.0f);
    groundBodyDef.userData = this;
    SetBodyDef(groundBodyDef);
        
   // b2Vec2 _center(3.5f, 0.25f);

    mBox.SetAsBox(mWidth / 200.0f, mHeight / 200.0f);
    //setShape(mBox);
   
    b2Vec2 vertices[4];
    vertices[0].Set(0.0f, height / 100.0f);
    vertices[1].Set(width / 100.0f, height / 100.0f);
    vertices[2].Set(width / 100.0f, 0.0f);
    vertices[3].Set(0.0f, 0.0f);

    int vertexCount = 4;

    b2PolygonShape groundBox;
    groundBox.Set(vertices, 4);
    setShape(groundBox);
    

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &mBox;
    SetFixDef(fixtureDef);

    mBody = HAMURWORLD->Getb2World()->CreateBody(&mBodyDef);
    mBody->CreateFixture(&fixtureDef);
}
*/

void Base::Draw(float deltaTime)
{
    /*
    HAMURCONSOLE << "Vertice1: " << mBox.GetVertex(0).x << "," << mBox.GetVertex(0).y << "\n"
        << "Vertice2: " << mBox.GetVertex(1).x << "," << mBox.GetVertex(1).y << "\n"
        << "Vertice3: " << mBox.GetVertex(2).x << "," << mBox.GetVertex(2).y << "\n"
        << "Vertice4: " << mBox.GetVertex(3).x << "," << mBox.GetVertex(3).y << "\n\n\n";

    HAMURCONSOLE << "POS: " << pos << "\n";
    */
    //HamurVec3 temp(body->GetPosition().x, body->GetPosition().y, 0.0f);
    //HAMURCONSOLE << "BODY POS: " << temp << "\n";

	// Draw a grey rectangle 
    HamurPlotter::DrawSolidRectangle(mPos, mWidth, mHeight, HamurColor::GREY);
}

void Base::Update(float deltaTime)
{
	//There is no movement for the base...
	//if(update)
	//{
	//	hamur::HamurString str;
	//	str << (int)state->GetActiveObjList()->size();
	//	if(enemies.size() > 0 && enemies[killedEnemyCount]->IsActive())
	//	{
	//		Bullet *b = new ToothPasteBullet(str.GetString(), mPos, 
	//			enemies[killedEnemyCount]->GetPosition(), 1);
	//		//state->GetActiveObjList()->push_front(b);
	//	}

	//	if(killedEnemyCount == enemies.size())
	//		update = false;
	//}


}

void Base::Fire(const HamurVec3 &targetPos)
{
	Bullet *b = new ToothPasteBullet("ToothPasteBullet", mPos, 
		targetPos, 1);
}