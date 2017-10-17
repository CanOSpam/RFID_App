#pragma once
#include <qthread.h>

#include <stapi\SkyeTekAPI.h>
#include <stapi\SkyeTekProtocol.h>

class readerThread : public QThread
{
	Q_OBJECT

public:
	readerThread(QObject* parent = nullptr);
	~readerThread();
	void run();

private:
	LPSKYETEK_DEVICE* mDevices;
	LPSKYETEK_READER* mReaders;
	SKYETEK_STATUS st;
	LPSKYETEK_TAG *lpTags;
	unsigned int mNumOfDevices;
	unsigned int mNumOfReaders;
	unsigned short count;
	bool haveAReader;
	

public slots:
	void checkForTags();
	void freeTags();

signals:
	void gotATag(LPSKYETEK_TAG *tags, unsigned short numTags);

};