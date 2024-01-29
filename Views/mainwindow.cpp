#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(std::unique_ptr<MainWindowViewModel> viewModel, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , viewModel_(std::move(viewModel))
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, viewModel_.get(), &MainWindowViewModel::onClickSlot);


    connect(viewModel_.get(), SIGNAL(valueChangedSignal(int)),
            ui->lcdNumber, SLOT(display(int)));

    connect(viewModel_.get(), SIGNAL(valueChangedSignal(int)),
            ui->progressBar, SLOT(setValue(int)));

    connect(viewModel_.get(), SIGNAL(textChangedSignal(QString)),
            ui->lineEdit, SLOT(setText(QString)));

    connect(viewModel_.get(), SIGNAL(textChangedSignal(QString)),
            ui->textEdit, SLOT(append(QString)));

    connect(ui->clearButton, SIGNAL(clicked()), viewModel_.get(), SLOT(onClearSlot()));

    viewModel_->init();
}


MainWindow::~MainWindow()
{
    delete ui;
}

