#include <QApplication>

#include "Views/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Model model;
    auto viewModel = std::make_unique<MainWindowViewModel>(&model);
    MainWindow w(std::move(viewModel));
    w.show();
    return a.exec();
}
