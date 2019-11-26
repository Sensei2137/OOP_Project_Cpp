#ifndef PROGRAMISTA_H
#define PROGRAMISTA_H

#include "czlowiek.h"

class programista : public czlowiek
{

	protected: string imiee, nazwiskoo;
	public: 
	
	virtual void przedstaw();
};

#endif
