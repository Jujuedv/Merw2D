#ifndef _CONTENTMGR_H_
#define _CONTENTMGR_H_

#include "ext_include.h"

class Contentmgr
{
private:
  std::vector<SDL_Texture*> loadedTextures;

  void unloadAll();
public:
  Contentmgr(SDL_Renderer* renderer);
  ~Contentmgr();

  void textureload(SDL_Renderer* renderer);
  SDL_Texture* getTexture(int index);
};

#endif
