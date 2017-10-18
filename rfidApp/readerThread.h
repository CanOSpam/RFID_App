/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: readerThread.cpp - DESCRIPTION HERE
--
-- PROGRAM: RFID Reader App
--
-- FUNCTIONS:
--	void freeTags()
--	void checkForTags()
--
-- QT Signals:
--	void gotATag(LPSKYETEK_TAG *tags, unsigned short numTags);
--
-- DATE: October 17, 2017
--
-- REVISIONS: None
--
-- DESIGNER: Tim Bruecker, JC Tee
--
-- PROGRAMMER: Tim Bruecker, JC Tee
--
-- NOTES:
--	This class is a thread that handles the detecting and reading of RFID tags. It is capable of checking for tags, 
-- and emitting a signal that contains an array of detected tags so that they can be handled in other parts 
-- of the application.
----------------------------------------------------------------------------------------------------------------------*/
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
	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: checkForTags
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void checkForTags()
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This function uses the SkyeTek_GetTags function to find any tags that are within range of the reader. These tags
	-- are then saved in an array, and the gotATag signal is emitted that contains that array so that other parts
	-- of the application can use them. If no tags are found, a debug message is sent to the console.
	----------------------------------------------------------------------------------------------------------------------*/
	void checkForTags();

	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: freeTags
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void freeTags()
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This function frees the tag array if there are any tags stored in it (if count is greater than 0).
	----------------------------------------------------------------------------------------------------------------------*/
	void freeTags();

signals:
	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: gotATag
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void gotATag(LPSKYETEK_TAG *tags, unsigned short numTags)
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This is a signal that is emitted when tags are detected. This signal contains the array of tags that were found.
	-- This lets any other part of the application interact with those tags.
	----------------------------------------------------------------------------------------------------------------------*/
	void gotATag(LPSKYETEK_TAG *tags, unsigned short numTags);

};