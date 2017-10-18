#include "readerThread.h"

#include <stapi\SkyeTekAPI.h>
#include <stapi\SkyeTekProtocol.h>

#include <qdebug.h>

readerThread::readerThread(QObject* parent)
	: QThread(parent)
{
	
}

readerThread::~readerThread()
{
	if (mNumOfDevices != 0)
	{
		SkyeTek_FreeDevices(mDevices, mNumOfDevices);
	}

	if (mNumOfReaders != 0)
	{
		SkyeTek_FreeReaders(mReaders, mNumOfReaders);
	}
		
		
}

void readerThread::run()
{
	mDevices = NULL;
	mReaders = NULL;
	mNumOfDevices = 0;
	mNumOfReaders = 0;
	haveAReader = false;
	count = 0;

	mNumOfDevices = SkyeTek_DiscoverDevices(&mDevices);
	if (mNumOfDevices > 0)
	{
		mNumOfReaders = SkyeTek_DiscoverReaders(mDevices, mNumOfDevices, &mReaders);
		if (mNumOfReaders > 0)
		{
			haveAReader = true;
		}
	}
	else
	{
		qDebug() << endl << "No reader found" << endl;
	}
	
}

void readerThread::freeTags()
{
	if (count > 0)
	{
		SkyeTek_FreeTags(mReaders[0], lpTags, count);
	}
}

void readerThread::checkForTags()
{
	if (haveAReader)
	{
		st = SkyeTek_GetTags(mReaders[0], AUTO_DETECT, &lpTags, &count);
		if (st != SKYETEK_SUCCESS)
		{
			qDebug() << "No tags found" << endl;
			return;
		}
		else
		{
			emit gotATag(lpTags, count);
		}


		count = 0;

	}
}