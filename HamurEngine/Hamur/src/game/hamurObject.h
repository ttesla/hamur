#include "../helper/hamurVec3.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace hamur
{
	/** Handles all game objects */
	class HamurObject
	{
	    public:
		    virtual void update() = 0;
		    virtual void draw() = 0;

		    /** GETTER functions */
		    inline string getName() { return name; }
		    inline HamurVec3 getPosition() { return pos; }
		    inline bool isActive() { return active; }
		    inline bool hasInteraction() { return interaction; }

		    /** SETTER functions */
		    inline void setName(string _name) { name = _name; }
		    inline void setPosition(HamurVec3 _pos) { pos = _pos; }
		    inline void setActive(bool _active) { active = _active; }
		    inline void setInteraction(bool _interaction) { interaction = _interaction; }

	    protected:
		    string name;
		    HamurVec3 pos;
		    bool active;
		    bool interaction;

	    private:
	};
}