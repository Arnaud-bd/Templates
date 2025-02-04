#include "main.h"
#include "Managers/GameManager.h"
int main()
{
	GameManager* gameManager = GameManager::GetInstance();
	gameManager->Loop();

}
