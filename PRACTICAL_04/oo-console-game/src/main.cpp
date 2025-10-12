#include <iostream>

#include <./include/Player.h>
#include <./include/NPC.h>

using namespace std;

class Game
{
private:
    Player player;
    NPC npc;

    GameObject *winner = nullptr;

public:
    Game(std::string playerName, std::string npcName) : player(playerName), npc(npcName) {}

    void gameloop()
    {
	cout<<"You are an "<<player.getName()<<". Choose your action:"<<endl;

         while (player.getHealth() > 0 && npc.getHealth() > 0)
{
	if(player.getName() == "Orc")
	{
	  int choice = 0;

	  cout<<"1. Sword Slash (Power: 15, Cooldown: 2)\n";
	  cout<<"2. Shield Bash (Power: 25, Cooldwon: 1)\n";
	  cout<<"3. Defensive Stance (Negates next attack, Cooldown: 3)\n:";
	  cin>>choice;
    	  
	if(choice == 1)
		{cout<<"You used Sword Slash!\n";
		player.attack(npc,15);}
	else if(choice == 2)
		{cout<<"You used Shield Bash!\n";
		player.attack(npc,25);}
	else if(choice == 3)
		{cout<<"You used Defensive Stance!\n";}
	}	 


	else if(player.getName() == "Troll")
        {
          int choice = 0;
	  cout<<"1. Ground Stomp Shockwave (Power: 20, Cooldown: 3)\n";
          cout<<"2. Club Smash (Power: 15, Cooldwon: 2)\n";
          cout<<"3. Thick Hide (Negates next attack, Cooldown: 3)\n";
	 cin>>choice;

	if(choice == 1)
                {cout<<"You used Ground Stomp Shockwave!\n";
                 player.attack(npc,20);}
        else if(choice == 2)
                {cout<<"You used Club Smash!\n";
	     	player.attack(npc,15);}
        else if(choice == 3)
                cout<<"You used Thick Hide!\n";  
	
	
}
	 npc.attack(player, 10);

}//end while
	

	
	
        // Main GameLoop
        while (player.getHealth() > 0 && npc.getHealth() > 0)
        {

            // Check for winner
            if (player.getHealth() <= 0)
            {
                winner = &npc;
                break; // End loop if winner is determined
            }
            else if (npc.getHealth() <= 0)
            {
                winner = &player;
                break; // End loop if winner is determined
            }
        }

        // Output the winner
        if (winner)
        {
            std::cout << winner->getName() << " has won the battle!" << std::endl;
        }
    }
};

int main()
{
    //Ask user for input

    int choice = 0;
    std::cout<<"\n";
    std::cout<<"Please choose your character\n";
    std::cout<<"1. Orc\n";
    std::cout<<"2. Troll\n";
    std::cin >> choice;

  std::string m_playerName = ""; 
  std::string m_npcName = "";

   if(choice == 1){
	m_playerName = "Orc";
        m_npcName = "Troll";
   }

   else
	{
  	  m_playerName = "Troll";
	  m_npcName = "Orc";

	}
    Game game(m_playerName, m_npcName);
    game.gameloop();
    cin.get();
}

