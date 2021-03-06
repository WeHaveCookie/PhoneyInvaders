#include "stdafx.h"
#include "CommandSound.h"
#include "Entity/Entity.h"
#include "Manager/Sound/SoundMgr.h"

void CommandSound::init(Entity* ent, void* data)
{
	Command::init(ent);
	m_soundID = SoundMgr::getSingleton()->addSound((char*)data, false, true);
	Command::initDone();
}

bool CommandSound::execute()
{
	SoundMgr::getSingleton()->getSound(m_soundID)->play();
	return true;
}

void CommandSound::undo()
{
}

void* CommandSound::makeCopy()
{
	return (void*)new CommandSound();
}