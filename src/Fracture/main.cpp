#include "main.h"
#include "Managers/GameManager.h"
int main()
{
	GameManager gameManager;
	gameManager.GetInstance();
	gameManager.Loop();

}
