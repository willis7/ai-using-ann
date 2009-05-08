#pragma once
#include "Model.h"

class Track
{
private:

	// .obj model 
	Model model;

public:

	Track(void);
	~Track(void);

	void update();
};
