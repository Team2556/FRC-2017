#ifndef Shooting_H
#define Shooting_H

#include "CommandBase.h"

class Shooting : public CommandBase {
public:
	Shooting(float timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Shooting_H
