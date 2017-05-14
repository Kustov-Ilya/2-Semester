#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"TObject.h"
#include"TMoveSprites.h"
#include"TPacMan.h"
#include"TWall.h"
#include"TFood.h"
#include"TMonsters.h"
#include"TPills.h"
#include"TPill1.h"
#include"TScopedPtrObj.h"
#include"GameOver.h"
#include<vector>


class HelloWorld : public cocos2d::Scene
{
private:
	TScopedPtrObj Pacman;
	TScopedPtrObj Wall;
	TScopedPtrObj Food;
	TScopedPtrObj Monsters;
	TScopedPtrObj Pills;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

	friend void Movement(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event * event);

	friend bool isClash(TObject *rhs, size_t napr);

	friend void isEat(size_t napr);

	friend bool isfight();

	friend void isPill(size_t napr);

	friend void Remov(std::vector<TObject*>::iterator &rhs);

	friend bool RemFight(std::vector<TObject*>::iterator &it);

	void Update(float dt);

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__

