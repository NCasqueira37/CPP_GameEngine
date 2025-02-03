#include "Entity.h"


void Entity::draw(SDL_Renderer* renderer) const {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}