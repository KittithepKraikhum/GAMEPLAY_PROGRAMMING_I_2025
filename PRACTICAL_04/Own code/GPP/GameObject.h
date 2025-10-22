#include <string>

//Base class
class GameObject
{
	//Member variable
protected:
	std::string name;
	int health;

public:
	//Constructor to initialize health (default is set t0 100)
	GameObject(std::string t_name = "PlayerUnknown", int t_health = 100) :
		name(t_name),
		health(t_health) {}

	int  getHealth() const
	{
		return health;
	}

	std::string getName() const
	{
		return name;
	}

	//Pure virtual function. This function must be implemented by derived classes 
	virtual void attack(GameObject&, int t_damage) = 0;

	//Virtual method for defence. This can be overriden by derived classes if needed
	virtual void defend()
	{
		//Complete
	}

	//instance method takeDamage
	void takeDamage(int)
	{

	}


};