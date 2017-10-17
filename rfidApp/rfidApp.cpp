#include "rfidApp.h"

#include <qmessagebox.h>

rfidApp::rfidApp(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	textBox = new QTextEdit();
	setCentralWidget(textBox);

	connect(ui.actionConnect, &QAction::triggered, this, &rfidApp::connectToReader);
	connect(ui.actionDisconnect, &QAction::triggered, this, &rfidApp::disconnectFromReader);
	
	ui.actionDisconnect->setEnabled(false);
	
}

void rfidApp::connectToReader()
{
	ui.actionDisconnect->setEnabled(true);
	ui.actionConnect->setEnabled(false);
	readTagsThread = new readerThread();
	connect(ui.menuScan, &QMenu::aboutToShow, readTagsThread, &readerThread::checkForTags);
	connect(readTagsThread, &readerThread::gotATag, this, &rfidApp::caughtATag);
	connect(this, &rfidApp::tagReadDone, readTagsThread, &readerThread::freeTags);
	readTagsThread->start();
	
}

void rfidApp::disconnectFromReader()
{
	ui.actionDisconnect->setEnabled(false);
	ui.actionConnect->setEnabled(true);
	readTagsThread->terminate();
	delete readTagsThread;
}

void rfidApp::caughtATag(LPSKYETEK_TAG * tags, unsigned short count)
{
	QString toPut = "";


	for (int i = 0; i < count; i++)
	{
		TCHAR * convert = tags[i]->friendly;

		for (int i = 0; convert[i] != '\0'; i++)
		{
			toPut.append((LPSTR)(convert + i));
		}

		textBox->append("Tag\n");
		textBox->append("---\n");
		textBox->insertPlainText(toPut);
		textBox->append("\n");
		toPut = "";
	}
	emit tagReadDone();
	
}
