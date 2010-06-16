// main_window.h

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "base/user_types.h"

#include <QMainWindow>
#include <QIcon>

class QAction;
class QComboBox;
class QMenu;
class QLabel;

namespace BioSig_
{

// main window
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow ();
    virtual ~MainWindow () {};

    void setStatusBarSignalLength(float64 length);
    void setStatusBarNrChannels(int32 nr_channels);

    void setRecentFiles(const QStringList& recent_file_list);

signals:
    void recentFileActivated(QAction* recent_file_action);
    void recentFileMenuAboutToShow();


protected:
    virtual void closeEvent(QCloseEvent* close_event);
    virtual void dropEvent (QDropEvent* event);
    virtual void dragEnterEvent(QDragEnterEvent *event);
    virtual void resizeEvent (QResizeEvent* event);
private slots:
    void toggleStatusBar (bool visible);
    void toggleAllToolbars ();

private:
    QAction* action (QString const& action_id);

    MainWindow(const MainWindow&);
    const MainWindow& operator=(const MainWindow&);

    void initActions();
    void initToolBars();
    void initMenus();
    void initStatusBar();

    QMenu* file_menu_;
    QMenu* file_recent_files_menu_;
    QMenu* edit_menu_;
    QMenu* mouse_mode_menu_;
    QMenu* view_menu_;
    QMenu* view_toolbar_views_menu_;
    QMenu* tools_menu_;
    QMenu* help_menu_;

    QToolBar* file_toolbar_;
    QToolBar* mouse_mode_toolbar_;
    QToolBar* view_toolbar_;

    QLabel* status_bar_signal_length_label_;
    QLabel* status_bar_nr_channels_label_;

    QAction* toggle_all_toolbars_;
};

} // namespace BioSig_

#endif
