#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

HelloWorld * GL_SC = nullptr;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}


// on "init" you need to initialize your instance
bool HelloWorld::init()
{

    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	GL_SC = this;

	std::string sMap1 = "1111111111111111111111111111111111111111"
						"1000000000000000000011111111100000000001"
						"1010111111111111110011111111101111111101"
						"1010000000000000010000000000000000001101"
						"1010111111101111010111111111111111101101"
						"1000000000000000000011111111111000001101"
						"1111111111111111101010000000000011101101"
						"1000000011111110000010111111111000101101"
						"1011111000000000111100111111111110101101"
						"1000111011111101111101111000000004000001"
						"1110111000500001000001111011111111111111"
						"1110111111111100011111111000000005000001"
						"1110004111111111000111110011011101111101"
						"1000110111000000010000000111011000000101"
						"1010000000011111111111110111011011110101"
						"1011111111110000000011100000000000000001"
						"1011111111110111111011101111111111011111"
						"1011100001110011100000100000111111000001"
						"1000001101111011001113111110111111111101"
						"1011100101110010011110111110000000011101"
						"1001110000006000111110000000111111011101"
						"1101100101111110111110111110000000011101"
						"1101101100111100000000001110111111111101"
						"1001001110011001110110100010110001000001"
						"1011011111001011100110111000000101011111"
						"1011000001101011001104100011110101001111"
						"1011111101100000011101001100000001101111"
						"1011111101110111111101011001111100501111"
						"1000050000000000000001011011111101111111"
						"1011101111110111111111000000111101111111"
						"1400001111110000000000011110000001111111"
						"1111111111111111111111111111111111111111";
	int k = 0;
	for (size_t i=0; i<sMap1.size(); ++i)
	{
		if (sMap1.at(i) == '1')
		{
			TObject *wall;
			wall = new TWall(45 + 10 * (i % 40), 5 + 10 * (i / 40));
			addChild(wall->GetPict(), 3);
			Wall->push_back(wall);
		}
		if (sMap1.at(i) == '0') {
			TObject* food;
			food = new TFood(45 + 10 * (i % 40), 5 + 10 * (i / 40));
			addChild(food->GetPict(), -3);
			Food->push_back(food);
		}
		if (sMap1.at(i) == '3') {
			TObject* pac;
			pac = new TPacMan(45 + 10 * (i % 40), 5 + 10 * (i / 40));
			addChild(pac->GetPict(), 2);
			Pacman->push_back(pac);
		}
		if (sMap1.at(i) == '4') {
			TObject* mons;
			mons = new TMonsters(45 + 10 * (i % 40), 5 + 10 * (i / 40));
			addChild(mons->GetPict(), -1);
			Monsters->push_back(mons);
		}
		if (sMap1.at(i) == '5') {
			TObject* pill;
			pill = new TPill1(45 + 10 * (i % 40), 5 + 10 * (i / 40));
			addChild(pill->GetPict(), -3);
			Food->push_back(pill);
		}
	}

	
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a labe
	
	
	this->schedule(schedule_selector(HelloWorld::Update), 0.3);


	cocos2d::EventListenerKeyboard * listener = cocos2d::EventListenerKeyboard::create();
	listener->onKeyPressed = Movement;

	// never mind about the string bellow 
	this->scheduleUpdate();

	// never mind about the string bellow 
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
   
    return true;
}

void Movement(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event)
{
	if (GL_SC == nullptr)
		return;
	if (GL_SC->Pacman.Get()->empty()) return;
	TObject *pac = GL_SC->Pacman.Get()->at(0);
	float XPac = pac->GetCoord().first;
	float YPac = pac->GetCoord().second;
	if(isfight()) return;
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_D)
	{
		//3==right
		if (isClash(pac, 3)) return;
		isEat(3);
		pac->MRight();
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_W)
	{
		//1==up
		if (isClash(pac, 1)) return;
		isEat(1);
		pac->MUp();
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_A)
	{
		//4==left
		if (isClash(pac, 4)) return;
		isEat(4);
		pac->MLeft();
	}
	if (code == cocos2d::EventKeyboard::KeyCode::KEY_S)
	{
		//2==down
		if (isClash(pac, 2)) return;
		isEat(2);
		pac->MDown();
	}

}

