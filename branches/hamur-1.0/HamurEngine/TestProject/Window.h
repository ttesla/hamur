#include "GUI.h"
#include "hamur.h"
#include "hamurDefinitions.h"
#include <list>

class Window : public GUIElement
{
	public:
		Window(const string &name);
		Window(const string &name, const HamurVec3 &position, const int width, const int height);
		virtual void Update(float deltaTime);
		virtual void Draw(float deltaTime);
		void SetVisible(bool visible);
		void SetTitle(string title);
		void SetText(string text);
		void AddButton(Button *button);
		void DeleteWindow();

		// Buttons are public to simplify the access
		Button *closeButton;
		//Button *okButton; Button *cancelButton;
		list<Button*> extraButtons;	

	private:
		Text *windowTitle;
		Panel *windowPanel;	
		Text *messageText;

};