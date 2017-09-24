#include "GameScene.h"
#include <ui/CocosGUI.h>
#include "Objects/Player.h"
USING_NS_CC;


bool GameScene::init()
{
	const double _dScale = 1.0;

	this->initWithPhysics();
	this->getPhysicsWorld()->setGravity(Vec2(0, -98));

	m_pcTerrain = TMXTiledMap::create("data/map/2DGameMap.tmx");
	this->addChild(m_pcTerrain);

	auto _pColliders = m_pcTerrain->getObjectGroup("collider");
	for (auto _pCo : _pColliders->getObjects()) {
		auto _pMap = _pCo.asValueMap();
		double _dWidth = _pMap["width"].asDouble();
		double _dHeight = _pMap["height"].asDouble();
		double _dX = _pMap["x"].asDouble();
		double _dY = _pMap["y"].asDouble();

		PhysicsBody* _pPhy = PhysicsBody::createBox(Size(_dWidth*_dScale, _dHeight*_dScale));
		_pPhy->setDynamic(false);
		Sprite *_pSprite = Sprite::create();
		_pSprite->setPosition(Vec2(_dX, _dY));
		_pSprite->setAnchorPoint(Vec2::ZERO);
		_pSprite->setContentSize(Size(_dWidth, _dHeight));
		_pSprite->setPhysicsBody(_pPhy);

		m_pcTerrain->addChild(_pSprite);
	}
	auto _pMapObjects = m_pcTerrain->getObjectGroup("GameObjects");
	auto _pSpawn = _pMapObjects->getObject("StartingPoint");

	m_pcPlayer = Player::create("res/brick.png");
	m_pcPlayer->setPosition(Vec2(_pSpawn["x"].asDouble(), _pSpawn["y"].asDouble()));
	PhysicsBody* _pPhy = PhysicsBody::createBox(m_pcPlayer->getContentSize()*_dScale);
	_pPhy->setRotationEnable(false);
	_pPhy->setDynamic(true);
	m_pcPlayer->setPhysicsBody(_pPhy);
	m_pcTerrain->addChild(m_pcPlayer);

	this->setScale(_dScale);

	this->scheduleUpdate();


	//UI
	
	auto button = ui::Button::create();
	button->loadTextureNormal("res/left.png");
	button->loadTexturePressed("res/left_pressed.png");
	button->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType nType) {
		switch (nType)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			m_pcPlayer->m_bMoveLeft = true;
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			m_pcPlayer->m_bMoveLeft = false;
			break;
		default:
			break;
		}
	});
	button->setPosition(Vec2(0, 0));
	button->setOpacity(80);
	button->setAnchorPoint(Vec2::ZERO);
	this->addChild(button, 1);


	button = ui::Button::create();
	button->loadTextureNormal("res/right.png");
	button->loadTexturePressed("res/right_pressed.png");
	button->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType nType) {
		switch (nType)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			m_pcPlayer->m_bMoveRight = true;
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			m_pcPlayer->m_bMoveRight = false;
			break;
		default:
			break;
		}
	});
	button->setPosition(Vec2(button->getContentSize().width, 0));
	button->setOpacity(80);
	button->setAnchorPoint(Vec2::ZERO);

	this->addChild(button,1);

	button = ui::Button::create();
	button->loadTextureNormal("res/jump.png");
	button->loadTexturePressed("res/jump_pressed.png");
	button->addTouchEventListener([&](Ref* pSender, ui::Widget::TouchEventType nType) {
		switch (nType)
		{
		case cocos2d::ui::Widget::TouchEventType::BEGAN:
			m_pcPlayer->jump();
			break;
		case cocos2d::ui::Widget::TouchEventType::MOVED:
			break;
		case cocos2d::ui::Widget::TouchEventType::ENDED:
		case cocos2d::ui::Widget::TouchEventType::CANCELED:
			break;
		default:
			break;
		}
	});
	button->setPosition(Vec2(Director::sharedDirector()->getVisibleSize().width - button->getContentSize().width, 0));
	button->setOpacity(80);
	button->setAnchorPoint(Vec2::ZERO);

	this->addChild(button, 1);

	return true;
}

void GameScene::update(float delta)
{
	auto _vWinSize = Director::sharedDirector()->getVisibleSize();
	Vec2 _vDelta = Vec2(_vWinSize.width / 2, _vWinSize.height / 2);
	m_pcTerrain->setPosition(_vDelta-m_pcPlayer->getPosition());
}