bool isClash(TObject *rhs, size_t napr)
{
	
	//1==up
	//2==down
	//3==right
	//4==left
	float pozX = rhs->GetCoord().first;
	float pozY = rhs->GetCoord().second;
	for (auto it = GL_SC->Wall.Get()->begin(); it != GL_SC->Wall.Get()->end(); ++it) {
		float WallPozYU = (*it)->GetCoord().second + (*it)->GetSize().second;
		float WallPozYD = (*it)->GetCoord().second - (*it)->GetSize().second;
		float WallPozXR = (*it)->GetCoord().first + (*it)->GetSize().first;
		float WallPozXL = (*it)->GetCoord().first - (*it)->GetSize().first;
		switch (napr) {
		case 1:
			if (pozY + rhs->GetSize().second == WallPozYD&&pozX <= WallPozXR&&pozX >= WallPozXL) {
				return true;
			}
			break;
		case 2:
			if (pozY - rhs->GetSize().second == WallPozYU&&pozX <= WallPozXR&&pozX >= WallPozXL) {
				return true;
			}
			break;
		case 3:
			if (pozX + rhs->GetSize().first == WallPozXL&&pozY <= WallPozYU&&pozY >= WallPozYD) {
				return true;
			}
			break;
		case 4:
			if (pozX - rhs->GetSize().first == WallPozXR&&pozY <= WallPozYU&&pozY >= WallPozYD) {
				return true;
			}
			break;
		}
	}
	return false;
}

void isEat(size_t napr)
{
	//1==up
	//2==down
	//3==right
	//4==left
	TObject *pac = GL_SC->Pacman.Get()->at(0);
	float pozX = pac->GetCoord().first;
	float pozY = pac->GetCoord().second;
	for (auto it = GL_SC->Food.Get()->begin(); it != GL_SC->Food.Get()->end(); ++it) {
		float FoodPozYU = (*it)->GetCoord().second + (*it)->GetSize().second;
		float FoodPozYD = (*it)->GetCoord().second - (*it)->GetSize().second;
		float FoodPozXR = (*it)->GetCoord().first + (*it)->GetSize().first;
		float FoodPozXL = (*it)->GetCoord().first - (*it)->GetSize().first;
		switch (napr) {
		case 1:
			if (pozY + pac->GetSize().second == FoodPozYD&&pozX <= FoodPozXR&&pozX >= FoodPozXL) {
				Remov(it);
				return;
			}
			break;
		case 2:
			if (pozY - pac->GetSize().second == FoodPozYU&&pozX <= FoodPozXR&&pozX >= FoodPozXL) {
				Remov(it);
				return;
			}
			break;
		case 3:
			if (pozX + pac->GetSize().first == FoodPozXL&&pozY <= FoodPozYU&&pozY >= FoodPozYD) {
				Remov(it);
				return;
			}
			break;
		case 4:
			if (pozX - pac->GetSize().first == FoodPozXR&&pozY <= FoodPozYU&&pozY >= FoodPozYD) {
				Remov(it);
				return;
			}
			break;
		}
	}
}

bool isfight()
{

	//1==up
	//2==down
	//3==right
	//4==left
	TObject *pac = GL_SC->Pacman.Get()->at(0);
	float pozX = pac->GetCoord().first;
	float pozY = pac->GetCoord().second;
	for (auto it = GL_SC->Monsters.Get()->begin(); it != GL_SC->Monsters.Get()->end(); ++it) {
		float MonPozYU = (*it)->GetCoord().second + (*it)->GetSize().second;
		float MonPozYD = (*it)->GetCoord().second - (*it)->GetSize().second;
		float MonPozXR = (*it)->GetCoord().first + (*it)->GetSize().first;
		float MonPozXL = (*it)->GetCoord().first - (*it)->GetSize().first;

		if (pozY + pac->GetSize().second == MonPozYD&&pozX <= MonPozXR&&pozX >= MonPozXL) {
			return RemFight(it);
		}

		if (pozY - pac->GetSize().second == MonPozYU&&pozX <= MonPozXR&&pozX >= MonPozXL) {
			return RemFight(it);
		}

		if (pozX + pac->GetSize().first == MonPozXL&&pozY <= MonPozYU&&pozY >= MonPozYD) {
			return RemFight(it);
		}
		if (pozX - pac->GetSize().first == MonPozXR&&pozY <= MonPozYU&&pozY >= MonPozYD) {
			return RemFight(it);
		}
	}
	return false;
}


void Remov(std::vector<TObject*>::iterator & it)
{
	if ((*it)->GetType() == 1) {
		TObject* pac = GL_SC->Pacman.Get()->at(0);
		if (pac->GetTimer() != 0) {
			pac->SetTimer(pac->GetTimer() + 30);
		}
		else {
			pac->SetTimer(30);
			pac->ChangeIsHunt();
		}
	}
	GL_SC->removeChild((*it)->GetPict());
	GL_SC->Food.Get()->erase(it);
	
}

