#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ViewModels/mainwindowviewmodel.h"
#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::unique_ptr<MainWindowViewModel> viewModel, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<MainWindowViewModel> viewModel_;
};
#endif // MAINWINDOW_H
