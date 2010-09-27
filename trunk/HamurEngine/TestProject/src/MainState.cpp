#include "MainState.h"
#include "GroundObject.h"
#include "DynamicObject.h"




// Calling HamurState("Name") is a must!
MainState::MainState() : HamurState("MainState")
{
    angle1 = 0;

}

MainState::~MainState()
{

}


// ENTER
void MainState::Enter() 
{
    HamurVec2 pos2(480, 150);

    HAMURWORLD->AddObject(new GroundObject("Ground"));
}


// UPDATE
void MainState::Update() 
{
    if(HAMUREVENT->IsKeyPressed(Keyboard::Escape)) 
        HAMURENGINE->Stop();

    if(HAMUREVENT->IsMouseDown(Mouse::MiddleButton)) 
        HAMURCONSOLE << "mouse a basili tuttum \n";

    if(HAMUREVENT->IsMousePressed(Mouse::LeftButton))
        HAMURCONSOLE << "mouse a bastim \n";

    if(HAMUREVENT->IsKeyPressed(Keyboard::KeyW))
        HAMURCONSOLE << "W a bastim";
}


// DRAW
void MainState::Draw() 
{
    
}


// EXIT
void MainState::Exit() 
{

}

void MainState::testBox2D()
{
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);

    // Do we want to let bodies sleep?
    bool doSleep = true;

    // Construct a world object, which will hold and simulate the rigid bodies.
    b2World world(gravity, doSleep);


    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;

    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);

    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    float timeStep = 1.0f / 60.0f;
    int velocityIterations = 6;
    int positionIterations = 2;

    // This is our little game loop.
    for (int i = 0; i < 60; ++i)
    {
        // Instruct the world to perform a single step of simulation.
        // It is generally best to keep the time step and iterations fixed.
        world.Step(timeStep, velocityIterations, positionIterations);

        // Clear applied body forces. We didn't apply any forces, but you
        // should know about this function.
        world.ClearForces();

        // Now print the position and angle of the body.
        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle();

        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
}

void MainState::testPlotter()
{
    HamurPlotter::DrawSolidRectangle(100, 100, 50, 50, HamurColor::RED);

    HamurPlotter::DrawSolidRectangle(400, 400, 10, 80, HamurColor::GREEN);


    HamurVec3 vecs[6] = {HamurVec3(300,10,50), HamurVec3(100,250,50), HamurVec3(300,450,50),
        HamurVec3(450, 450,50), HamurVec3(600,250,50), HamurVec3(450, 10,50)};

    HamurPlotter::DrawPolygon(vecs, 6, HamurColor::CYAN,180);

    HamurPlotter::DrawRectangle(225, 100, 280, 275, HamurColor::RED);

    HamurPlotter::DrawCircle(365, 237, 136, HamurColor::MAGENTA);

    HamurPlotter::DrawSolidCircle(365, 237, 50, HamurColor::YELLOW);


    for ( int i =0; i< 40; i++)
    {
        HamurPlotter::DrawCircle(400, 300, (i+1)* 8.0f, HamurColor::RED);
    }


    HamurVec2 down1(140, 70);
    HamurVec2 down2(140,350);

    HamurVec3 up1(140, 70, 0);
    HamurVec3 up2(140, 350, 0);

    HamurColor newcolor1(255, 50, 0);
    HamurColor newcolor2 (255, 0, 255);

    HamurVec2 try1(1,1);
    HamurVec3 try2(3,3,0);

    //HamurPlotter::DrawLine(140, 70, 0, 140, 350, 0, HamurColor::WHITE, 90);
    HamurPlotter::DrawLine(down1, down2, HamurColor::WHITE, 90);
    HamurPlotter::DrawLine(up1, up2, HamurColor::YELLOW, 45);
    HamurPlotter::DrawLine(down1, down2, newcolor1);
    HamurPlotter::DrawLine(up1, up2, newcolor2);

    for (int i = 0, k=0; i < 50; i++)
    {
        HamurPlotter::DrawPoint(try1, HamurColor::YELLOW);
        HamurPlotter::DrawPoint(try2, HamurColor::BLUE);
    }
}

void MainState::spawnObjects()
{
    static float x = 0;
    static float y = 0;
    static int i = HAMURWORLD->GetWorldSize()- 1;

    bool spawn = false;


    HamurVec2 pos(x, y);
    HamurString ss;
    //pos.x = 0 + i *30;
    //pos.y = 0 + i *5;

    pos.x = 250.0f;
    pos.y = 0.0f;
    
    x = pos.x;
    y = pos.y;

    ss << "Dynamic" << i;
    HAMURWORLD->AddObject(new DynamicObject(ss.GetString(), pos));
    i = HAMURWORLD->GetWorldSize()-1;
}