bool RemFight(std::vector<TObject*>::iterator & it)
{
	if (GL_SC->Pacman.Get()->at(0)->GetIsHunter() == 1) {
		GL_SC->removeChild((*it)->GetPict());
		GL_SC->Monsters.Get()->erase(it);
		return false;
	}
	else {
		GL_SC->removeChild(GL_SC->Pacman.Get()->at(0)->GetPict());
		GL_SC->Pacman.~TScopedPtrObj();
		return true;
	}
}




void HelloWorld::Update(float dt)
{
	if (GL_SC->Pacman.Get()->empty()|| GL_SC->Food.Get()->empty() || GL_SC->Monsters.Get()->empty()) {
		if (GL_SC->Food.Get()->empty() || GL_SC->Monsters.Get()->empty()) {
			GameOverScene *gameOverScene = GameOverScene::create();
			gameOverScene->getLayer()->getLabel()->setString("You Win!");
			CCDirector::sharedDirector()->replaceScene(gameOverScene);
		}
		else {
			GameOverScene *gameOverScene = GameOverScene::create();
			gameOverScene->getLayer()->getLabel()->setString("You Lose :[");
			CCDirector::sharedDirector()->replaceScene(gameOverScene);
		}
		return;
	}
	if(isfight()) return;
	TObject* pac = GL_SC->Pacman.Get()->at(0);
	if (round(pac->GetTimer()*10)/10. == 0.3) {
		pac->ChangeIsHunt();
		pac->SetTimer(0);
	}
	else if (pac->GetTimer() > 0.3) 
		pac->SetTimer(pac->GetTimer() - 0.3);
	for (auto it = GL_SC->Monsters.Get()->begin(); it != GL_SC->Monsters.Get()->end(); ++it) {
		//1==up
		//2==down
		//3==right
		//4==left
		size_t napr = (*it)->GetDirect();
		switch (napr)
		{
		case 1:
			if (isClash((*it), 1)) {
				if (!isClash((*it), 4)) {
					(*it)->MLeft();
					(*it)->SetDirect(4);
					break;
				}
				else {
					(*it)->MRight();
					(*it)->SetDirect(3);
					break;
				}
			}
			else {
				size_t i = rand() % 2;
				if (i == 0) {
					if (!isClash(*it, 3)) {
						(*it)->MRight();
						(*it)->SetDirect(3);
						break;
					}
				}
				else {
					if (!isClash(*it, 4)) {
						(*it)->MLeft();
						(*it)->SetDirect(4);
						break;
					}
				}
			(*it)->MUp();
			break;
			}
		case 2:
			if (isClash((*it), 2)) {
				if (!isClash((*it), 3)) {
					(*it)->MRight();
					(*it)->SetDirect(3);
					break;
				}
				else {
					(*it)->MLeft();
					(*it)->SetDirect(4);
					break;
				}
			}
			else {
				size_t i = rand() % 2;
				if (i == 0) {
					if (!isClash(*it, 4)) {
						(*it)->MLeft();
						(*it)->SetDirect(4);
						break;
					}
				}
				else {
					if (!isClash(*it, 3)) {
						(*it)->MRight();
						(*it)->SetDirect(3);
						break;
					}
				}
			(*it)->MDown();
			break;
			}
		case 3:
			if (isClash((*it), 3)) {
				if (!isClash((*it), 1)) {
					(*it)->MUp();
					(*it)->SetDirect(1);
					break;
				}
				else {
					(*it)->MDown();
					(*it)->SetDirect(2);
					break;
				}
			}
			else {
				size_t i = rand() % 2;
				if (i == 0) {
					if (!isClash(*it, 1)) {
						(*it)->MUp();
						(*it)->SetDirect(1);
						break;
					}
				}
				else {
					if (!isClash(*it, 2)) {
						(*it)->MDown();
						(*it)->SetDirect(2);
						break;
					}
				}
			(*it)->MRight();
			break;
			}
		case 4:
			if (isClash((*it), 4)) {
				if (!isClash((*it), 2)) {
					(*it)->MDown();
					(*it)->SetDirect(2);
					break;
				}
				else {
					(*it)->MUp();
					(*it)->SetDirect(1);
					break;
				}
			}
			else {
				size_t i = rand() % 2;
				if (i == 0) {
					if (!isClash(*it, 2)) {
						(*it)->MDown();
						(*it)->SetDirect(2);
						break;
					}
				}
				else {
					if (!isClash(*it, 1)) {
						(*it)->MUp();
						(*it)->SetDirect(1);
						break;
					}
				}
			(*it)->MLeft();
			break;
			}
		}
	}
}



void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
    
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/
    
    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
    
    
}
