/*
 * Copyright (c) 2016 Vincent Lee. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include "mainwindow.h"
#include "chartdatasource.h"
#include "chartview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(480, 300);
    setWindowTitle("Demo: Qt WebChannel");

    ChartView *chartView = new ChartView();
    QWebEngineView *webEngineView = new QWebEngineView();
    webEngineView->setPage(chartView);

    QPushButton *regenerateButton = new QPushButton("Regenerate");

    QWidget *centralWidget = new QWidget();
    QVBoxLayout *vbox = new QVBoxLayout(centralWidget);
    vbox->addWidget(webEngineView);
    vbox->addWidget(regenerateButton);

    setCentralWidget(centralWidget);

    QWebChannel *webChannel = new QWebChannel(this);
    chartView->setWebChannel(webChannel);

    // Objects must be registered before any client is initialized
    ChartDataSource *dataSource = new ChartDataSource(this);
    webChannel->registerObject(QStringLiteral("dataSource"), dataSource);
    connect(regenerateButton, SIGNAL(clicked()), dataSource, SLOT(generateRandomData()));
}
