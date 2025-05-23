#pragma once

#define max(X, Y) \
({ __typeof__ (X) _X = (X); \
  __typeof__ (Y) _Y = (Y); \
  _X > _Y ? _X : _Y; })
