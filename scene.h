#ifndef SCENE_H_
#define SCENE_H_

#include <SDL2/SDL.h>
#include <vector>
#include <list>
#include <map>
#include <string>

#include "camera.h"

class Scene {
private:
	std::vector<Sprite*> 			sceneSprites;	//Объекты,которые находяться на сцене
	std::list<Sprite*>				clickedSprites;	//Объекты,которые нажаты.При отпускании мыши - список очищается
	std::list<Sprite*>				hoveredSprites;	//Объекты,на которые наведена мышь.При движении мыши список,возможно обновляеться.

	std::map<std::string,Camera*> 	sceneCameras;	//Камеры,которые находяться на сцене.Хранится
													//в виде Имя Камеры - Значение

public:
	virtual ~Scene()=0;	//НАДО РЕАЛИЗОВАТЬ УДАЛЕНИЕ

	//Обрабатывает события
	virtual void controller(SDL_Event* event);

	//Обновляет игровые данные
	virtual void update(double delta);

	//Рисует на сцене игровые данные
	virtual void draw();

	//Добавляет спрайт на сцену
	void addSprite(Sprite* sprite);

	//Добавляет камеру в словарь
	void addCamera(std::string name,Camera* camera);

	//Удаляет камеру из словаря
	void removeCamera(std::string name);

};



#include "sprite.h"
#include <SDL2/SDL_ttf.h>
//НИЖЕ ТЕСТ,МОЖНО УДАЛЯТЬ
class TestScene : public Scene {
private:
	int direction;
	Sprite* animatedSprite;
	Label label;
	Animation animations[4];
	float timer;

	Camera* camera;

public:
	TestScene();
	~TestScene();

	void controller(SDL_Event* event);
	void update(double delta);
	void draw();
};

#endif