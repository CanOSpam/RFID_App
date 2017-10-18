/*------------------------------------------------------------------------------------------------------------------
-- SOURCE FILE: rfidApp.cpp - An application that can open and close a connected RFID reader, and check for, and read
-- tags that are in range.
--
-- PROGRAM: RFID Reader App
--
-- FUNCTIONS:
--	void connectToReader
--	void disconnectFromReader
--	void caughtATag(LPSKYETEK_TAG * tags, unsigned short count)
--
-- QT Signals:
--	tagReadDone();
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
--	This program is capable of opening a connection to an RFID reader that is plugged in, once the reader is connected
--	to, the user can check to see if there are any tags in range, or disconnect from the reader.
----------------------------------------------------------------------------------------------------------------------*/

#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_rfidApp.h"

#include "readerThread.h"
#include <qtextedit.h>

#include <stapi\SkyeTekAPI.h>
#include <stapi\SkyeTekProtocol.h>

class rfidApp : public QMainWindow
{
	Q_OBJECT

public:
	rfidApp(QWidget *parent = nullptr);
	
	

private:
	Ui::rfidAppClass ui;
	readerThread* readTagsThread;
	QTextEdit* textBox;

signals:
	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: tagReadDone
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void tagReadDone()
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This is a signal that is emitted when all tags have been read from the readerThread. This signal is emitted so that
	-- readerThread can safely free the tags in its memory without causing issues with reading them.
	----------------------------------------------------------------------------------------------------------------------*/
	void tagReadDone();

public slots:
	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: connectToReader
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void connectToReader()
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This function starts the readerThread, which then connects to the reader and then connects all the \
	-- appropriate signals to it. It also changes the menu actions to grey out connect, and enable disconnect. 
	----------------------------------------------------------------------------------------------------------------------*/
	void connectToReader();

	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: disconnectFromReader
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void disconnectFromReader()
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This function terminates the readerThread which disconnects from the reader.
	----------------------------------------------------------------------------------------------------------------------*/
	void disconnectFromReader();

	/*------------------------------------------------------------------------------------------------------------------
	-- FUNCTION: caughtATag
	-- DATE: October 17th, 2017
	-- REVISIONS: None
	-- DESIGNER: Tim Bruecker, JC Tee
	-- PROGRAMMER: Tim Bruecker, JC Tee
	--
	-- INTERFACE: void caughtATag(LPSKYETEK_TAG* tags, unsigned short numTags)
	--	tags: pointer to the array of tags
	--	numTags: number of tags in the array
	--
	-- RETURNS: void
	--
	-- NOTES:
	-- This function is connected to the gotATag signal that is emitted from the readerThread. It uses the array of tags
	-- that are passed to it by gotATag and prints them to the text window. numTags is the number of tags that were found.
	----------------------------------------------------------------------------------------------------------------------*/
	void caughtATag(LPSKYETEK_TAG* tags, unsigned short numTags);

};
