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
	void tagReadDone();

public slots:
	void connectToReader();
	void disconnectFromReader();
	void caughtATag(LPSKYETEK_TAG* tags, unsigned short numTags);

};
