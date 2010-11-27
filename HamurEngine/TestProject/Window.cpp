#include "Window.h"

Window::Window(const string &name):GUIElement(name)
{

}

Window::Window(const string &name, const HamurVec3 &position, const int width, const int height): 
		GUIElement(name, position, "", width, height)
{
	HamurVec3 c;
	c.x = HamurOpenGL::GetInstance()->GetScreenWidth()/2;
	c.y = HamurOpenGL::GetInstance()->GetScreenHeight()/2;
	string root = "Graphics/Window/";

	windowPanel = new Panel (name + "Panel", c, root + "windowPanel.png", 400, 300);
	c.x = mPos.x + mWidth/2 - 75; c.y = mPos.y - mHeight/2 + 60; c.z = 1.0;
	closeButton = new Button (name + "CloseButton", c, root + "closeWindow.png", 30, 20);
	//okButton = NULL; cancelButton = NULL;
	messageText = NULL;
	windowTitle = NULL;
}

void Window::Update(float deltaTime)
{
}

void Window::Draw(float deltaTime)
{
	windowPanel->Draw(deltaTime);
	closeButton->Draw(deltaTime);
	windowTitle->Draw(deltaTime);
	//messageText->SetVisible(visible);

	list<Button*>::iterator it;
	for(it = extraButtons.begin(); it != extraButtons.end(); it++)
	{
		(*it)->Draw(deltaTime);	
	}
}

void Window::SetVisible(bool visible)
{
	cout << "POR AQUI PASABA" << visible << endl;
	windowPanel->SetVisible(visible);
	closeButton->SetVisible(visible);
	windowTitle->SetVisible(visible);
	//messageText->SetVisible(visible);

	list<Button*>::iterator it;
	for(it = extraButtons.begin(); it != extraButtons.end(); it++)
	{
		(*it)->SetVisible(visible);
	}
}


void Window::SetTitle(string title)
{
	HamurVec3 c;
	c.x = this->mPos.x;
	c.y = this->mPos.y - this->mHeight/2 + 70;
	windowTitle = new Text(this->GetName() + "title", title, "Fonts/LambadaDexter.ttf", 20, c, HamurColorRGB::BLACK);
}

void Window::SetText(string text)
{
}

void Window::AddButton(Button *button)
{
	HamurVec3 c;
	int nB = extraButtons.size() + 1;

	c.x = this->mPos.x;
	c.y = this->mPos.y - this->mHeight/2 + 120;
	c.y += nB*30;
	button->SetPosition(c);

	extraButtons.push_back(button);
}

void Window::DeleteWindow()
{
	HAMURWORLD->DeleteObject(windowPanel->GetName());
	HAMURWORLD->DeleteObject(closeButton->GetName());
	HAMURWORLD->DeleteObject(windowTitle->GetName());
	
	list<Button*>::iterator it;
	for (it = extraButtons.begin(); it != extraButtons.end(); it++)
	{
		HAMURWORLD->DeleteObject((*it)->GetName());
	}
}