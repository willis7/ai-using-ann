#include "Track.h"

Track::Track(void)
{
	model.loadModel("Asset/Track.obj");
}

Track::~Track(void)
{
}

void Track::update()
{
	model.draw();
}
