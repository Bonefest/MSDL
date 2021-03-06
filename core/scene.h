#ifndef SCENE_H_
#define SCENE_H_

#include <SDL2/SDL.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <SDL2/SDL_ttf.h>

#include "camera.h"
#include "sprite.h"
#include "collision_manager.h"

namespace MSDL {

	class Scene {
	private:
		std::list<Sprite*>			UILayer;		//Список объектов пользовательского интерфейса
		std::list<Sprite*> 			sceneSprites;	//Объекты,которые находяться на сцене
		std::map<std::string,Camera*> 	sceneCameras;	//Камеры,которые находяться на сцене.Хранится
														//в виде Имя Камеры - Значение
		
		CollisionManager 			collisionManager;	//Менеджер для обработки коллизий
	public:
		virtual ~Scene();	//НАДО РЕАЛИЗОВАТЬ УДАЛЕНИЕ(Сцена не должна удалять указатели самостоятельно)

		//Обрабатывает события
		virtual void controller(SDL_Event* event);

		//Обновляет игровые данные
		virtual void update(double delta);

		//Рисует на сцене игровые данные
		virtual void draw();

		//Добавляет спрайт на сцену с прямым порядком отрисовки и в коллизионный менеджер
		void addSprite(Sprite* sprite,long collisionLevel=CollisionManager::DEFAULT_LEVEL_COLLISION);

		//Удаляет спрайт из сцены и коллизионного менеджера
		void removeSprite(Sprite* sprite,long collisionLevel=CollisionManager::DEFAULT_LEVEL_COLLISION);

		//Добавляет спрайт на сцену с Z-порядком отрисовки и в коллизионный менеджер
		void addSpriteWithZOrder(Sprite* sprite,long z_position=0,long collisionLevel=CollisionManager::DEFAULT_LEVEL_COLLISION);

		//Добавляет спрайт на слой пользовательского интерфейса
		void addUIElement(Sprite* sprite);

		//Удаляет объект с пользовательского интерфейса
		void removeUIElement(Sprite* sprite);


		//Добавляет камеру в словарь
		void addCamera(std::string name,Camera* camera);

		//Удаляет камеру из словаря
		void removeCamera(std::string name);


		//WARNING!
		CollisionManager* getCollisionManager() { return &collisionManager; }

	};

}
#endif
