#ifndef DriveOntoPeg_H
#define DriveOntoPeg_H

#include "CommandBase.h"

class DriveOntoPeg : public CommandBase {
public:
	DriveOntoPeg();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveOntoPeg_H
