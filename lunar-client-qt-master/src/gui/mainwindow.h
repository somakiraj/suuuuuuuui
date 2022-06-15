//
// Created by nils on 11/4/21.
//

#ifndef LUNAR_CLIENT_QT_MAINWINDOW_H
#define LUNAR_CLIENT_QT_MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QStackedWidget>
#include <QPushButton>
#include <QComboBox>
#include <QStandardPaths>

#include "launch/offlinelauncher.h"
#include "launch/launcher.h"
#include "pages/configurationpage.h"
#include "pages/generalpage.h"
#include "pages/agentspage.h"
#include "config/config.h"

#ifdef INCLUDE_UPDATER
#include "updater/updatechecker.h"
#endif

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    void launch(Launcher& launcher, Launcher::CosmeticsState cosmeticsState);
    void closeEvent(QCloseEvent* closeEvent) override;
    void apply();
    void load();
private slots:
    void resetLaunchButtons();
    void launchUnlockedCosmetics();
    void launchDefault();
    void launchNoCosmetics();
    void errorCallback(const QString& message);

#ifdef INCLUDE_UPDATER
    void updateAvailable(const QString& url);
    void noUpdatesAvailable();
#endif
private:
    QListWidget* pageList;
    QStackedWidget* pageStack;
    QPushButton* launchUnlockedCosmeticsButton;
    QPushButton* launchButton;
    QPushButton* launchNoCosmeticsButton;
    QComboBox* versionSelect;

    QList<ConfigurationPage*> pages;

    OfflineLauncher offlineLauncher;

    Config config;

#ifdef INCLUDE_UPDATER
    UpdateChecker updaterChecker;
#endif
};


#endif //LUNAR_CLIENT_QT_MAINWINDOW_H
