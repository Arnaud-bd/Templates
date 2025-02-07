#include "PlayerBehaviour.h"
#include "../Components/Collider.h"
#include "../Components/SpriteRender.h"
#include "../GameComponents/BrickBehaviour.h"

PlayerBehaviour::PlayerBehaviour()
{
}

void PlayerBehaviour::Update(float _deltaTime)
{
    sf::RenderWindow* window = GameManager::GetInstance()->GetWindow();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_transform->getPosition().x < window->getSize().x - 52.f)
    {
        m_transform->setPosition(m_transform->getPosition().x + 550 * 1 * _deltaTime, m_transform->getPosition().y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_transform->getPosition().x > 52.f)
    {
        m_transform->setPosition(m_transform->getPosition().x + 550 * -1 * _deltaTime, m_transform->getPosition().y);
    }

    if (GameManager::GetInstance()->GetSceneManager()->GetCurrentScene()->GetAll<BrickBehaviour>().size() <= 0)
    {
        GameManager::GetInstance()->m_GameState = GameManager::GAMESTATE::WIN;
    }
}

void PlayerBehaviour::Awake()
{
    SpriteRender* s = Add<SpriteRender>();
    s->Init("..\\..\\..\\res\\Sprite\\paddleBlu.png");
    s->Start();
    Collider* c = Add<Collider>();
    c->Start();
    c->AddHitbox({-58.5f, 0}, 19.f);
    c->AddHitbox({-19.5f, 0}, 19.f);
    c->AddHitbox({ 19.5f, 0}, 19.f);
    c->AddHitbox({ 58.5f, 0}, 19.f);
}

void PlayerBehaviour::Start()
{
    m_transform = Get<Transform2D>();
}

void PlayerBehaviour::OnCollideEnter(Collider* _other)
{

}

void PlayerBehaviour::Reset()
{
    m_transform->setPosition(860.f, 950.f);
}
